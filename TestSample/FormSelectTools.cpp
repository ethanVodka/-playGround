#include "pch.h"
#include "FormSelectTools.h"

System::Void TestSample::FormSelectTools::BtnExitApp_Click(System::Object^ sender, System::EventArgs^ e)
{
	//アプリケーション終了
	Application::Exit();
}

System::Void TestSample::FormSelectTools::BtnStWatch_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (CurrentForm != nullptr)
	{
		//もし現在フォームが開かれている場合は閉じて開きなおす
		//重複フォーム防止
		CurrentForm->Close();
	}


	//呼び出すフォームクラスのインスタンス作成
	CurrentForm = gcnew FormStopWatch();

	//フォームの表示処理
	CurrentForm->Show();

}

System::Void TestSample::FormSelectTools::BtnCalc_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (CurrentForm != nullptr)
	{
		//もし現在フォームが開かれている場合は閉じて開きなおす
		//重複フォーム防止
		CurrentForm->Close();
	}


	//呼び出すフォームクラスのインスタンス作成
	CurrentForm = gcnew FormCalculator();

	//フォームの表示処理
	CurrentForm->Show();
}
