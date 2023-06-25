#include <stdio.h>
#include <vcclr.h>
#include "GdsViewer.h"
#include "gdstk.h"

using namespace gdstk;
using namespace gdsreader;

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
			gdstk::Set<gdstk::Tag> tags{};
			lib.get_shape_tags(tags);
			for (int64_t t = 0; t < tags.count; t++)
			{
				// Tag
				gdstk::Tag tag = tags.items[t].value;
				// Polygon
				gdstk::Array<Polygon*> poly{};

				for (int64_t i = 0; i < lib.cell_array.count; i++)
				{
					// Cell
					Cell* cell = lib.cell_array[i];
					cell->get_polygons(true, true, 1, true, tag, poly);
				}

				if (poly.count != 0)
				{
					Cob_SelectLayer->Items->Add(get_layer(tag));
					GetPolygon(poly, tag);
				}
			}
			// 描画処理
			DrawPolygon(GdsPolygons[DisplayLayer]->plygons_list, SCALE);
		}
	}
	else
	{
		CreateGdsFile();
	}
}
System::Void GdsViewer::DrawPolygon(List<List<GPoint^>^>^ poly_list, double scale_factor)
{
	Bitmap^ bmp = gcnew Bitmap(PicBox->Width, PicBox->Height);
	Graphics^ g = Graphics::FromImage(bmp);

	for each (List<GPoint^> ^ originalPoints in poly_list)
	{
		// スケーリング後のポリゴンの頂点を定義
		array<PointF>^ scaledPoints = gcnew array<PointF>(originalPoints->Count);
		for (int i = 0; i < originalPoints->Count; i++)
		{
			scaledPoints[i].X = (float)(originalPoints[i]->X * scale_factor + LEFT_POSITION);
			scaledPoints[i].Y = (float)(originalPoints[i]->Y * scale_factor + TOP_POSITION);
		}

		g->FillPolygon(Brushes::Red, scaledPoints);
	}

	PicBox->Image = bmp;
}
System::Void gdsreader::GdsViewer::ActionBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	Button^ btn = (Button^)sender;

	if (btn->Name == "Btn_Up")
	{
		TOP_POSITION -= 20;
	}
	else if (btn->Name == "Btn_Down")
	{
		TOP_POSITION += 20;
	}
	else if (btn->Name == "Btn_Left")
	{
		LEFT_POSITION -= 20;
	}
	else if (btn->Name == "Btn_Right")
	{
		LEFT_POSITION += 20;
	}
	else if (btn->Name == "Btn_In")
	{
		SCALE += 0.5;
	}
	else if (btn->Name == "Btn_Out")
	{
		SCALE -= 0.5;
	}

	// 描画処理
	DrawPolygon(GdsPolygons[DisplayLayer]->plygons_list, SCALE);

	return System::Void();
}

System::Void gdsreader::GdsViewer::CreateGdsFile()
{
	Library lib = {};
	lib.init("library", 1e-6, 1e-9);

	Cell cell = {};
	cell.name = copy_string("FIRST", NULL);
	lib.cell_array.append(&cell);

	Vec2 points[] = { {0, 0}, {50, 0}, {50, 50}, {0, 50}, {0, 0},
					 {20, 20}, {20, 30}, {30, 30}, {30, 20}, {20, 20} };
	Polygon* poly = (Polygon*)allocate_clear(sizeof(Polygon));

	poly->point_array.capacity = 0;
	poly->point_array.count = COUNT(points);
	poly->point_array.items = points;

	cell.polygon_array.append(poly);


	lib.write_gds("first.gds", 0, NULL);

	cell.clear();
	lib.clear();
}

System::Void gdsreader::GdsViewer::Cob_SelectLayer_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	DisplayLayer = Cob_SelectLayer->SelectedIndex;

	// 描画処理
	DrawPolygon(GdsPolygons[DisplayLayer]->plygons_list, SCALE);
}

System::Void gdsreader::GdsViewer::GetPolygon(gdstk::Array<Polygon*> polys, gdstk::Tag tag)
{
	GdsPolygon^ _gdspoly = gcnew GdsPolygon();

	for (int64_t i = 0; i < polys.count; i++)
	{
		Polygon* polygon = polys[i];
		
		// 現在ループのタグ層と異なるレイヤーのポリゴンはスキップ
		if (get_layer(polygon->tag) != get_layer(tag))
		{
			continue;
		}

		List<GPoint^>^ _p = gcnew List<GPoint^>();
		for (int64_t j = 0; j < polygon->point_array.count; j++)
		{
			double x, y;
			Vec2 point = polygon->point_array[j];

			_p->Add(gcnew GPoint(point.x, point.y));
		}
		_gdspoly->plygons_list->Add(_p);
	}

	GdsPolygons->Add(_gdspoly);
}

System::Void gdsreader::GdsViewer::Btn_Do_Click(System::Object^ sender, System::EventArgs^ e)
{
	GdsPolygons[DisplayLayer]->plygons_list = Utils::Common::UClipper::CombinePolygons(GdsPolygons[DisplayLayer]->plygons_list, 1.0);

	List<List<GPoint^>^>^ outer = gcnew List<List<GPoint^>^>();
	List<List<GPoint^>^>^ inner = gcnew List<List<GPoint^>^>();

	for each (List<GPoint^> ^ poly in GdsPolygons[DisplayLayer]->plygons_list)
	{
		if (Utils::Common::UClipper::IsClockwise(poly))
		{
			outer->Add(poly);
		}
		else
		{
			inner->Add(poly);
		}
	}

	List<GPoint^>^ counter = Utils::Common::UClipper::SubtractPolygons(outer[0], inner[0]);

	GdsPolygons[DisplayLayer]->plygons_list = gcnew List<List<GPoint^>^>();
	GdsPolygons[DisplayLayer]->plygons_list->Add(counter);

	// 描画処理
	DrawPolygon(GdsPolygons[DisplayLayer]->plygons_list, SCALE);
}

