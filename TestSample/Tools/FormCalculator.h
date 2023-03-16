#pragma once

namespace TestSample {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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

	protected:
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
	protected:
	private: System::Windows::Forms::PictureBox^ PicBox;
	private: System::Windows::Forms::RichTextBox^ BoxRichText;
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
	private: System::Windows::Forms::Button^ BtnPercent;
	private: System::Windows::Forms::Button^ BtnAllClear;
	private: System::Windows::Forms::Button^ btnClear;
	private: System::Windows::Forms::Button^ BtnEqual;
	private: System::Windows::Forms::Button^ BtnDot;
	private: System::Windows::Forms::Button^ Btn00;
	private: System::Windows::Forms::Button^ Btn0;

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
			this->BaseSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->PicBox = (gcnew System::Windows::Forms::PictureBox());
			this->BoxRichText = (gcnew System::Windows::Forms::RichTextBox());
			this->BtnEqual = (gcnew System::Windows::Forms::Button());
			this->BtnDot = (gcnew System::Windows::Forms::Button());
			this->Btn00 = (gcnew System::Windows::Forms::Button());
			this->Btn0 = (gcnew System::Windows::Forms::Button());
			this->BtnMulitple = (gcnew System::Windows::Forms::Button());
			this->Btn9 = (gcnew System::Windows::Forms::Button());
			this->Btn8 = (gcnew System::Windows::Forms::Button());
			this->Btn7 = (gcnew System::Windows::Forms::Button());
			this->BtnDivide = (gcnew System::Windows::Forms::Button());
			this->Btn6 = (gcnew System::Windows::Forms::Button());
			this->Btn5 = (gcnew System::Windows::Forms::Button());
			this->Btn4 = (gcnew System::Windows::Forms::Button());
			this->BtnMinus = (gcnew System::Windows::Forms::Button());
			this->Btn3 = (gcnew System::Windows::Forms::Button());
			this->Btn2 = (gcnew System::Windows::Forms::Button());
			this->Btn1 = (gcnew System::Windows::Forms::Button());
			this->BtnPlus = (gcnew System::Windows::Forms::Button());
			this->BtnPercent = (gcnew System::Windows::Forms::Button());
			this->BtnAllClear = (gcnew System::Windows::Forms::Button());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BaseSplitContainer))->BeginInit();
			this->BaseSplitContainer->Panel1->SuspendLayout();
			this->BaseSplitContainer->Panel2->SuspendLayout();
			this->BaseSplitContainer->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBox))->BeginInit();
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
			this->BaseSplitContainer->Panel1->Controls->Add(this->BoxRichText);
			// 
			// BaseSplitContainer.Panel2
			// 
			this->BaseSplitContainer->Panel2->Controls->Add(this->BtnEqual);
			this->BaseSplitContainer->Panel2->Controls->Add(this->BtnDot);
			this->BaseSplitContainer->Panel2->Controls->Add(this->Btn00);
			this->BaseSplitContainer->Panel2->Controls->Add(this->Btn0);
			this->BaseSplitContainer->Panel2->Controls->Add(this->BtnMulitple);
			this->BaseSplitContainer->Panel2->Controls->Add(this->Btn9);
			this->BaseSplitContainer->Panel2->Controls->Add(this->Btn8);
			this->BaseSplitContainer->Panel2->Controls->Add(this->Btn7);
			this->BaseSplitContainer->Panel2->Controls->Add(this->BtnDivide);
			this->BaseSplitContainer->Panel2->Controls->Add(this->Btn6);
			this->BaseSplitContainer->Panel2->Controls->Add(this->Btn5);
			this->BaseSplitContainer->Panel2->Controls->Add(this->Btn4);
			this->BaseSplitContainer->Panel2->Controls->Add(this->BtnMinus);
			this->BaseSplitContainer->Panel2->Controls->Add(this->Btn3);
			this->BaseSplitContainer->Panel2->Controls->Add(this->Btn2);
			this->BaseSplitContainer->Panel2->Controls->Add(this->Btn1);
			this->BaseSplitContainer->Panel2->Controls->Add(this->BtnPlus);
			this->BaseSplitContainer->Panel2->Controls->Add(this->BtnPercent);
			this->BaseSplitContainer->Panel2->Controls->Add(this->BtnAllClear);
			this->BaseSplitContainer->Panel2->Controls->Add(this->btnClear);
			this->BaseSplitContainer->Size = System::Drawing::Size(413, 569);
			this->BaseSplitContainer->SplitterDistance = 241;
			this->BaseSplitContainer->TabIndex = 0;
			// 
			// PicBox
			// 
			this->PicBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PicBox->Location = System::Drawing::Point(0, 63);
			this->PicBox->Name = L"PicBox";
			this->PicBox->Size = System::Drawing::Size(413, 178);
			this->PicBox->TabIndex = 1;
			this->PicBox->TabStop = false;
			// 
			// BoxRichText
			// 
			this->BoxRichText->Dock = System::Windows::Forms::DockStyle::Top;
			this->BoxRichText->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BoxRichText->Location = System::Drawing::Point(0, 0);
			this->BoxRichText->Name = L"BoxRichText";
			this->BoxRichText->ReadOnly = true;
			this->BoxRichText->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->BoxRichText->Size = System::Drawing::Size(413, 63);
			this->BoxRichText->TabIndex = 0;
			this->BoxRichText->Text = L"";
			// 
			// BtnEqual
			// 
			this->BtnEqual->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnEqual->Location = System::Drawing::Point(309, 258);
			this->BtnEqual->Margin = System::Windows::Forms::Padding(0);
			this->BtnEqual->Name = L"BtnEqual";
			this->BtnEqual->Size = System::Drawing::Size(103, 63);
			this->BtnEqual->TabIndex = 19;
			this->BtnEqual->Text = L"=";
			this->BtnEqual->UseVisualStyleBackColor = true;
			this->BtnEqual->Click += gcnew System::EventHandler(this, &FormCalculator::BtnEqual_Click);
			// 
			// BtnDot
			// 
			this->BtnDot->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnDot->Location = System::Drawing::Point(206, 258);
			this->BtnDot->Margin = System::Windows::Forms::Padding(0);
			this->BtnDot->Name = L"BtnDot";
			this->BtnDot->Size = System::Drawing::Size(103, 63);
			this->BtnDot->TabIndex = 18;
			this->BtnDot->Text = L".";
			this->BtnDot->UseVisualStyleBackColor = true;
			this->BtnDot->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn00
			// 
			this->Btn00->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn00->Location = System::Drawing::Point(103, 258);
			this->Btn00->Margin = System::Windows::Forms::Padding(0);
			this->Btn00->Name = L"Btn00";
			this->Btn00->Size = System::Drawing::Size(103, 63);
			this->Btn00->TabIndex = 17;
			this->Btn00->Text = L"00";
			this->Btn00->UseVisualStyleBackColor = true;
			this->Btn00->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn0
			// 
			this->Btn0->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn0->Location = System::Drawing::Point(0, 258);
			this->Btn0->Margin = System::Windows::Forms::Padding(0);
			this->Btn0->Name = L"Btn0";
			this->Btn0->Size = System::Drawing::Size(103, 63);
			this->Btn0->TabIndex = 16;
			this->Btn0->Text = L"0";
			this->Btn0->UseVisualStyleBackColor = true;
			this->Btn0->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// BtnMulitple
			// 
			this->BtnMulitple->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnMulitple->Location = System::Drawing::Point(309, 195);
			this->BtnMulitple->Margin = System::Windows::Forms::Padding(0);
			this->BtnMulitple->Name = L"BtnMulitple";
			this->BtnMulitple->Size = System::Drawing::Size(103, 63);
			this->BtnMulitple->TabIndex = 15;
			this->BtnMulitple->Text = L"×";
			this->BtnMulitple->UseVisualStyleBackColor = true;
			this->BtnMulitple->Click += gcnew System::EventHandler(this, &FormCalculator::Operatrion_Click);
			// 
			// Btn9
			// 
			this->Btn9->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn9->Location = System::Drawing::Point(206, 195);
			this->Btn9->Margin = System::Windows::Forms::Padding(0);
			this->Btn9->Name = L"Btn9";
			this->Btn9->Size = System::Drawing::Size(103, 63);
			this->Btn9->TabIndex = 14;
			this->Btn9->Text = L"9";
			this->Btn9->UseVisualStyleBackColor = true;
			this->Btn9->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn8
			// 
			this->Btn8->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn8->Location = System::Drawing::Point(103, 195);
			this->Btn8->Margin = System::Windows::Forms::Padding(0);
			this->Btn8->Name = L"Btn8";
			this->Btn8->Size = System::Drawing::Size(103, 63);
			this->Btn8->TabIndex = 13;
			this->Btn8->Text = L"8";
			this->Btn8->UseVisualStyleBackColor = true;
			this->Btn8->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn7
			// 
			this->Btn7->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn7->Location = System::Drawing::Point(0, 195);
			this->Btn7->Margin = System::Windows::Forms::Padding(0);
			this->Btn7->Name = L"Btn7";
			this->Btn7->Size = System::Drawing::Size(103, 63);
			this->Btn7->TabIndex = 12;
			this->Btn7->Text = L"7";
			this->Btn7->UseVisualStyleBackColor = true;
			this->Btn7->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// BtnDivide
			// 
			this->BtnDivide->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnDivide->Location = System::Drawing::Point(309, 132);
			this->BtnDivide->Margin = System::Windows::Forms::Padding(0);
			this->BtnDivide->Name = L"BtnDivide";
			this->BtnDivide->Size = System::Drawing::Size(103, 63);
			this->BtnDivide->TabIndex = 11;
			this->BtnDivide->Text = L"÷";
			this->BtnDivide->UseVisualStyleBackColor = true;
			this->BtnDivide->Click += gcnew System::EventHandler(this, &FormCalculator::Operatrion_Click);
			// 
			// Btn6
			// 
			this->Btn6->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn6->Location = System::Drawing::Point(206, 132);
			this->Btn6->Margin = System::Windows::Forms::Padding(0);
			this->Btn6->Name = L"Btn6";
			this->Btn6->Size = System::Drawing::Size(103, 63);
			this->Btn6->TabIndex = 10;
			this->Btn6->Text = L"6";
			this->Btn6->UseVisualStyleBackColor = true;
			this->Btn6->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn5
			// 
			this->Btn5->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn5->Location = System::Drawing::Point(103, 132);
			this->Btn5->Margin = System::Windows::Forms::Padding(0);
			this->Btn5->Name = L"Btn5";
			this->Btn5->Size = System::Drawing::Size(103, 63);
			this->Btn5->TabIndex = 9;
			this->Btn5->Text = L"5";
			this->Btn5->UseVisualStyleBackColor = true;
			this->Btn5->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn4
			// 
			this->Btn4->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn4->Location = System::Drawing::Point(0, 132);
			this->Btn4->Margin = System::Windows::Forms::Padding(0);
			this->Btn4->Name = L"Btn4";
			this->Btn4->Size = System::Drawing::Size(103, 63);
			this->Btn4->TabIndex = 8;
			this->Btn4->Text = L"4";
			this->Btn4->UseVisualStyleBackColor = true;
			this->Btn4->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// BtnMinus
			// 
			this->BtnMinus->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnMinus->Location = System::Drawing::Point(309, 69);
			this->BtnMinus->Margin = System::Windows::Forms::Padding(0);
			this->BtnMinus->Name = L"BtnMinus";
			this->BtnMinus->Size = System::Drawing::Size(103, 63);
			this->BtnMinus->TabIndex = 7;
			this->BtnMinus->Text = L"-";
			this->BtnMinus->UseVisualStyleBackColor = true;
			this->BtnMinus->Click += gcnew System::EventHandler(this, &FormCalculator::Operatrion_Click);
			// 
			// Btn3
			// 
			this->Btn3->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn3->Location = System::Drawing::Point(206, 69);
			this->Btn3->Margin = System::Windows::Forms::Padding(0);
			this->Btn3->Name = L"Btn3";
			this->Btn3->Size = System::Drawing::Size(103, 63);
			this->Btn3->TabIndex = 6;
			this->Btn3->Text = L"3";
			this->Btn3->UseVisualStyleBackColor = true;
			this->Btn3->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn2
			// 
			this->Btn2->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn2->Location = System::Drawing::Point(103, 69);
			this->Btn2->Margin = System::Windows::Forms::Padding(0);
			this->Btn2->Name = L"Btn2";
			this->Btn2->Size = System::Drawing::Size(103, 63);
			this->Btn2->TabIndex = 5;
			this->Btn2->Text = L"2";
			this->Btn2->UseVisualStyleBackColor = true;
			this->Btn2->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// Btn1
			// 
			this->Btn1->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn1->Location = System::Drawing::Point(0, 69);
			this->Btn1->Margin = System::Windows::Forms::Padding(0);
			this->Btn1->Name = L"Btn1";
			this->Btn1->Size = System::Drawing::Size(103, 63);
			this->Btn1->TabIndex = 4;
			this->Btn1->Text = L"1";
			this->Btn1->UseVisualStyleBackColor = true;
			this->Btn1->Click += gcnew System::EventHandler(this, &FormCalculator::Number_Click);
			// 
			// BtnPlus
			// 
			this->BtnPlus->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnPlus->Location = System::Drawing::Point(309, 6);
			this->BtnPlus->Margin = System::Windows::Forms::Padding(0);
			this->BtnPlus->Name = L"BtnPlus";
			this->BtnPlus->Size = System::Drawing::Size(103, 63);
			this->BtnPlus->TabIndex = 3;
			this->BtnPlus->Text = L"+";
			this->BtnPlus->UseVisualStyleBackColor = true;
			this->BtnPlus->Click += gcnew System::EventHandler(this, &FormCalculator::Operatrion_Click);
			// 
			// BtnPercent
			// 
			this->BtnPercent->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnPercent->Location = System::Drawing::Point(206, 6);
			this->BtnPercent->Margin = System::Windows::Forms::Padding(0);
			this->BtnPercent->Name = L"BtnPercent";
			this->BtnPercent->Size = System::Drawing::Size(103, 63);
			this->BtnPercent->TabIndex = 2;
			this->BtnPercent->Text = L"%";
			this->BtnPercent->UseVisualStyleBackColor = true;
			this->BtnPercent->Click += gcnew System::EventHandler(this, &FormCalculator::Operatrion_Click);
			// 
			// BtnAllClear
			// 
			this->BtnAllClear->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->BtnAllClear->Location = System::Drawing::Point(103, 6);
			this->BtnAllClear->Margin = System::Windows::Forms::Padding(0);
			this->BtnAllClear->Name = L"BtnAllClear";
			this->BtnAllClear->Size = System::Drawing::Size(103, 63);
			this->BtnAllClear->TabIndex = 1;
			this->BtnAllClear->Text = L"AC";
			this->BtnAllClear->UseVisualStyleBackColor = true;
			this->BtnAllClear->Click += gcnew System::EventHandler(this, &FormCalculator::BtnAllClear_Click);
			// 
			// btnClear
			// 
			this->btnClear->Font = (gcnew System::Drawing::Font(L"ＭＳ ゴシック", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->btnClear->Location = System::Drawing::Point(0, 6);
			this->btnClear->Margin = System::Windows::Forms::Padding(0);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(103, 63);
			this->btnClear->TabIndex = 0;
			this->btnClear->Text = L"C";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &FormCalculator::btnClear_Click);
			// 
			// FormCalculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(413, 569);
			this->Controls->Add(this->BaseSplitContainer);
			this->Name = L"FormCalculator";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormCalculator";
			this->BaseSplitContainer->Panel1->ResumeLayout(false);
			this->BaseSplitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BaseSplitContainer))->EndInit();
			this->BaseSplitContainer->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		double Value;
		String^ Operator = String::Empty;
		bool Check = false;
		String^ ResultText = "0";

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
		//文字列を追加し続ける
		System::Void SetCalcLine(String^ value);
	};
}
