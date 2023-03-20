#include "../pch.h"
#include "FormCalculator.h"

System::Void TestSample::FormCalculator::Number_Click(System::Object^ sender, System::EventArgs^ e)
{
	Button^ btn = (Button^)sender;
	//ボタンテキストで分岐処理
	if (btn->Text != ".")
	{
		TxtBox->Text += btn->Text;
	}
	else
	{
		array<String^>^ splitStr = TxtBox->Text->Split('/', '+', '-', '*');
		if (splitStr[splitStr->Length - 1]->Contains(".") == false)
		{
			TxtBox->Text += btn->Text;
		}
		else
		{
			return;
		}
	}
}

System::Void TestSample::FormCalculator::Operatrion_Click(System::Object^ sender, System::EventArgs^ e)
{
	Button^ btn = (Button^)sender;
	String^ ope = btn->Text;

	//各オペレーションボタンごとの処理
	if (ope == "+")
	{
		TxtBox->Text += "+";
	}
	else if (ope == "-")
	{
		TxtBox->Text += "-";
	}
	else if (ope == "÷")
	{
		TxtBox->Text += "/";
	}
	else if (ope == "×")
	{
		TxtBox->Text += "*";
	}
	else if (ope == "(" || ope == ")")
	{
		TxtBox->Text += ope;
	}
	else
	{
		return;
	}
}

System::Void TestSample::FormCalculator::btnClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (TxtBox->Text != "")
	{
		//テキストボックスの後ろから一文字削除
		TxtBox->Text = TxtBox->Text->Substring(0, TxtBox->Text->Length - 1);
	}
}

System::Void TestSample::FormCalculator::BtnAllClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	//初期化処理
	TxtBox->Text = String::Empty;
	SetCalcLine("0");
}

System::Void TestSample::FormCalculator::BtnEqual_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		String^ result = (Evaluate(TxtBox->Text)).ToString();

		if (result->EndsWith(".0"))
		{
			result = result->Replace(".0", "");
		}
		SetCalcLine(result);
	}
	catch (Exception^)
	{
		SetCalcLine("Error");
	}
}

System::Void TestSample::FormCalculator::SetCalcLine(String^ value)
{
	//Bitmapクラスのインスタンス作成
	//キャンバスを作るイメージ
	//描画先のpictureBox縦幅,横幅と同じサイズ指定
	System::Drawing::Bitmap^ objBmp = gcnew System::Drawing::Bitmap(PicBox->Width, PicBox->Height);

	//Graphicsクラスのインスタンス
	//キャンバスの上にあるペンのイメージ
	System::Drawing::Graphics^ objGrp = System::Drawing::Graphics::FromImage(objBmp);

	//文字列描画するときのフォント指定
	System::Drawing::Font^ objFnt = gcnew System::Drawing::Font("MS UI Gothic", 60);

	//小数点描画時あふれるのを防ぐ
	while (value->Length > 10)
	{
		value = value->Substring(0, value->Length - 1);
	}

	//grapicsの文字列描画メソッド
	//引数 （描画する文字列、フォント、筆の色、描画開始位置X、描画開始位置Y）
	objGrp->DrawString(value, objFnt, Brushes::Black, 20, PicBox->Height * 0.0f);

	//キャンバスの絵をpictureboxに映す
	PicBox->Image = objBmp;

	if (value != "0")
	{
		//保存のため格納
		UserInput += TxtBox->Text + " = " + value + "\n";
		//グリッドに一行追加
		DataGrid->Rows->Add();
		//グリッドの一番下の行にラップタイムを表示
		DataGrid->Rows[DataGrid->RowCount - 1]->Cells[0]->Value = TxtBox->Text + " = " + value;
		//表示初期化
		TxtBox->Text = String::Empty;
	}
}

System::Void TestSample::FormCalculator::BtnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	//ファイル書き出す呪文
	System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(SaveFilePath, false);

	//グリッドのデータをファイルへ書き出す

	//1行筒書き足す
	sw->WriteLine(UserInput);


	//書き出す呪文をクローズ
	//絶対いるのでわすれないで
	sw->Close();

	//完了ダイアログ表示
	MessageBox::Show("保存完了", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
