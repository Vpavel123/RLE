#pragma once
#include "NavigationService.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace RLE {

	/// <summary>
	/// Сводка для PageSideBar
	/// </summary>
	public ref class PageSideBar : public System::Windows::Forms::UserControl
	{
	public:
		PageSideBar(void)
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
		~PageSideBar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel2;
	protected:
	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::RadioButton^ radioButton5;
	private: System::Windows::Forms::RadioButton^ radioButton4;

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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->radioButton6);
			this->panel2->Controls->Add(this->radioButton5);
			this->panel2->Controls->Add(this->radioButton4);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(236, 529);
			this->panel2->TabIndex = 5;
			// 
			// radioButton6
			// 
			this->radioButton6->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton6->AutoSize = true;
			this->radioButton6->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->radioButton6->Dock = System::Windows::Forms::DockStyle::Top;
			this->radioButton6->FlatAppearance->BorderSize = 0;
			this->radioButton6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton6->Font = (gcnew System::Drawing::Font(L"Calibri", 24));
			this->radioButton6->Location = System::Drawing::Point(0, 118);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(236, 59);
			this->radioButton6->TabIndex = 8;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"Exit";
			this->radioButton6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->radioButton6->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->radioButton6->UseVisualStyleBackColor = false;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &PageSideBar::radioButton6_CheckedChanged);
			// 
			// radioButton5
			// 
			this->radioButton5->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton5->AutoSize = true;
			this->radioButton5->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->radioButton5->Dock = System::Windows::Forms::DockStyle::Top;
			this->radioButton5->FlatAppearance->BorderSize = 0;
			this->radioButton5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton5->Font = (gcnew System::Drawing::Font(L"Calibri", 24));
			this->radioButton5->Location = System::Drawing::Point(0, 59);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(236, 59);
			this->radioButton5->TabIndex = 7;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Send";
			this->radioButton5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->radioButton5->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->radioButton5->UseVisualStyleBackColor = false;
			// 
			// radioButton4
			// 
			this->radioButton4->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton4->AutoSize = true;
			this->radioButton4->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->radioButton4->Dock = System::Windows::Forms::DockStyle::Top;
			this->radioButton4->FlatAppearance->BorderSize = 0;
			this->radioButton4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Calibri", 24));
			this->radioButton4->Location = System::Drawing::Point(0, 0);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(236, 59);
			this->radioButton4->TabIndex = 5;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"General";
			this->radioButton4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->radioButton4->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->radioButton4->UseVisualStyleBackColor = false;
			this->radioButton4->Enter += gcnew System::EventHandler(this, &PageSideBar::radioButton4_Enter);
			// 
			// PageSideBar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->panel2);
			this->Name = L"PageSideBar";
			this->Size = System::Drawing::Size(236, 529);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void radioButton6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void radioButton4_Enter(System::Object^ sender, System::EventArgs^ e) {
		//NavigationService::getInstance()->Navigate(gcnew PageGeneral(), );
	}

};
}
