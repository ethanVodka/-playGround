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
	try
	{
		if (Tb_FilePath->Text != String::Empty)
		{
			IntPtr ptr = Marshal::StringToHGlobalAnsi(Tb_FilePath->Text);
			const char* file_path = static_cast<char*>(ptr.ToPointer());

			// 最後にメモリを解放する
			Marshal::FreeHGlobal(ptr);

			ErrorCode error_code = ErrorCode::NoError;
			Library lib = read_gds(file_path, 0, 1e-2, NULL, &error_code);
			if (error_code != ErrorCode::NoError)
			{
				exit(EXIT_FAILURE);
			}
			else
			{
				// get all cell in gds file
				gdstk::Array<Cell*> cells = lib.cell_array;

				for (int64_t i = 0; i < cells.count; i++)
				{
					// get cell's polygons
					gdstk::Array<Polygon*> polygons = cells[i]->polygon_array;
					for (int64_t j = 0; j < polygons.count; j++)
					{
						// get olygon's point array, then add them to list of gds_polygons 
						Polygon* poly = polygons[j];
						array<UPoint^>^ points = gcnew array<UPoint^>(poly->point_array.count);
						for (int p = 0; p < poly->point_array.count; p++)
						{
							points[p] = gcnew UPoint(poly->point_array[p].x, poly->point_array[p].y);
						}
						Polygons->Add(points);
					}

					// release resource
					polygons.clear();
				}
				// release resource
				cells.clear();

				DrawPath(Polygons);
			}
		}
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message);
	}
}

System::Void gdsreader::GdsViewer::DrawPath(List<array<UPoint^>^>^ polygons)
{
	Bitmap^ bmp = gcnew Bitmap(PicBox->Width, PicBox->Height);
	Graphics^ g = Graphics::FromImage(bmp);

	for each (array<UPoint^> ^ originalPoints in polygons)
	{
		// スケーリング後のポリゴンの頂点を定義
		array<PointF>^ scaledPoints = gcnew array<PointF>(originalPoints->Length);
		for (int i = 0; i < originalPoints->Length; i++)
		{
			scaledPoints[i].X = (float)((originalPoints[i]->X * SCALE) + LEFT_POSITION);
			scaledPoints[i].Y = (float)((originalPoints[i]->Y * SCALE) + TOP_POSITION);
		}
		Pen^ p = gcnew Pen(Color::Red, 0.1);
		//Brush^ b = gcnew Brush();
		g->DrawPolygon(p, scaledPoints);
		//g->FillPolygon(Brushes::Black, scaledPoints);
	}

	PicBox->Image = bmp;
}

System::Void gdsreader::GdsViewer::Btn_Do_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		// create closed polygon from closed polygon path
		//Polygons = Geometry::Clipping::CombinePolygons(Polygons, 1000.0);

		//List<array<UPoint^>^>^ edges = gcnew List<array<UPoint^>^>();
		//List<array<UPoint^>^>^ holes = gcnew List<array<UPoint^>^>();

		//Geometry::Clipping::DividePolygons(Polygons, holes, edges, 1000.0);

		List<array<UPoint^>^>^ paths = gcnew List<array<UPoint^>^>();


		array<UPoint^>^ outer = gcnew array<UPoint^>(5)
		{
			gcnew UPoint(0, 0),
				gcnew UPoint(50, 0),
				gcnew UPoint(50, 50),
				gcnew UPoint(0, 50),
				gcnew UPoint(0, 0)  // 起点に戻ることでポリゴンを閉じる
		};

		// Create list of holes
		List<array<UPoint^>^>^ holes = gcnew List<array<UPoint^>^>();

		// Define hole 1
		array<UPoint^>^ hole1 = gcnew array<UPoint^>(5)
		{
			gcnew UPoint(10, 10),
				gcnew UPoint(20, 10),
				gcnew UPoint(20, 20),
				gcnew UPoint(10, 20),
				gcnew UPoint(10, 10)  // ホール1を閉じる
		};

		// Define hole 2
		array<UPoint^>^ hole2 = gcnew array<UPoint^>(5)
		{
			gcnew UPoint(30, 30),
				gcnew UPoint(40, 30),
				gcnew UPoint(40, 40),
				gcnew UPoint(30, 40),
				gcnew UPoint(30, 30)  // ホール2を閉じる
		};

		// Add holes to the list
		holes->Add(hole1);
		holes->Add(hole2);



		paths->Add(Geometry::UPoint::CreatePathWithMultipleHoles(outer, holes));

		DrawPath(paths);

		return;
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message);
	}

}

