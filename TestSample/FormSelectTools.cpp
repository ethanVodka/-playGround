#include "pch.h"
#include "FormSelectTools.h"

System::Void TestSample::FormSelectTools::BtnExitApp_Click(System::Object^ sender, System::EventArgs^ e)
{
	//�A�v���P�[�V�����I��
	Application::Exit();
}

System::Void TestSample::FormSelectTools::BtnStWatch_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (CurrentForm != nullptr)
	{
		//�������݃t�H�[�����J����Ă���ꍇ�͕��ĊJ���Ȃ���
		//�d���t�H�[���h�~
		CurrentForm->Close();
	}


	//�Ăяo���t�H�[���N���X�̃C���X�^���X�쐬
	CurrentForm = gcnew FormStopWatch();

	//�t�H�[���̕\������
	CurrentForm->Show();

}

System::Void TestSample::FormSelectTools::BtnCalc_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (CurrentForm != nullptr)
	{
		//�������݃t�H�[�����J����Ă���ꍇ�͕��ĊJ���Ȃ���
		//�d���t�H�[���h�~
		CurrentForm->Close();
	}


	//�Ăяo���t�H�[���N���X�̃C���X�^���X�쐬
	CurrentForm = gcnew FormCalculator();

	//�t�H�[���̕\������
	CurrentForm->Show();
}
