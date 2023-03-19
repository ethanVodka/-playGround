#pragma once

namespace TestSample {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Web::Compilation;


	/// <summary>
	/// FormCalculator の概要
	/// </summary>
	public ref class FormCalculator : public System::Windows::Forms::Form
	{
	public:
		FormCalculator(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~FormCalculator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ BaseSplitContainer;
	private: System::Windows::Forms::PictureBox^ PicBox;
	private: System::Windows::Forms::Button^ BtnMulitple;
	private: System::Windows::Forms::Button^ Btn9;
	private: System::Windows::Forms::Button^ Btn8;
	private: System::Windows::Forms::Button^ Btn7;
	private: System::Windows::Forms::Button^ BtnDivide;
	private: System::Windows::Forms::Button^ Btn6;
	private: System::Windows::Forms::Button^ Btn5;
	private: System::Windows::Forms::Button^ Btn4;
	private: System::Windows::Forms::Button^ BtnMinus;
	private: System::Windows::Forms::Button^ Btn3;
	private: System::Windows::Forms::Button^ Btn2;
	private: System::Windows::Forms::Button^ Btn1;
	private: System::Windows::Forms::Button^ BtnPlus;
	private: System::Windows::Forms::Button^ BtnbracketsRight;

	private: System::Windows::Forms::Button^ BtnAllClear;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ BtnEqual;
	private: System::Windows::Forms::Button^ BtnDot;
	private: System::Windows::Forms::Button^ Btn0;
	private: System::Windows::Forms::TextBox^ TxtBox;
	private: System::Windows::Forms::Button^ BtnSave;



	private: System::Windows::Forms::Button^ BtnbracketsLeft;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::DataGridView^ DataGrid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CalcHistory;





	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->BaseSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->TxtBox = (gcnew System::Windows::Forms::TextBox());
			this->PicBox = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->BtnAllClear = (gcnew System::Windows::Forms::Button());
			this->BtnSave = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->BtnbracketsLeft = (gcnew System::Windows::Forms::Button());
			this->BtnbracketsRight = (gcnew System::Windows::Forms::Button());
			this->BtnPlus = (gcnew System::Windows::Forms::Button());
			this->Btn1 = (gcnew System::Windows::Forms::Button());
			this->Btn2 = (gcnew System::Windows::Forms::Button());
			this->Btn3 = (gcnew System::Windows::Forms::Button());
			this->BtnMinus = (gcnew System::Windows::Forms::Button());
			this->Btn4 = (gcnew System::Windows::Forms::Button());
			this->Btn5 = (gcnew System::Windows::Forms::Button());
			this->Btn6 = (gcnew System::Windows::Forms::Button());
			this->BtnDivide = (gcnew System::Windows::Forms::Button());
			this->Btn7 = (gcnew System::Windows::Forms::Button());
			this->Btn8 = (gcnew System::Windows::Forms::Button());
			this->Btn9 = (gcnew System::Windows::Forms::Button());
			this->BtnMulitple = (gcnew System::Windows::Forms::Button());
			this->Btn0 = (gcnew System::Windows::Forms::Button());
			this->BtnDot = (gcnew System::Windows::Forms::Button());
			this->BtnEqual = (gcnew System::Windows::Forms::Button());
			this->DataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->CalcHistory = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BaseSplitContainer))->BeginInit();
			this->BaseSplitContainer->Panel1->SuspendLayout();
			this->BaseSplitContainer->Panel2->SuspendLayout();
			this->BaseSplitContainer->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBox))->BeginInit();
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// BaseSplitContainer
			// 
			this->BaseSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->BaseSplitContainer->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->BaseSplitContainer->Location = System::Drawing::Point(0, 0);
			this->BaseSplitContainer->Name = L"BaseSplitContainer";
			this->BaseSplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// BaseSplitContainer.Panel1
			// 
			this->BaseSplitContainer->Panel1->Controls->Add(this->panel1);
			this->BaseSplitContainer->Panel1->Controls->Add(this->PicBox);
			// 
			// BaseSplitContainer.Panel2
			// 
			this->BaseSplitContainer->Panel2->Controls->Add(this->flowLayoutPanel1);
			this->BaseSplitContainer->Panel2->Controls->Add(this->DataGrid);
			this->BaseSplitContainer->Size = System::Drawing::Size(418, 626);
			this->BaseSplitContainer->SplitterDistance = 142;
			this->BaseSplitContainer->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->TxtBox);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(418, 45);
			this->panel1->TabIndex = 3;
			// 
			// TxtBox
			// 
			this->TxtBox->BackColor = System::Drawing::SystemColors::Control;
			this->TxtBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->TxtBox->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->TxtBox->Location = System::Drawing::Point(0, 0);
			this->TxtBox->Name = L"TxtBox";
			this->TxtBox->ReadOnly = true;
			this->TxtBox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->TxtBox->Size = System::Drawing::Size(418, 39);
			this->TxtBox->TabIndex = 2;
			// 
			// PicBox
			// 
			this->PicBox->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->PicBox->Location = System::Drawing::Point(0, 47);
			this->PicBox->Margin = System::Windows::Forms::Padding(0);
			this->PicBox->Name = L"PicBox";
			this->PicBox->Size = System::Drawing::Size(418, 95);
			this->PicBox->TabIndex = 1;
			this->PicBox->TabStop = false;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->BtnAllClear);
			this->flowLayoutPanel1->Controls->Add(this->BtnSave);
			this->flowLayoutPanel1->Controls->Add(this->btnClear);
			this->flowLayoutPanel1->Controls->Add(this->BtnbracketsLeft);
			this->flowLayoutPanel1->Controls->Add(this->BtnbracketsRight);
			this->flowLayoutPanel1->Controls->Add(this->BtnPlus);
			this->flowLayoutPanel1->Controls->Add(this->Btn1);
			this->flowLayoutPanel1->Controls->Add(this->Btn2);
			this->flowLayoutPanel1->Controls->Add(this->Btn3);
			this->flowLayoutPanel1->Controls->Add(this->BtnMinus);
			this->flowLayoutPanel1->Controls->Add(this->Btn4);
			this->flowLayoutPanel1->Controls->Add(this->Btn5);
			this->flowLayoutPanel1->Controls->Add(this->Btn6);
			this->flowLayoutPanel1->Controls->Add(this->BtnDivide);
			this->flowLayoutPanel1->Controls->Add(this->Btn7);
			this->flowLayoutPanel1->Controls->Add(this->Btn8);
			this->flowLayoutPanel1->Controls->Add(this->Btn9);
			this->flowLayoutPanel1->Controls->Add(this->BtnMulitple);
			this->flowLayoutPanel1->Controls->Add(this->Btn0);
			this->flowLayoutPanel1->Controls->Add(this->BtnDot);
			this->flowLayoutPanel1->Controls->Add(this->BtnEqual);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 98);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(418, 382);
			this->flowLayoutPanel1->TabIndex = 24;
			// 
			// BtnAllClear
			// 
			this->BtnAllClear->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnAllClear->Location = System::Drawing::Point(0, 0);
			this->BtnAllClear->Margin = System::Windows::Forms::Padding(0);
			this->BtnAllClear->Name = L"BtnAllClear";
			this->BtnAllClear->Size = System::Drawing::Size(206, 63);
			this->BtnAllClear->TabIndex = 1;
			this->BtnAllClear->Text = L"AC";
			this->BtnAllClear->UseVisualStyleBackColor = true;
			this->BtnAllClear->Click += gcnew System::EventHandler(this, &FormCalculator::BtnAllClear_Click);
			// 
			// BtnSave
			// 
			this->BtnSave->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnSave->Location = System::Drawing::Point(206, 0);
			this->BtnSave->Margin = System::Windows::Forms::Padding(0);
			this->BtnSave->Name = L"BtnSave";
			this->BtnSave->Size = System::Drawing::Size(206, 63);
			this->BtnSave->TabIndex = 22;
			this->BtnSave->Text = L"save";
			this->BtnSave->UseVisualStyleBackColor = true;
			this->BtnSave->Click += gcnew System::EventHandler(this, &FormCalculator::BtnSave_Click);
			// 
			// btnClear
			// 
			this->btnClear->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->btnClear->Location = System::Drawing::Point(0, 63);
			this->btnClear->Margin = System::Windows::Forms::Padding(0);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(103, 63);
			this->btnClear->TabIndex = 0;
			this->btnClear->Text = L"C";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &FormCalculator::btnClear_Click);
			// 
			// BtnbracketsLeft
			// 
			this->BtnbracketsLeft->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnbracketsLeft->Location = System::Drawing::Point(103, 63);
			this->BtnbracketsLeft->Margin = System::Windows::Forms::Padding(0);
			this->BtnbracketsLeft->Name = L"BtnbracketsLeft";
			this->BtnbracketsLeft->Size = System::Drawing::Size(103, 63);
			this->BtnbracketsLeft->TabIndex = 20;
			this->BtnbracketsLeft->Text = L"(";
			this->BtnbracketsLeft->UseVisualStyleBackColor = true;
			this->BtnbracketsLeft->Click += gcnew System::EventHandler(this, &FormCalculator::Operatrion_Click);
			// 
			// BtnbracketsRight
			// 
			this->BtnbracketsRight->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnbracketsRight->Location = System::Drawing::Point(206, 63);
			this->BtnbracketsRight->Margin = System::Windows::Forms::Padding(0);
			this->BtnbracketsRight->Name = L"BtnbracketsRight";
			this->BtnbracketsRight->Size = System::Drawing::Size(103, 63);
			this->BtnbracketsRight->TabIndex = 2;
			this->BtnbracketsRight->Text = L")";
			this->BtnbracketsRight->UseVisualStyleBackColor = true;
			this->BtnbracketsRight->Click += gcnew System::EventHandler(this, &FormCalculator::Operatrion_Click);
			// 
			// BtnPlus
			// 
			this->BtnPlus->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnPlus->Location = System::Drawing::Point(309, 63);
			this->BtnPlus->Margin = System::Windows::Forms::Padding(0);
			this->BtnPlus->Name = L"BtnPlus";
			this->BtnPlus->Size = System::Drawing::Size(103, 63);
			this->BtnPlus->TabIndex = 3;
			this->BtnPlus->Text = L"+";
			this->BtnPlus->UseVisualStyleBackColor = true;
			this->BtnPlus->Click += gcnew System::EventHandler(this, &FormCalculator::Operatrion_Click);
			// 
			// Btn1
			// 
			this->Btn1->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn1->Location = System::Drawing::Point(0, 126);
			this->Btn1->Margin = System::Windows::Forms::Padding(0);
			this->Btn1->Name = L"Btn1";
			this->Btn1->Size = System::Drawing::Size(103, 63);
			this->Btn1->TabIndex = 4;
			this->Btn1->Text = L"1";
			this->Btn1->UseVisualStyleBackColor = true;
			this->Btn1->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn2
			// 
			this->Btn2->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn2->Location = System::Drawing::Point(103, 126);
			this->Btn2->Margin = System::Windows::Forms::Padding(0);
			this->Btn2->Name = L"Btn2";
			this->Btn2->Size = System::Drawing::Size(103, 63);
			this->Btn2->TabIndex = 5;
			this->Btn2->Text = L"2";
			this->Btn2->UseVisualStyleBackColor = true;
			this->Btn2->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn3
			// 
			this->Btn3->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn3->Location = System::Drawing::Point(206, 126);
			this->Btn3->Margin = System::Windows::Forms::Padding(0);
			this->Btn3->Name = L"Btn3";
			this->Btn3->Size = System::Drawing::Size(103, 63);
			this->Btn3->TabIndex = 6;
			this->Btn3->Text = L"3";
			this->Btn3->UseVisualStyleBackColor = true;
			this->Btn3->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// BtnMinus
			// 
			this->BtnMinus->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnMinus->Location = System::Drawing::Point(309, 126);
			this->BtnMinus->Margin = System::Windows::Forms::Padding(0);
			this->BtnMinus->Name = L"BtnMinus";
			this->BtnMinus->Size = System::Drawing::Size(103, 63);
			this->BtnMinus->TabIndex = 7;
			this->BtnMinus->Text = L"-";
			this->BtnMinus->UseVisualStyleBackColor = true;
			this->BtnMinus->Click += gcnew System::EventHandler(this, &FormCalculator::Operatrion_Click);
			// 
			// Btn4
			// 
			this->Btn4->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn4->Location = System::Drawing::Point(0, 189);
			this->Btn4->Margin = System::Windows::Forms::Padding(0);
			this->Btn4->Name = L"Btn4";
			this->Btn4->Size = System::Drawing::Size(103, 63);
			this->Btn4->TabIndex = 8;
			this->Btn4->Text = L"4";
			this->Btn4->UseVisualStyleBackColor = true;
			this->Btn4->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn5
			// 
			this->Btn5->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn5->Location = System::Drawing::Point(103, 189);
			this->Btn5->Margin = System::Windows::Forms::Padding(0);
			this->Btn5->Name = L"Btn5";
			this->Btn5->Size = System::Drawing::Size(103, 63);
			this->Btn5->TabIndex = 9;
			this->Btn5->Text = L"5";
			this->Btn5->UseVisualStyleBackColor = true;
			this->Btn5->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn6
			// 
			this->Btn6->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn6->Location = System::Drawing::Point(206, 189);
			this->Btn6->Margin = System::Windows::Forms::Padding(0);
			this->Btn6->Name = L"Btn6";
			this->Btn6->Size = System::Drawing::Size(103, 63);
			this->Btn6->TabIndex = 10;
			this->Btn6->Text = L"6";
			this->Btn6->UseVisualStyleBackColor = true;
			this->Btn6->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// BtnDivide
			// 
			this->BtnDivide->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnDivide->Location = System::Drawing::Point(309, 189);
			this->BtnDivide->Margin = System::Windows::Forms::Padding(0);
			this->BtnDivide->Name = L"BtnDivide";
			this->BtnDivide->Size = System::Drawing::Size(103, 63);
			this->BtnDivide->TabIndex = 11;
			this->BtnDivide->Text = L"÷";
			this->BtnDivide->UseVisualStyleBackColor = true;
			this->BtnDivide->Click += gcnew System::EventHandler(this, &FormCalculator::Operatrion_Click);
			// 
			// Btn7
			// 
			this->Btn7->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn7->Location = System::Drawing::Point(0, 252);
			this->Btn7->Margin = System::Windows::Forms::Padding(0);
			this->Btn7->Name = L"Btn7";
			this->Btn7->Size = System::Drawing::Size(103, 63);
			this->Btn7->TabIndex = 12;
			this->Btn7->Text = L"7";
			this->Btn7->UseVisualStyleBackColor = true;
			this->Btn7->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn8
			// 
			this->Btn8->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn8->Location = System::Drawing::Point(103, 252);
			this->Btn8->Margin = System::Windows::Forms::Padding(0);
			this->Btn8->Name = L"Btn8";
			this->Btn8->Size = System::Drawing::Size(103, 63);
			this->Btn8->TabIndex = 13;
			this->Btn8->Text = L"8";
			this->Btn8->UseVisualStyleBackColor = true;
			this->Btn8->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn9
			// 
			this->Btn9->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn9->Location = System::Drawing::Point(206, 252);
			this->Btn9->Margin = System::Windows::Forms::Padding(0);
			this->Btn9->Name = L"Btn9";
			this->Btn9->Size = System::Drawing::Size(103, 63);
			this->Btn9->TabIndex = 14;
			this->Btn9->Text = L"9";
			this->Btn9->UseVisualStyleBackColor = true;
			this->Btn9->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// BtnMulitple
			// 
			this->BtnMulitple->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnMulitple->Location = System::Drawing::Point(309, 252);
			this->BtnMulitple->Margin = System::Windows::Forms::Padding(0);
			this->BtnMulitple->Name = L"BtnMulitple";
			this->BtnMulitple->Size = System::Drawing::Size(103, 63);
			this->BtnMulitple->TabIndex = 15;
			this->BtnMulitple->Text = L"×";
			this->BtnMulitple->UseVisualStyleBackColor = true;
			this->BtnMulitple->Click += gcnew System::EventHandler(this, &FormCalculator::Operatrion_Click);
			// 
			// Btn0
			// 
			this->Btn0->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn0->Location = System::Drawing::Point(0, 315);
			this->Btn0->Margin = System::Windows::Forms::Padding(0);
			this->Btn0->Name = L"Btn0";
			this->Btn0->Size = System::Drawing::Size(103, 63);
			this->Btn0->TabIndex = 16;
			this->Btn0->Text = L"0";
			this->Btn0->UseVisualStyleBackColor = true;
			this->Btn0->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// BtnDot
			// 
			this->BtnDot->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnDot->Location = System::Drawing::Point(103, 315);
			this->BtnDot->Margin = System::Windows::Forms::Padding(0);
			this->BtnDot->Name = L"BtnDot";
			this->BtnDot->Size = System::Drawing::Size(103, 63);
			this->BtnDot->TabIndex = 18;
			this->BtnDot->Text = L".";
			this->BtnDot->UseVisualStyleBackColor = true;
			this->BtnDot->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// BtnEqual
			// 
			this->BtnEqual->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnEqual->Location = System::Drawing::Point(206, 315);
			this->BtnEqual->Margin = System::Windows::Forms::Padding(0);
			this->BtnEqual->Name = L"BtnEqual";
			this->BtnEqual->Size = System::Drawing::Size(206, 63);
			this->BtnEqual->TabIndex = 19;
			this->BtnEqual->Text = L"=";
			this->BtnEqual->UseVisualStyleBackColor = true;
			this->BtnEqual->Click += gcnew System::EventHandler(this, &FormCalculator::BtnEqual_Click);
			// 
			// DataGrid
			// 
			this->DataGrid->AllowUserToAddRows = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->DataGrid->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->DataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->DataGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->CalcHistory });
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->DataGrid->DefaultCellStyle = dataGridViewCellStyle2;
			this->DataGrid->Dock = System::Windows::Forms::DockStyle::Top;
			this->DataGrid->Location = System::Drawing::Point(0, 0);
			this->DataGrid->Margin = System::Windows::Forms::Padding(0);
			this->DataGrid->Name = L"DataGrid";
			this->DataGrid->RowHeadersVisible = false;
			this->DataGrid->RowTemplate->Height = 21;
			this->DataGrid->Size = System::Drawing::Size(418, 98);
			this->DataGrid->TabIndex = 23;
			// 
			// CalcHistory
			// 
			this->CalcHistory->HeaderText = L"計算履歴";
			this->CalcHistory->Name = L"CalcHistory";
			this->CalcHistory->Width = 395;
			// 
			// FormCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(418, 626);
			this->Controls->Add(this->BaseSplitContainer);
			this->Name = L"FormCalculator";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormCalculator";
			this->Load += gcnew System::EventHandler(this, &FormCalculator::FormCalculator_Load);
			this->BaseSplitContainer->Panel1->ResumeLayout(false);
			this->BaseSplitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BaseSplitContainer))->EndInit();
			this->BaseSplitContainer->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBox))->EndInit();
			this->flowLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->DataGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		String^ UserInput = String::Empty;
		String^ SaveFilePath = "calc.txt";
		//生成イベント
		//数字ボタンクリック
		System::Void Number_Click(System::Object^ sender, System::EventArgs^ e);

		//オペレーションクリック
		System::Void Operatrion_Click(System::Object^ sender, System::EventArgs^ e);

		//クリアボタンクリックイベント
		System::Void btnClear_Click(System::Object^ sender, System::EventArgs^ e);

		//AllClearボタンクリックイベント
		System::Void BtnAllClear_Click(System::Object^ sender, System::EventArgs^ e);

		//イコールクリック
		System::Void BtnEqual_Click(System::Object^ sender, System::EventArgs^ e);

		//ユーザ作成イベント
		//計算結果出力
		System::Void SetCalcLine(String^ value);

		//文字列計算
		//(1*2-9)/2の計算処理をまとめて行う

		//中身は考えずそのまま使うか、
		//変数作成し単一式ごとの計算処理にするか
		double Evaluate(String^ expr)
		{
			Generic::Stack<String^>^ stack = gcnew Generic::Stack<String^>();

			String^ value = "";
			for (int i = 0; i < expr->Length; i++)
			{
				String^ s = expr->Substring(i, 1);
				char chr = (char)s->ToCharArray()[0];

				if (!Char::IsDigit(chr) && chr != '.' && value != "")
				{
					stack->Push(value);
					value = "";
				}

				if (s->Equals("(")) {

					String^ innerExp = "";
					i++;
					int bracketCount = 0;
					for (; i < expr->Length; i++)
					{
						s = expr->Substring(i, 1);

						if (s->Equals("("))
							bracketCount++;

						if (s->Equals(")"))
							if (bracketCount == 0)
								break;
							else
								bracketCount--;


						innerExp += s;
					}

					stack->Push(Evaluate(innerExp).ToString());

				}
				else if (s->Equals("+")) stack->Push(s);
				else if (s->Equals("-")) stack->Push(s);
				else if (s->Equals("*")) stack->Push(s);
				else if (s->Equals("/")) stack->Push(s);
				else if (s->Equals(")"))
				{
				}
				else if (Char::IsDigit(chr) || chr == '.')
				{
					value += s;

					if (value->Split('.')->Length > 2)
						throw gcnew Exception("Invalid decimal.");

					if (i == (expr->Length - 1))
						stack->Push(value);

				}
				else
					throw gcnew Exception("Invalid character.");
			}


			double result = 0;
			while (stack->Count >= 3)
			{

				double right = Convert::ToDouble(stack->Pop());
				String^ op = stack->Pop();
				double left = Convert::ToDouble(stack->Pop());

				if (op == "+") result = left + right;
				else if (op == "+") result = left + right;
				else if (op == "-") result = left - right;
				else if (op == "*") result = left * right;
				else if (op == "/") result = left / right;

				stack->Push(result.ToString());
			}


			return Convert::ToDouble(stack->Pop());
		}

		System::Void FormCalculator_Load(System::Object^ sender, System::EventArgs^ e)
		{
			//以前保存されたファイルが存在する場合
			if (System::IO::File::Exists(SaveFilePath))
			{
				Windows::Forms::DialogResult result;
				result = MessageBox::Show("以前のデータがありますが開きますか", "Question", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);

				if (result == Windows::Forms::DialogResult::OK)
				{
					//ファイル読み込む呪文
					System::IO::StreamReader^ sr = gcnew System::IO::StreamReader(SaveFilePath);

					//最終行まで一行ずつ読み込む呪文
					while (!sr->EndOfStream)
					{
						String^ line = sr->ReadLine();
						if (line != "")
						{
							//グリッドに一行追加
							DataGrid->Rows->Add();

							//グリッドの一番下の行にラップタイムを表示
							DataGrid->Rows[DataGrid->RowCount - 1]->Cells[0]->Value = line;
						}
					}

					sr->Close();

					//完了ダイアログ表示
					MessageBox::Show("読み込み完了", "Information", MessageBoxButtons::OK, MessageBoxIcon::Information);

					SetCalcLine("0");
				}
				else
				{
					SetCalcLine("0");
				}
			}			
		}

		System::Void BtnSave_Click(System::Object^ sender, System::EventArgs^ e);
	};
}