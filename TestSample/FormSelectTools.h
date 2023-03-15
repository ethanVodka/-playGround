#pragma once
//Tools�f�B���N�g���[�̃t�H�[���̃w�b�_�[�t�@�C�����C���N���[�h
#include "Tools/FormCalculator.h"
#include "Tools/FormStopWatch.h"


namespace TestSample {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// FormSelectTools �̊T�v
	/// </summary>
	public ref class FormSelectTools : public System::Windows::Forms::Form
	{
	public:
		FormSelectTools(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~FormSelectTools()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ MainPanel;
	private: System::Windows::Forms::Button^ BtnExitApp;
	protected:

	private: System::Windows::Forms::Button^ BtnStWatch;
	private: System::Windows::Forms::Button^ BtnCalc;

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->MainPanel = (gcnew System::Windows::Forms::Panel());
			this->BtnExitApp = (gcnew System::Windows::Forms::Button());
			this->BtnStWatch = (gcnew System::Windows::Forms::Button());
			this->BtnCalc = (gcnew System::Windows::Forms::Button());
			this->MainPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// MainPanel
			// 
			this->MainPanel->Controls->Add(this->BtnExitApp);
			this->MainPanel->Controls->Add(this->BtnStWatch);
			this->MainPanel->Controls->Add(this->BtnCalc);
			this->MainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MainPanel->Location = System::Drawing::Point(0, 0);
			this->MainPanel->Name = L"MainPanel";
			this->MainPanel->Size = System::Drawing::Size(233, 192);
			this->MainPanel->TabIndex = 0;
			// 
			// BtnExitApp
			// 
			this->BtnExitApp->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->BtnExitApp->Location = System::Drawing::Point(0, 162);
			this->BtnExitApp->Name = L"BtnExitApp";
			this->BtnExitApp->Size = System::Drawing::Size(233, 30);
			this->BtnExitApp->TabIndex = 3;
			this->BtnExitApp->Text = L"Exit";
			this->BtnExitApp->UseVisualStyleBackColor = true;
			this->BtnExitApp->Click += gcnew System::EventHandler(this, &FormSelectTools::BtnExitApp_Click);
			// 
			// BtnStWatch
			// 
			this->BtnStWatch->Dock = System::Windows::Forms::DockStyle::Top;
			this->BtnStWatch->Location = System::Drawing::Point(0, 60);
			this->BtnStWatch->Name = L"BtnStWatch";
			this->BtnStWatch->Size = System::Drawing::Size(233, 60);
			this->BtnStWatch->TabIndex = 1;
			this->BtnStWatch->Text = L"StopWatch";
			this->BtnStWatch->UseVisualStyleBackColor = true;
			this->BtnStWatch->Click += gcnew System::EventHandler(this, &FormSelectTools::BtnStWatch_Click);
			// 
			// BtnCalc
			// 
			this->BtnCalc->Dock = System::Windows::Forms::DockStyle::Top;
			this->BtnCalc->Location = System::Drawing::Point(0, 0);
			this->BtnCalc->Name = L"BtnCalc";
			this->BtnCalc->Size = System::Drawing::Size(233, 60);
			this->BtnCalc->TabIndex = 0;
			this->BtnCalc->Text = L"Calculator";
			this->BtnCalc->UseVisualStyleBackColor = true;
			this->BtnCalc->Click += gcnew System::EventHandler(this, &FormSelectTools::BtnCalc_Click);
			// 
			// FormSelectTools
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(233, 192);
			this->Controls->Add(this->MainPanel);
			this->Name = L"FormSelectTools";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormSelectTools";
			this->MainPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		//���݊J���Ă���t�H�[���̏���ێ�
		Form^ CurrentForm = nullptr;

		//���������C�x���g���\�b�h��`
		//Exit\�{�^���N���b�N
		System::Void BtnExitApp_Click(System::Object^ sender, System::EventArgs^ e);
		//StopWatch�{�^���N���b�N
		System::Void BtnStWatch_Click(System::Object^ sender, System::EventArgs^ e);
		//Calculator�{�^���N���b�N
		System::Void BtnCalc_Click(System::Object^ sender, System::EventArgs^ e);

	};
}
