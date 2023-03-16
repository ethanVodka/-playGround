#include "../pch.h"
#include "FormStopWatch.h"

System::Void TestSample::FormStopWatch::FormStopWatch_Load(System::Object^ sender, System::EventArgs^ e)
{
	//以前保存されたファイルが存在する場合
	if (System::IO::File::Exists(SaveFilePath))
	{
		Windows::Forms::DialogResult^ result;
		result = MessageBox::Show("以前のデータがありますが開きますか", "Question", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
		
		//OKクリック時
		if (result = Windows::Forms::DialogResult::OK)
		{
			ReadFile();
		}
		else
		{
			return;
		}
	}
}

System::Void TestSample::FormStopWatch::BtnStart_Click(System::Object^ sender, System::EventArgs^ e)
{
	IsActive = true;
}

System::Void TestSample::FormStopWatch::BtnStop_Click(System::Object^ sender, System::EventArgs^ e)
{
	IsActive = false;
}

System::Void TestSample::FormStopWatch::BtnReset_Click(System::Object^ sender, System::EventArgs^ e)
{
	IsActive = false;

	ResetTime();
}

System::Void TestSample::FormStopWatch::BtnRapTime_Click(System::Object^ sender, System::EventArgs^ e)
{
	//ラップタイムは動作時のみ処理のため
	if (IsActive)
	{
		//グリッドに一行追加
		dataGridView->Rows->Add();

		//グリッドの一番下の行にラップタイムを表示
		dataGridView->Rows[dataGridView->RowCount - 1]->Cells[0]->Value = TimeMin.ToString("#00") + " : " + TimeSec.ToString("#00") + " : " + TimeCs.ToString("#00");
	}
}

System::Void TestSample::FormStopWatch::BtnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	//保存処理は止まっているとき
	if (!IsActive)
	{
		//ファイル書き出す呪文
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(SaveFilePath, false);
		
		//グリッドのデータをファイルへ書き出す
		for (int i = 0; i < dataGridView->RowCount; i++)
		{
			//1行筒書き足す
			sw->WriteLine(dataGridView->Rows[i]->Cells[0]->Value->ToString());
		}
		
		//書き出す呪文をクローズ
		//絶対いるのでわすれないで
		sw->Close();

		//完了ダイアログ表示
		MessageBox::Show("保存完了", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

System::Void TestSample::FormStopWatch::timer__Tick(System::Object^ sender, System::EventArgs^ e)
{
	//動いているフラグ成立時のみ
	if (IsActive)
	{
		/*
			ミリ秒からカウントしていき
			Cs = 100, Sec = 60 のカウントごとに上の単位を更新する
		*/

		TimeCs++;

		if (TimeCs >= 100)
		{
			TimeSec++;
			TimeCs = 0;

			if (TimeSec >= 60)
			{
				TimeMin++;
				TimeSec = 0;

				if (TimeMin == 59)
				{
					//59分までカウントしたらストップ
					IsActive = false;
				}
			}
		}
		DrawTime();
	}
}

System::Void TestSample::FormStopWatch::ResetTime()
{
	TimeCs = 0;
	TimeSec = 0;
	TimeMin = 0;

	DrawTime();
}

System::Void TestSample::FormStopWatch::DrawTime()
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

	//grapicsの文字列描画メソッド
	//引数 （描画する文字列、フォント、筆の色、描画開始位置X、描画開始位置Y）
	objGrp->DrawString(TimeMin.ToString("#00") + " : " + TimeSec.ToString("#00") + " : " + TimeCs.ToString("#00"), objFnt, Brushes::Black, 20, PicBox->Height * 0.2);

	//キャンバスの絵をpictureboxに映す
	PicBox->Image = objBmp;
}

System::Void TestSample::FormStopWatch::ReadFile()
{
	//ファイル読み込む呪文
	System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(SaveFilePath);

	//最終行まで一行ずつ読み込む呪文
	while (!sr->EndOfStream)
	{
		String^ line = sr->ReadLine();

		//グリッドに一行追加
		dataGridView->Rows->Add();

		//グリッドの一番下の行にラップタイムを表示
		dataGridView->Rows[dataGridView->RowCount - 1]->Cells[0]->Value = line;
	}

	sr->Close();

	//完了ダイアログ表示
	MessageBox::Show("読み込み完了", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
