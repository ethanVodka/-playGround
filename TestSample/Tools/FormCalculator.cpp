#include "../pch.h"
#include "FormCalculator.h"

System::Void TestSample::FormCalculator::Number_Click(System::Object^ sender, System::EventArgs^ e)
{
	Button^ btn = (Button^)sender;
	//�{�^���e�L�X�g�ŕ��򏈗�
	if (btn->Text != ".")
	{
		TxtBox->Text += btn->Text;
	}
	else
	{
		if (TxtBox->Text->Contains(".") == false)
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

	//�e�I�y���[�V�����{�^�����Ƃ̏���
	if (ope == "+")
	{
		TxtBox->Text += "+";
	}
	else if (ope == "-")
	{
		TxtBox->Text += "-";
	}
	else if (ope == "��")
	{
		TxtBox->Text += "/";
	}
	else if (ope == "�~")
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
	//�e�L�X�g�{�b�N�X�̌�납��ꕶ���폜
	TxtBox->Text = TxtBox->Text->Substring(0, TxtBox->Text->Length - 1);
}

System::Void TestSample::FormCalculator::BtnAllClear_Click(System::Object^ sender, System::EventArgs^ e)
{
	//����������
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
	//Bitmap�N���X�̃C���X�^���X�쐬
	//�L�����o�X�����C���[�W
	//�`����pictureBox�c��,�����Ɠ����T�C�Y�w��
	System::Drawing::Bitmap^ objBmp = gcnew System::Drawing::Bitmap(PicBox->Width, PicBox->Height);

	//Graphics�N���X�̃C���X�^���X
	//�L�����o�X�̏�ɂ���y���̃C���[�W
	System::Drawing::Graphics^ objGrp = System::Drawing::Graphics::FromImage(objBmp);

	//������`�悷��Ƃ��̃t�H���g�w��
	System::Drawing::Font^ objFnt = gcnew System::Drawing::Font("MS UI Gothic", 60);

	//grapics�̕�����`�惁�\�b�h
	//���� �i�`�悷�镶����A�t�H���g�A�M�̐F�A�`��J�n�ʒuX�A�`��J�n�ʒuY�j
	objGrp->DrawString(value, objFnt, Brushes::Black, 20, PicBox->Height * 0.2f);

	//�L�����o�X�̊G��picturebox�ɉf��
	PicBox->Image = objBmp;

	if (value != "0")
	{
		//�ۑ��̂��ߊi�[
		UserInput += TxtBox->Text + " = " + value + "\n";

		//�\��������
		TxtBox->Text = String::Empty;
	}
}

System::Void TestSample::FormCalculator::BtnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	//�t�@�C�������o������
	System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(SaveFilePath, false);

	//�O���b�h�̃f�[�^���t�@�C���֏����o��

	//1�s����������
	sw->WriteLine(UserInput);


	//�����o���������N���[�Y
	//��΂���̂ł킷��Ȃ���
	sw->Close();

	//�����_�C�A���O�\��
	MessageBox::Show("�ۑ�����", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
