#pragma once

namespace TestSample {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;

	/// <summary>
	/// FormStopWatch �̊T�v
	/// </summary>
	public ref class FormStopWatch : public System::Windows::Forms::Form
	{
	public:
		FormStopWatch(void)
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
		~FormStopWatch()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ BaseSplitContainer;
	private: System::Windows::Forms::SplitContainer^ ControlSplitContainer;
	private: System::Windows::Forms::DataGridView^ dataGridView;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TimeCol;
	private: System::Windows::Forms::PictureBox^ PicBox;
	private: System::Windows::Forms::Button^ BtnSave;
	private: System::Windows::Forms::Button^ BtnReset;
	private: System::Windows::Forms::Button^ BtnStop;
	private: System::Windows::Forms::Button^ BtnStart;

	private: System::Windows::Forms::Button^ BtnRapTime;
	private: System::Windows::Forms::Timer^ timer_;

	private: System::ComponentModel::IContainer^ components;
	protected:


	protected:

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->BaseSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->PicBox = (gcnew System::Windows::Forms::PictureBox());
			this->ControlSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->BtnRapTime = (gcnew System::Windows::Forms::Button());
			this->BtnSave = (gcnew System::Windows::Forms::Button());
			this->BtnReset = (gcnew System::Windows::Forms::Button());
			this->BtnStop = (gcnew System::Windows::Forms::Button());
			this->BtnStart = (gcnew System::Windows::Forms::Button());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->TimeCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->timer_ = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BaseSplitContainer))->BeginInit();
			this->BaseSplitContainer->Panel1->SuspendLayout();
			this->BaseSplitContainer->Panel2->SuspendLayout();
			this->BaseSplitContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ControlSplitContainer))->BeginInit();
			this->ControlSplitContainer->Panel1->SuspendLayout();
			this->ControlSplitContainer->Panel2->SuspendLayout();
			this->ControlSplitContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// BaseSplitContainer
			// 
			this->BaseSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->BaseSplitContainer->Location = System::Drawing::Point(0, 0);
			this->BaseSplitContainer->Name = L"BaseSplitContainer";
			this->BaseSplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// BaseSplitContainer.Panel1
			// 
			this->BaseSplitContainer->Panel1->Controls->Add(this->PicBox);
			// 
			// BaseSplitContainer.Panel2
			// 
			this->BaseSplitContainer->Panel2->Controls->Add(this->ControlSplitContainer);
			this->BaseSplitContainer->Size = System::Drawing::Size(452, 354);
			this->BaseSplitContainer->SplitterDistance = 181;
			this->BaseSplitContainer->TabIndex = 0;
			// 
			// PicBox
			// 
			this->PicBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PicBox->Location = System::Drawing::Point(0, 0);
			this->PicBox->Name = L"PicBox";
			this->PicBox->Size = System::Drawing::Size(452, 181);
			this->PicBox->TabIndex = 0;
			this->PicBox->TabStop = false;
			// 
			// ControlSplitContainer
			// 
			this->ControlSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ControlSplitContainer->Location = System::Drawing::Point(0, 0);
			this->ControlSplitContainer->Name = L"ControlSplitContainer";
			// 
			// ControlSplitContainer.Panel1
			// 
			this->ControlSplitContainer->Panel1->Controls->Add(this->BtnRapTime);
			this->ControlSplitContainer->Panel1->Controls->Add(this->BtnSave);
			this->ControlSplitContainer->Panel1->Controls->Add(this->BtnReset);
			this->ControlSplitContainer->Panel1->Controls->Add(this->BtnStop);
			this->ControlSplitContainer->Panel1->Controls->Add(this->BtnStart);
			// 
			// ControlSplitContainer.Panel2
			// 
			this->ControlSplitContainer->Panel2->Controls->Add(this->dataGridView);
			this->ControlSplitContainer->Size = System::Drawing::Size(452, 169);
			this->ControlSplitContainer->SplitterDistance = 299;
			this->ControlSplitContainer->TabIndex = 0;
			// 
			// BtnRapTime
			// 
			this->BtnRapTime->Location = System::Drawing::Point(76, 98);
			this->BtnRapTime->Name = L"BtnRapTime";
			this->BtnRapTime->Size = System::Drawing::Size(67, 59);
			this->BtnRapTime->TabIndex = 4;
			this->BtnRapTime->Text = L"Rap";
			this->BtnRapTime->UseVisualStyleBackColor = true;
			this->BtnRapTime->Click += gcnew System::EventHandler(this, &FormStopWatch::BtnRapTime_Click);
			// 
			// BtnSave
			// 
			this->BtnSave->Location = System::Drawing::Point(200, 14);
			this->BtnSave->Name = L"BtnSave";
			this->BtnSave->Size = System::Drawing::Size(75, 23);
			this->BtnSave->TabIndex = 3;
			this->BtnSave->Text = L"Save";
			this->BtnSave->UseVisualStyleBackColor = true;
			this->BtnSave->Click += gcnew System::EventHandler(this, &FormStopWatch::BtnSave_Click);
			// 
			// BtnReset
			// 
			this->BtnReset->Location = System::Drawing::Point(224, 98);
			this->BtnReset->Name = L"BtnReset";
			this->BtnReset->Size = System::Drawing::Size(69, 59);
			this->BtnReset->TabIndex = 2;
			this->BtnReset->Text = L"Reset";
			this->BtnReset->UseVisualStyleBackColor = true;
			this->BtnReset->Click += gcnew System::EventHandler(this, &FormStopWatch::BtnReset_Click);
			// 
			// BtnStop
			// 
			this->BtnStop->Location = System::Drawing::Point(149, 97);
			this->BtnStop->Name = L"BtnStop";
			this->BtnStop->Size = System::Drawing::Size(69, 59);
			this->BtnStop->TabIndex = 1;
			this->BtnStop->Text = L"Stop";
			this->BtnStop->UseVisualStyleBackColor = true;
			this->BtnStop->Click += gcnew System::EventHandler(this, &FormStopWatch::BtnStop_Click);
			// 
			// BtnStart
			// 
			this->BtnStart->Location = System::Drawing::Point(3, 97);
			this->BtnStart->Name = L"BtnStart";
			this->BtnStart->Size = System::Drawing::Size(67, 59);
			this->BtnStart->TabIndex = 0;
			this->BtnStart->Text = L"Start";
			this->BtnStart->UseVisualStyleBackColor = true;
			this->BtnStart->Click += gcnew System::EventHandler(this, &FormStopWatch::BtnStart_Click);
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->TimeCol });
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView->Location = System::Drawing::Point(0, 0);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->RowTemplate->Height = 21;
			this->dataGridView->Size = System::Drawing::Size(149, 169);
			this->dataGridView->TabIndex = 0;
			// 
			// TimeCol
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->TimeCol->DefaultCellStyle = dataGridViewCellStyle2;
			this->TimeCol->HeaderText = L"Time";
			this->TimeCol->Name = L"TimeCol";
			// 
			// timer_
			// 
			this->timer_->Enabled = true;
			this->timer_->Interval = 10;
			this->timer_->Tick += gcnew System::EventHandler(this, &FormStopWatch::timer__Tick);
			// 
			// FormStopWatch
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(452, 354);
			this->Controls->Add(this->BaseSplitContainer);
			this->Name = L"FormStopWatch";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormStopWatch";
			this->Load += gcnew System::EventHandler(this, &FormStopWatch::FormStopWatch_Load);
			this->BaseSplitContainer->Panel1->ResumeLayout(false);
			this->BaseSplitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BaseSplitContainer))->EndInit();
			this->BaseSplitContainer->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBox))->EndInit();
			this->ControlSplitContainer->Panel1->ResumeLayout(false);
			this->ControlSplitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ControlSplitContainer))->EndInit();
			this->ControlSplitContainer->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		//�f�[�^�ۑ��t�@�C���p�X
		//C:\Users\[���[�U�[��]\AppData\Local\Temp//stopwatch.txt
		String^ SaveFilePath = System::IO::Path::GetTempPath() + "stopwatch.txt";

		int TimeCs = 0;		//�~���b
		int TimeSec = 0;	//�b
		int TimeMin = 0;	//��

		bool IsActive = false;

		///���������C�x���g���\�b�h///

		//�N�������������C�x���g
		System::Void FormStopWatch_Load(System::Object^ sender, System::EventArgs^ e);

		//Start�{�^���N���b�N
		System::Void BtnStart_Click(System::Object^ sender, System::EventArgs^ e);

		//Stop�{�^���N���b�N
		System::Void BtnStop_Click(System::Object^ sender, System::EventArgs^ e);

		//Reset�{�^���N���b�N
		System::Void BtnReset_Click(System::Object^ sender, System::EventArgs^ e);

		//Rap�{�^���N���b�N�C�x���g
		System::Void BtnRapTime_Click(System::Object^ sender, System::EventArgs^ e);

		//Save�{�^���N���b�N
		System::Void BtnSave_Click(System::Object^ sender, System::EventArgs^ e);

		//Timer�C�x���g
		System::Void timer__Tick(System::Object^ sender, System::EventArgs^ e);


		///���[�U��`���\�b�h///

		//������
		System::Void ResetTime();

		//PicBox�`�揈��
		System::Void DrawTime();
		
		//�ߋ��̃f�[�^�ǂݍ���
		System::Void ReadFile();
	};
}
