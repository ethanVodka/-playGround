#include <stdio.h>
#include <vcclr.h>
#include "GdsViewer.h"
#include "gdstk.h"

using namespace gdstk;
using namespace gdsreader;
using namespace Geometry;

System::Void GdsViewer::Tb_FilePath_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	if (e->Data->GetDataPresent(DataFormats::FileDrop))
		e->Effect = DragDropEffects::Copy;
	else
		e->Effect = DragDropEffects::None;
}


System::Void GdsViewer::Tb_FilePath_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e)
{
	if (e->Data->GetDataPresent(DataFormats::FileDrop)) {
		array<String^>^ files = (array<String^>^)e->Data->GetData(DataFormats::FileDrop);
		if (files->Length > 0)
			this->Tb_FilePath->Text = files[0];
	}
}


System::Void GdsViewer::Btn_Start_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (Tb_FilePath->Text != String::Empty)
	{
		IntPtr ptr = Marshal::StringToHGlobalAnsi(Tb_FilePath->Text);
		const char* file_path = static_cast<char*>(ptr.ToPointer());
		Marshal::FreeHGlobal(ptr);

		ErrorCode error_code = ErrorCode::NoError;
		Library lib = read_gds(file_path, 0, 1e-2, NULL, &error_code);
		if (error_code != ErrorCode::NoError)
		{
			exit(EXIT_FAILURE);
		}
		else
		{
			List<array<Point>^>^ gds_polygons = gcnew List<array<Point>^>();
			// get all cell in gds file
			gdstk::Array<Cell*> cells = lib.cell_array;
			int scale = 1000;

			for (int64_t i = 0; i < cells.count; i++)
			{
				// get cell's polygons
				gdstk::Array<Polygon*> polygons = cells[i]->polygon_array;
				for (int64_t j = 0; j < polygons.count; j++)
				{
					// get olygon's point array, then add them to list of gds_polygons 
					Polygon* poly = polygons[j];
					array<Point>^ points = gcnew array<Point>(poly->point_array.count);
					for (int p = 0; p < poly->point_array.count; p++)
					{
						points[p] = Point(poly->point_array[p].x * scale, poly->point_array[p].y * scale);
					}
					gds_polygons->Add(points);
				}
			}

			// create closed polygon from closed polygon path
			gds_polygons = Geometry::Clipping::CombinePolygons(gds_polygons);
			List<array<Point>^>^ edges = gcnew List<array<Point>^>();
			List<array<Point>^>^ holes = gcnew List<array<Point>^>();
			Geometry::Clipping::DividePolygons(gds_polygons, holes, edges);
			
			array<Point>^ p__ = Geometry::UPoint::CreatePolygonWithHoles(edges[0], holes);
	
			//// Ç≠ÇËî≤Ç´ìÒÇ¬ÇÃÉ|ÉäÉSÉìê∂ê¨
			////gds_polygons = Geometry::Clipping::CreateClosedPathWithHole(edges[0], holes[0]);
			// path å`ê¨
			//array<Point>^ p = Geometry::Clipping::MakeHolesInPolygon(edges[0], holes);
			//List<Geometry::GdsPolygon^>^ poly_set = Geometry::GdsPolygons::AnalyzePolygons(edges, holes);



			Bitmap^ bmp = gcnew Bitmap(PicBox->Width, PicBox->Height);
			Graphics^ g = Graphics::FromImage(bmp);

			g->FillPolygon(Brushes::Black, p__);

			PicBox->Image = bmp;
			return;
		}
	}
	else
	{


		//return;
	}
}

