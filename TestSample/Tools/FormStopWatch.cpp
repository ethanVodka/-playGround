#include "../pch.h"
#include "FormStopWatch.h"

System::Void TestSample::FormStopWatch::FormStopWatch_Load(System::Object^ sender, System::EventArgs^ e)
{
	//�ȑO�ۑ����ꂽ�t�@�C�������݂���ꍇ
	if (System::IO::File::Exists(SaveFilePath))
	{
		Windows::Forms::DialogResult^ result;
		result = MessageBox::Show("�ȑO�̃f�[�^������܂����J���܂���", "Question", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);
		
		//OK�N���b�N��
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
	//���b�v�^�C���͓��쎞�̂ݏ����̂���
	if (IsActive)
	{
		//�O���b�h�Ɉ�s�ǉ�
		dataGridView->Rows->Add();

		//�O���b�h�̈�ԉ��̍s�Ƀ��b�v�^�C����\��
		dataGridView->Rows[dataGridView->RowCount - 1]->Cells[0]->Value = TimeMin.ToString("#00") + " : " + TimeSec.ToString("#00") + " : " + TimeCs.ToString("#00");
	}
}

System::Void TestSample::FormStopWatch::BtnSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	//�ۑ������͎~�܂��Ă���Ƃ�
	if (!IsActive)
	{
		//�t�@�C�������o������
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(SaveFilePath, false);
		
		//�O���b�h�̃f�[�^���t�@�C���֏����o��
		for (int i = 0; i < dataGridView->RowCount; i++)
		{
			//1�s����������
			sw->WriteLine(dataGridView->Rows[i]->Cells[0]->Value->ToString());
		}
		
		//�����o���������N���[�Y
		//��΂���̂ł킷��Ȃ���
		sw->Close();

		//�����_�C�A���O�\��
		MessageBox::Show("�ۑ�����", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

System::Void TestSample::FormStopWatch::timer__Tick(System::Object^ sender, System::EventArgs^ e)
{
	//�����Ă���t���O�������̂�
	if (IsActive)
	{
		/*
			�~���b����J�E���g���Ă���
			Cs = 100, Sec = 60 �̃J�E���g���Ƃɏ�̒P�ʂ��X�V����
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
					//59���܂ŃJ�E���g������X�g�b�v
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
	objGrp->DrawString(TimeMin.ToString("#00") + " : " + TimeSec.ToString("#00") + " : " + TimeCs.ToString("#00"), objFnt, Brushes::Black, 20, PicBox->Height * 0.2);

	//�L�����o�X�̊G��picturebox�ɉf��
	PicBox->Image = objBmp;
}

System::Void TestSample::FormStopWatch::ReadFile()
{
	//�t�@�C���ǂݍ��ގ���
	System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(SaveFilePath);

	//�ŏI�s�܂ň�s���ǂݍ��ގ���
	while (!sr->EndOfStream)
	{
		String^ line = sr->ReadLine();

		//�O���b�h�Ɉ�s�ǉ�
		dataGridView->Rows->Add();

		//�O���b�h�̈�ԉ��̍s�Ƀ��b�v�^�C����\��
		dataGridView->Rows[dataGridView->RowCount - 1]->Cells[0]->Value = line;
	}

	sr->Close();

	//�����_�C�A���O�\��
	MessageBox::Show("�ǂݍ��݊���", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
