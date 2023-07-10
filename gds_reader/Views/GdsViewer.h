#pragma once

namespace gdsreader {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace System::Configuration;


	/// <summary>
	/// GdsViewer の概要
	/// </summary>
	public ref class GdsViewer : public System::Windows::Forms::Form
	{
	public:
		GdsViewer(void)
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
		~GdsViewer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::Button^ Btn_Start;
	private: System::Windows::Forms::TextBox^ Tb_FilePath;
	private: System::Windows::Forms::PictureBox^ PicBox;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::Button^ Btn_Down;
	private: System::Windows::Forms::Button^ Btn_Left;
	private: System::Windows::Forms::Button^ Btn_Right;
	private: System::Windows::Forms::Button^ Btn_Up;
	private: System::Windows::Forms::Button^ Btn_Out;
	private: System::Windows::Forms::Button^ Btn_In;

	private: System::Windows::Forms::ComboBox^ Cob_SelectLayer;
	private: System::Windows::Forms::Button^ Btn_Do;
	protected:



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
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->Btn_Start = (gcnew System::Windows::Forms::Button());
			this->Tb_FilePath = (gcnew System::Windows::Forms::TextBox());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->Btn_Do = (gcnew System::Windows::Forms::Button());
			this->Cob_SelectLayer = (gcnew System::Windows::Forms::ComboBox());
			this->Btn_Out = (gcnew System::Windows::Forms::Button());
			this->Btn_In = (gcnew System::Windows::Forms::Button());
			this->Btn_Down = (gcnew System::Windows::Forms::Button());
			this->Btn_Left = (gcnew System::Windows::Forms::Button());
			this->Btn_Right = (gcnew System::Windows::Forms::Button());
			this->Btn_Up = (gcnew System::Windows::Forms::Button());
			this->PicBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBox))->BeginInit();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->splitContainer1->IsSplitterFixed = true;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->Btn_Start);
			this->splitContainer1->Panel1->Controls->Add(this->Tb_FilePath);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Size = System::Drawing::Size(954, 607);
			this->splitContainer1->SplitterDistance = 36;
			this->splitContainer1->TabIndex = 0;
			// 
			// Btn_Start
			// 
			this->Btn_Start->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Btn_Start->FlatAppearance->BorderColor = System::Drawing::Color::Gray;
			this->Btn_Start->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Btn_Start->Location = System::Drawing::Point(871, 3);
			this->Btn_Start->Name = L"Btn_Start";
			this->Btn_Start->Size = System::Drawing::Size(75, 28);
			this->Btn_Start->TabIndex = 1;
			this->Btn_Start->Text = L"開始";
			this->Btn_Start->UseVisualStyleBackColor = true;
			this->Btn_Start->Click += gcnew System::EventHandler(this, &GdsViewer::Btn_Start_Click);
			// 
			// Tb_FilePath
			// 
			this->Tb_FilePath->AllowDrop = true;
			this->Tb_FilePath->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->Tb_FilePath->Location = System::Drawing::Point(0, 8);
			this->Tb_FilePath->Name = L"Tb_FilePath";
			this->Tb_FilePath->Size = System::Drawing::Size(865, 19);
			this->Tb_FilePath->TabIndex = 0;
			this->Tb_FilePath->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &GdsViewer::Tb_FilePath_DragDrop);
			this->Tb_FilePath->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &GdsViewer::Tb_FilePath_DragEnter);
			// 
			// splitContainer2
			// 
			this->splitContainer2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->splitContainer2->IsSplitterFixed = true;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->Btn_Do);
			this->splitContainer2->Panel1->Controls->Add(this->Cob_SelectLayer);
			this->splitContainer2->Panel1->Controls->Add(this->Btn_Out);
			this->splitContainer2->Panel1->Controls->Add(this->Btn_In);
			this->splitContainer2->Panel1->Controls->Add(this->Btn_Down);
			this->splitContainer2->Panel1->Controls->Add(this->Btn_Left);
			this->splitContainer2->Panel1->Controls->Add(this->Btn_Right);
			this->splitContainer2->Panel1->Controls->Add(this->Btn_Up);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->PicBox);
			this->splitContainer2->Size = System::Drawing::Size(954, 567);
			this->splitContainer2->SplitterDistance = 150;
			this->splitContainer2->TabIndex = 1;
			// 
			// Btn_Do
			// 
			this->Btn_Do->Location = System::Drawing::Point(6, 9);
			this->Btn_Do->Name = L"Btn_Do";
			this->Btn_Do->Size = System::Drawing::Size(137, 36);
			this->Btn_Do->TabIndex = 7;
			this->Btn_Do->Text = L"実行";
			this->Btn_Do->UseVisualStyleBackColor = true;
			this->Btn_Do->Click += gcnew System::EventHandler(this, &GdsViewer::Btn_Do_Click);
			// 
			// Cob_SelectLayer
			// 
			this->Cob_SelectLayer->FormattingEnabled = true;
			this->Cob_SelectLayer->Location = System::Drawing::Point(6, 51);
			this->Cob_SelectLayer->Name = L"Cob_SelectLayer";
			this->Cob_SelectLayer->Size = System::Drawing::Size(137, 20);
			this->Cob_SelectLayer->TabIndex = 6;
			// 
			// Btn_Out
			// 
			this->Btn_Out->Location = System::Drawing::Point(76, 514);
			this->Btn_Out->Name = L"Btn_Out";
			this->Btn_Out->Size = System::Drawing::Size(67, 36);
			this->Btn_Out->TabIndex = 5;
			this->Btn_Out->Text = L"ZoomOut";
			this->Btn_Out->UseVisualStyleBackColor = true;
			// 
			// Btn_In
			// 
			this->Btn_In->Location = System::Drawing::Point(6, 514);
			this->Btn_In->Name = L"Btn_In";
			this->Btn_In->Size = System::Drawing::Size(67, 36);
			this->Btn_In->TabIndex = 4;
			this->Btn_In->Text = L"ZoomIn";
			this->Btn_In->UseVisualStyleBackColor = true;
			// 
			// Btn_Down
			// 
			this->Btn_Down->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn_Down->Location = System::Drawing::Point(51, 457);
			this->Btn_Down->Name = L"Btn_Down";
			this->Btn_Down->Size = System::Drawing::Size(45, 34);
			this->Btn_Down->TabIndex = 3;
			this->Btn_Down->Text = L"↓";
			this->Btn_Down->UseVisualStyleBackColor = true;
			// 
			// Btn_Left
			// 
			this->Btn_Left->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn_Left->Location = System::Drawing::Point(6, 417);
			this->Btn_Left->Name = L"Btn_Left";
			this->Btn_Left->Size = System::Drawing::Size(45, 34);
			this->Btn_Left->TabIndex = 2;
			this->Btn_Left->Text = L"←";
			this->Btn_Left->UseVisualStyleBackColor = true;
			// 
			// Btn_Right
			// 
			this->Btn_Right->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn_Right->Location = System::Drawing::Point(98, 417);
			this->Btn_Right->Name = L"Btn_Right";
			this->Btn_Right->Size = System::Drawing::Size(45, 34);
			this->Btn_Right->TabIndex = 1;
			this->Btn_Right->Text = L"→";
			this->Btn_Right->UseVisualStyleBackColor = true;
			// 
			// Btn_Up
			// 
			this->Btn_Up->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->Btn_Up->Location = System::Drawing::Point(51, 377);
			this->Btn_Up->Name = L"Btn_Up";
			this->Btn_Up->Size = System::Drawing::Size(45, 34);
			this->Btn_Up->TabIndex = 0;
			this->Btn_Up->Text = L"↑";
			this->Btn_Up->UseVisualStyleBackColor = true;
			// 
			// PicBox
			// 
			this->PicBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->PicBox->Location = System::Drawing::Point(0, 0);
			this->PicBox->Name = L"PicBox";
			this->PicBox->Size = System::Drawing::Size(798, 565);
			this->PicBox->TabIndex = 0;
			this->PicBox->TabStop = false;
			// 
			// GdsViewer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(954, 607);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"GdsViewer";
			this->Text = L"GdsViewer";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		String^ GdsFile = String::Empty;
		List<Geometry::GdsPolygons^>^ poly_set = gcnew List<Geometry::GdsPolygons^>();
		List<array<Geometry::UPoint^>^>^ Polygons = gcnew List<array<Geometry::UPoint^>^>();

		int DisplayLayer = 0;
		int TOP_POSITION = 50;
		int LEFT_POSITION = 50;
		double SCALE = 10.0;

	private: System::Void Tb_FilePath_DragDrop(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
	private: System::Void Tb_FilePath_DragEnter(System::Object^ sender, System::Windows::Forms::DragEventArgs^ e);
	private: System::Void Btn_Start_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DrawPath(List<array<Geometry::UPoint^>^>^ polygons);
	private: System::Void Btn_Do_Click(System::Object^ sender, System::EventArgs^ e);
};
}
