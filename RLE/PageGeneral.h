#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace RLE {

	/// <summary>
	/// Сводка для PageGeneral
	/// </summary>
	public ref class PageGeneral : public System::Windows::Forms::UserControl
	{
	public:
		delegate void ComboBoxTextChangedEventHandler(System::Object^ sender, System::String^ text);
		event ComboBoxTextChangedEventHandler^ ComboBoxTextChanged;

		PageGeneral(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PageGeneral()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Label^ ColorPicker;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ ColorButton_1;
	private: System::Windows::Forms::Button^ ColorButton_2;
	private: System::Windows::Forms::Button^ ColorButton_3;



	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->ColorPicker = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->ColorButton_1 = (gcnew System::Windows::Forms::Button());
			this->ColorButton_2 = (gcnew System::Windows::Forms::Button());
			this->ColorButton_3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"RLE", L"LZW", L"Huffman compression" });
			this->comboBox2->Location = System::Drawing::Point(87, 55);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(158, 24);
			this->comboBox2->TabIndex = 1;
			this->comboBox2->Text = L"RLE";
			this->comboBox2->TextChanged += gcnew System::EventHandler(this, &PageGeneral::comboBox2_TextChanged);
			// 
			// ColorPicker
			// 
			this->ColorPicker->AutoSize = true;
			this->ColorPicker->Font = (gcnew System::Drawing::Font(L"Calibri", 16));
			this->ColorPicker->Location = System::Drawing::Point(593, 310);
			this->ColorPicker->Name = L"ColorPicker";
			this->ColorPicker->Size = System::Drawing::Size(72, 33);
			this->ColorPicker->TabIndex = 2;
			this->ColorPicker->Text = L"Color";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->ColorButton_1);
			this->flowLayoutPanel1->Controls->Add(this->ColorButton_2);
			this->flowLayoutPanel1->Controls->Add(this->ColorButton_3);
			this->flowLayoutPanel1->Controls->Add(this->button4);
			this->flowLayoutPanel1->Controls->Add(this->button5);
			this->flowLayoutPanel1->Controls->Add(this->button6);
			this->flowLayoutPanel1->Location = System::Drawing::Point(555, 355);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(157, 100);
			this->flowLayoutPanel1->TabIndex = 3;
			// 
			// ColorButton_1
			// 
			this->ColorButton_1->BackColor = System::Drawing::Color::Crimson;
			this->ColorButton_1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ColorButton_1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ColorButton_1->Location = System::Drawing::Point(3, 3);
			this->ColorButton_1->Name = L"ColorButton_1";
			this->ColorButton_1->Size = System::Drawing::Size(45, 45);
			this->ColorButton_1->TabIndex = 4;
			this->ColorButton_1->UseVisualStyleBackColor = false;
			this->ColorButton_1->Click += gcnew System::EventHandler(this, &PageGeneral::ColorButton_1_Click);
			// 
			// ColorButton_2
			// 
			this->ColorButton_2->BackColor = System::Drawing::Color::DarkViolet;
			this->ColorButton_2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ColorButton_2->Location = System::Drawing::Point(54, 3);
			this->ColorButton_2->Name = L"ColorButton_2";
			this->ColorButton_2->Size = System::Drawing::Size(45, 45);
			this->ColorButton_2->TabIndex = 5;
			this->ColorButton_2->UseVisualStyleBackColor = false;
			this->ColorButton_2->Click += gcnew System::EventHandler(this, &PageGeneral::ColorButton_2_Click);
			// 
			// ColorButton_3
			// 
			this->ColorButton_3->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->ColorButton_3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ColorButton_3->Location = System::Drawing::Point(105, 3);
			this->ColorButton_3->Name = L"ColorButton_3";
			this->ColorButton_3->Size = System::Drawing::Size(45, 45);
			this->ColorButton_3->TabIndex = 6;
			this->ColorButton_3->UseVisualStyleBackColor = false;
			this->ColorButton_3->Click += gcnew System::EventHandler(this, &PageGeneral::ColorButton_3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::SpringGreen;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(3, 54);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(45, 45);
			this->button4->TabIndex = 7;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &PageGeneral::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LightPink;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(54, 54);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(45, 45);
			this->button5->TabIndex = 8;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &PageGeneral::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::LightCoral;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Location = System::Drawing::Point(105, 54);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(45, 45);
			this->button6->TabIndex = 9;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &PageGeneral::button6_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 16));
			this->label1->Location = System::Drawing::Point(16, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(341, 33);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Another compression method";
			// 
			// PageGeneral
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->label1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->ColorPicker);
			this->Controls->Add(this->comboBox2);
			this->Name = L"PageGeneral";
			this->Size = System::Drawing::Size(746, 477);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ColorButton_1_Click(System::Object^ sender, System::EventArgs^ e) {
		Panel^ panel1 = (Panel^)this->ParentForm->Controls->Find("panel1", false)[0];
		panel1->BackColor = Color::FromArgb(229, 27, 72);
	
		Panel^ panel2 = (Panel^)this->ParentForm->Controls->Find("panel2", true)[0];
		panel2->BackColor = Color::FromArgb(212, 27, 72);
	
		Panel^ SideBarPanel = (Panel^)this->ParentForm->Controls->Find("SideBarPanel", true)[0];
		for (size_t i = 0; i < SideBarPanel->Controls->Count; i++)
		{
			RadioButton^ radio = dynamic_cast<RadioButton^>(SideBarPanel->Controls[i]);
			if (radio != nullptr)
			{
				radio->FlatAppearance->MouseOverBackColor = System::Drawing::Color().FromArgb(229, 27, 72);
				radio->FlatAppearance->CheckedBackColor = System::Drawing::Color().FromArgb(229, 27, 72);
			}
		}
	}

	private: System::Void ColorButton_2_Click(System::Object^ sender, System::EventArgs^ e) {
		Panel^ panel1 = (Panel^)this->ParentForm->Controls->Find("panel1", false)[0];
		panel1->BackColor = Color::FromArgb(95, 57, 100);
	
		Panel^ panel2 = (Panel^)this->ParentForm->Controls->Find("panel2", true)[0];
		panel2->BackColor = Color::FromArgb(95, 40, 100);
	
		Panel^ SideBarPanel = (Panel^)this->ParentForm->Controls->Find("SideBarPanel", true)[0];
		for (size_t i = 0; i < SideBarPanel->Controls->Count; i++)
		{
			RadioButton^ radio = dynamic_cast<RadioButton^>(SideBarPanel->Controls[i]);
			if (radio != nullptr)
			{
				radio->FlatAppearance->MouseOverBackColor = System::Drawing::Color().FromArgb(95, 57, 100);
				radio->FlatAppearance->CheckedBackColor = System::Drawing::Color().FromArgb(95, 57, 100);
			}
		}
	}

	private: System::Void ColorButton_3_Click(System::Object^ sender, System::EventArgs^ e) {
		Panel^ panel1 = (Panel^)this->ParentForm->Controls->Find("panel1", false)[0];
		panel1->BackColor = Color::FromArgb(33, 150, 243);

		Panel^ panel2 = (Panel^)this->ParentForm->Controls->Find("panel2", true)[0];
		panel2->BackColor = Color::FromArgb(24, 105, 169);

		Panel^ SideBarPanel = (Panel^)this->ParentForm->Controls->Find("SideBarPanel", true)[0];
		for (size_t i = 0; i < SideBarPanel->Controls->Count; i++)
		{
			RadioButton^ radio = dynamic_cast<RadioButton^>(SideBarPanel->Controls[i]);
			if (radio != nullptr)
			{
				radio->FlatAppearance->MouseOverBackColor = System::Drawing::Color().FromArgb(33, 150, 243);
				radio->FlatAppearance->CheckedBackColor = System::Drawing::Color().FromArgb(33, 150, 243);
			}
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		Panel^ panel1 = (Panel^)this->ParentForm->Controls->Find("panel1", false)[0];
		panel1->BackColor = Color::FromArgb(0, 150, 135);

		Panel^ panel2 = (Panel^)this->ParentForm->Controls->Find("panel2", true)[0];
		panel2->BackColor = Color::FromArgb(0, 105, 135);

		Panel^ SideBarPanel = (Panel^)this->ParentForm->Controls->Find("SideBarPanel", true)[0];
		for (size_t i = 0; i < SideBarPanel->Controls->Count; i++)
		{
			RadioButton^ radio = dynamic_cast<RadioButton^>(SideBarPanel->Controls[i]);
			if (radio != nullptr)
			{
				radio->FlatAppearance->MouseOverBackColor = System::Drawing::Color().FromArgb(0, 150, 135);
				radio->FlatAppearance->CheckedBackColor = System::Drawing::Color().FromArgb(0, 150, 135);
			}
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		Panel^ panel1 = (Panel^)this->ParentForm->Controls->Find("panel1", false)[0];
		panel1->BackColor = Color::FromArgb(227, 81, 130);

		Panel^ panel2 = (Panel^)this->ParentForm->Controls->Find("panel2", true)[0];
		panel2->BackColor = Color::FromArgb(210, 81, 130);

		Panel^ SideBarPanel = (Panel^)this->ParentForm->Controls->Find("SideBarPanel", true)[0];
		for (size_t i = 0; i < SideBarPanel->Controls->Count; i++)
		{
			RadioButton^ radio = dynamic_cast<RadioButton^>(SideBarPanel->Controls[i]);
			if (radio != nullptr)
			{
				radio->FlatAppearance->MouseOverBackColor = System::Drawing::Color().FromArgb(227, 81, 130);
				radio->FlatAppearance->CheckedBackColor = System::Drawing::Color().FromArgb(227, 81, 130);
			}
		}
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		Panel^ panel1 = (Panel^)this->ParentForm->Controls->Find("panel1", false)[0];
		panel1->BackColor = Color::FromArgb(230, 88, 84);

		Panel^ panel2 = (Panel^)this->ParentForm->Controls->Find("panel2", true)[0];
		panel2->BackColor = Color::FromArgb(213, 88, 84);

		Panel^ SideBarPanel = (Panel^)this->ParentForm->Controls->Find("SideBarPanel", true)[0];
		for (size_t i = 0; i < SideBarPanel->Controls->Count; i++)
		{
			RadioButton^ radio = dynamic_cast<RadioButton^>(SideBarPanel->Controls[i]);
			if (radio != nullptr)
			{
				radio->FlatAppearance->MouseOverBackColor = System::Drawing::Color().FromArgb(230, 88, 84);
				radio->FlatAppearance->CheckedBackColor = System::Drawing::Color().FromArgb(230, 88, 84);
			}
		}
	}
	private: System::Void comboBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		ComboBoxTextChanged(this, comboBox2->Text);
	}
};
}
