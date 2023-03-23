#pragma once
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace RLE {

	/// <summary>
	/// Сводка для PageFile
	/// </summary>
	public ref class PageFile : public System::Windows::Forms::UserControl
	{
	public:
		PageFile(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			openFileDialog1->Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PageFile()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ ImagePanel1;
	private: System::Windows::Forms::Panel^ ImagePanel2;



	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;


	protected:

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
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->ImagePanel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->ImagePanel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->ImagePanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->ImagePanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Calibri", 16));
			this->button1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button1->Location = System::Drawing::Point(275, 389);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(188, 52);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Open";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// ImagePanel1
			// 
			this->ImagePanel1->BackColor = System::Drawing::SystemColors::Control;
			this->ImagePanel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ImagePanel1->Controls->Add(this->pictureBox1);
			this->ImagePanel1->Location = System::Drawing::Point(19, 24);
			this->ImagePanel1->Name = L"ImagePanel1";
			this->ImagePanel1->Size = System::Drawing::Size(310, 306);
			this->ImagePanel1->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(308, 304);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &PageFile::pictureBox1_Click);
			// 
			// ImagePanel2
			// 
			this->ImagePanel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->ImagePanel2->Controls->Add(this->pictureBox2);
			this->ImagePanel2->Location = System::Drawing::Point(401, 23);
			this->ImagePanel2->Name = L"ImagePanel2";
			this->ImagePanel2->Size = System::Drawing::Size(310, 306);
			this->ImagePanel2->TabIndex = 3;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox2->Location = System::Drawing::Point(0, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(308, 304);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &PageFile::pictureBox2_Click);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(68, 346);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(607, 23);
			this->progressBar1->TabIndex = 4;
			// 
			// PageFile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->ImagePanel2);
			this->Controls->Add(this->ImagePanel1);
			this->Controls->Add(this->button1);
			this->Name = L"PageFile";
			this->Size = System::Drawing::Size(746, 477);
			this->ImagePanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ImagePanel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		//textBox1.Text = fileText;
		if (openFileDialog1->ShowDialog() == DialogResult::OK)
		{
			// получаем выбранный файл
			String^ filename = openFileDialog1->FileName;
			pictureBox1->Image = Image::FromFile(filename);
		}
	}

	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
		//textBox1.Text = fileText;
		if (openFileDialog1->ShowDialog() == DialogResult::OK)
		{
			// получаем выбранный файл
			String^ filename = openFileDialog1->FileName;
			pictureBox2->Image = Image::FromFile(filename);
		}
	}

};
}
