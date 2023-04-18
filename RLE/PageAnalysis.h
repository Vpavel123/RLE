#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include "PageFile.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace RLE {
	/// <summary>
	/// Сводка для PageAnalysis
	/// </summary>
	public ref class PageAnalysis : public System::Windows::Forms::UserControl
	{
	public:
		PageFile^ file;

		void AddNumber(long rle, long lzw, long huffman)
		{
			this->chart1->Series[0]->Points->Add(rle);
			this->chart1->Series[1]->Points->Add(lzw);
			this->chart1->Series[2]->Points->Add(huffman);
		}

		PageAnalysis(PageFile^ file)
		{
			this->file = file;
			InitializeComponent();
		}

		PageAnalysis(void)
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
		~PageAnalysis()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			series1->Legend = L"Legend1";
			series1->Name = L"RLE";
			series2->ChartArea = L"ChartArea1";
			series2->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			series2->Legend = L"Legend1";
			series2->Name = L"LZW";
			series3->ChartArea = L"ChartArea1";
			series3->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			series3->Legend = L"Legend1";
			series3->Name = L"Huffman";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(746, 477);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			title1->Font = (gcnew System::Drawing::Font(L"Calibri", 16.2F, System::Drawing::FontStyle::Bold));
			title1->Name = L"Title1";
			title1->Text = L"Compression";
			this->chart1->Titles->Add(title1);
			// 
			// PageAnalysis
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->chart1);
			this->Name = L"PageAnalysis";
			this->Size = System::Drawing::Size(746, 477);
			this->Load += gcnew System::EventHandler(this, &PageAnalysis::PageAnalysis_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void PageAnalysis_Load(System::Object^ sender, System::EventArgs^ e) {
		file->AddNumberEvent += gcnew PageFile::AddNumberEventHandler(this, &PageAnalysis::AddNumber);
	}
};
}
