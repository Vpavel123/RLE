#pragma once
#include "PageGeneral.h"
#include "PageSideBar.h"
#include "PageAnalysis.h"
#include "PageFile.h"
#include "NavigationService.h"

namespace RLE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainApp
	/// </summary>
	public ref class MainApp : public System::Windows::Forms::Form
	{
	public:
		PageAnalysis^ Analysis;
		PageFile^ file;
		PageGeneral^ general;

		MainApp(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//

			general = gcnew PageGeneral();
			file = gcnew PageFile(general);
			Analysis = gcnew PageAnalysis(file);

			this->radioButton1->FlatAppearance->MouseOverBackColor = System::Drawing::Color().FromArgb(33, 150, 243);
			this->radioButton4->FlatAppearance->MouseOverBackColor = System::Drawing::Color().FromArgb(33, 150, 243);
			this->radioButton6->FlatAppearance->MouseOverBackColor = System::Drawing::Color().FromArgb(33, 150, 243);

			this->radioButton1->FlatAppearance->CheckedBackColor = System::Drawing::Color().FromArgb(33, 150, 243);
			this->radioButton4->FlatAppearance->CheckedBackColor = System::Drawing::Color().FromArgb(33, 150, 243);
			this->radioButton6->FlatAppearance->CheckedBackColor = System::Drawing::Color().FromArgb(33, 150, 243);

			this->radioButton1->Image = Image::FromFile("Image/file_30px.png");
			this->radioButton4->Image = Image::FromFile("Image/settings_30px.png");
			this->radioButton6->Image = Image::FromFile("Image/graph_30px.png");
			this->ExitButton->Image = Image::FromFile("Image/close_30px.png");

			this->panel1->BackColor = System::Drawing::Color().FromArgb(33, 150, 243);
			this->panel2->BackColor = System::Drawing::Color().FromArgb(24, 105, 169);
			this->panel3->BackColor = System::Drawing::Color().FromArgb(51, 51, 77);
			this->SideBarPanel->BackColor = System::Drawing::Color().FromArgb(51, 51, 77);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainApp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ SideBarPanel;
	private: System::Windows::Forms::Panel^ PagePanelControl;





	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::RadioButton^ radioButton6;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton5;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::Button^ ExitButton;














	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainApp::typeid));
			this->SideBarPanel = (gcnew System::Windows::Forms::Panel());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->PagePanelControl = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->ExitButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->SideBarPanel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// SideBarPanel
			// 
			this->SideBarPanel->BackColor = System::Drawing::SystemColors::InfoText;
			this->SideBarPanel->Controls->Add(this->radioButton4);
			this->SideBarPanel->Controls->Add(this->radioButton6);
			this->SideBarPanel->Controls->Add(this->radioButton1);
			this->SideBarPanel->Controls->Add(this->panel2);
			resources->ApplyResources(this->SideBarPanel, L"SideBarPanel");
			this->SideBarPanel->Name = L"SideBarPanel";
			// 
			// radioButton4
			// 
			resources->ApplyResources(this->radioButton4, L"radioButton4");
			this->radioButton4->BackColor = System::Drawing::Color::Transparent;
			this->radioButton4->FlatAppearance->BorderSize = 0;
			this->radioButton4->ForeColor = System::Drawing::SystemColors::Control;
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->UseVisualStyleBackColor = false;
			this->radioButton4->Enter += gcnew System::EventHandler(this, &MainApp::radioButton4_Enter);
			// 
			// radioButton6
			// 
			resources->ApplyResources(this->radioButton6, L"radioButton6");
			this->radioButton6->BackColor = System::Drawing::Color::Transparent;
			this->radioButton6->FlatAppearance->BorderSize = 0;
			this->radioButton6->ForeColor = System::Drawing::SystemColors::Control;
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->UseVisualStyleBackColor = false;
			this->radioButton6->Click += gcnew System::EventHandler(this, &MainApp::radioButton6_Click);
			// 
			// radioButton1
			// 
			resources->ApplyResources(this->radioButton1, L"radioButton1");
			this->radioButton1->BackColor = System::Drawing::Color::Transparent;
			this->radioButton1->FlatAppearance->BorderSize = 0;
			this->radioButton1->ForeColor = System::Drawing::SystemColors::Control;
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->Enter += gcnew System::EventHandler(this, &MainApp::radioButton1_Enter);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			resources->ApplyResources(this->panel2, L"panel2");
			this->panel2->Name = L"panel2";
			// 
			// PagePanelControl
			// 
			resources->ApplyResources(this->PagePanelControl, L"PagePanelControl");
			this->PagePanelControl->Name = L"PagePanelControl";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InfoText;
			this->panel1->Controls->Add(this->ExitButton);
			this->panel1->Controls->Add(this->label1);
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			// 
			// ExitButton
			// 
			this->ExitButton->FlatAppearance->BorderSize = 0;
			this->ExitButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->ExitButton, L"ExitButton");
			this->ExitButton->Name = L"ExitButton";
			this->ExitButton->UseVisualStyleBackColor = true;
			this->ExitButton->Click += gcnew System::EventHandler(this, &MainApp::ExitButton_Click);
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->ForeColor = System::Drawing::SystemColors::Control;
			this->label1->Name = L"label1";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::DimGray;
			resources->ApplyResources(this->panel3, L"panel3");
			this->panel3->Name = L"panel3";
			// 
			// MainApp
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->PagePanelControl);
			this->Controls->Add(this->SideBarPanel);
			this->Name = L"MainApp";
			this->Load += gcnew System::EventHandler(this, &MainApp::MainApp_Load);
			this->SideBarPanel->ResumeLayout(false);
			this->SideBarPanel->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainApp_Load(System::Object^ sender, System::EventArgs^ e) {
		NavigationService::getInstance()->Navigate("Settings", label1, general, PagePanelControl);
	}
	private: System::Void radioButton6_Click(System::Object^ sender, System::EventArgs^ e) {
		NavigationService::getInstance()->Navigate("Analysis", label1, Analysis, PagePanelControl);
	}
	private: System::Void radioButton4_Enter(System::Object^ sender, System::EventArgs^ e) {
		NavigationService::getInstance()->Navigate("Settings", label1, general, PagePanelControl);
	}	
	private: System::Void radioButton1_Enter(System::Object^ sender, System::EventArgs^ e) {
		NavigationService::getInstance()->Navigate("File", label1, file, PagePanelControl);
	}
	private: System::Void ExitButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

};
}
