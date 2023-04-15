#pragma once
#include <string>
#include "PageGeneral.h"
#include "PageAnalysis.h"
#include "LZW.h"
#include "RLEencryption.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
using namespace System::Text;


namespace RLE {

	/// <summary>
	/// Сводка для PageFile
	/// </summary>
	public ref class PageFile : public System::Windows::Forms::UserControl
	{
	public:
	public:
	private: System::Windows::Forms::TreeView^ treeView1;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ createToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ folderToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ textFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ deleteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^ renameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ moveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ pasteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ onlyFilesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ allToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::ImageList^ imageList2;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ CompressToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ расжатьToolStripMenuItem;

	public:

	public:
		RLEencryption* rle;
		LZW* lzw;
		PageGeneral^ general;
		PageAnalysis^ analysis;

		void UserControl1_ComboBoxTextChanged(System::Object^ sender, System::String^ text)
		{
			aboutToolStripMenuItem->Text = text;
		}

		PageFile(PageGeneral^ general, PageAnalysis^ analysis)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->analysis = analysis;
			this->general = general;
			lzw = new LZW();
			rle = new RLEencryption();
			openFileDialog1->Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
			saveFileDialog1->Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
			menuStrip1->BackColor = System::Drawing::Color().FromArgb(51, 51, 77); 
		}

		PageFile(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			rle = new RLEencryption();
			openFileDialog1->Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
			saveFileDialog1->Filter = "Text files(*.txt)|*.txt|All files(*.*)|*.*";
		}

	private:
		System::Void OnComboBoxTextChanged(System::String^ text)
		{
			aboutToolStripMenuItem->Text = text;
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












	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::ComponentModel::IContainer^ components;






	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->CompressToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->расжатьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->imageList2 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->folderToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->renameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->moveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->onlyFilesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->allToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->contextMenuStrip1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(3, 40);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(223, 409);
			this->treeView1->TabIndex = 2;
			this->treeView1->BeforeExpand += gcnew System::Windows::Forms::TreeViewCancelEventHandler(this, &PageFile::treeView1_BeforeExpand);
			this->treeView1->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &PageFile::treeView1_AfterSelect);
			this->treeView1->NodeMouseClick += gcnew System::Windows::Forms::TreeNodeMouseClickEventHandler(this, &PageFile::treeView1_NodeMouseClick);
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3
			});
			this->listView1->ContextMenuStrip = this->contextMenuStrip1;
			this->listView1->HideSelection = false;
			this->listView1->LabelEdit = true;
			this->listView1->LargeImageList = this->imageList2;
			this->listView1->Location = System::Drawing::Point(232, 40);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(511, 295);
			this->listView1->SmallImageList = this->imageList2;
			this->listView1->TabIndex = 3;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->AfterLabelEdit += gcnew System::Windows::Forms::LabelEditEventHandler(this, &PageFile::listView1_AfterLabelEdit);
			this->listView1->ItemActivate += gcnew System::EventHandler(this, &PageFile::listView1_ItemActivate);
			this->listView1->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &PageFile::listView1_ItemSelectionChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Имя";
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Размер";
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Изменен";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->CompressToolStripMenuItem,
					this->расжатьToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(135, 52);
			// 
			// CompressToolStripMenuItem
			// 
			this->CompressToolStripMenuItem->Name = L"CompressToolStripMenuItem";
			this->CompressToolStripMenuItem->Size = System::Drawing::Size(134, 24);
			this->CompressToolStripMenuItem->Text = L"Сжать";
			this->CompressToolStripMenuItem->Click += gcnew System::EventHandler(this, &PageFile::CompressToolStripMenuItem_Click);
			// 
			// расжатьToolStripMenuItem
			// 
			this->расжатьToolStripMenuItem->Name = L"расжатьToolStripMenuItem";
			this->расжатьToolStripMenuItem->Size = System::Drawing::Size(134, 24);
			this->расжатьToolStripMenuItem->Text = L"Расжать";
			this->расжатьToolStripMenuItem->Click += gcnew System::EventHandler(this, &PageFile::расжатьToolStripMenuItem_Click);
			// 
			// imageList2
			// 
			this->imageList2->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList2->ImageSize = System::Drawing::Size(16, 16);
			this->imageList2->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(232, 341);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(511, 108);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Black;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(746, 37);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->createToolStripMenuItem,
					this->deleteToolStripMenuItem, this->toolStripSeparator1, this->renameToolStripMenuItem, this->moveToolStripMenuItem, this->copyToolStripMenuItem,
					this->pasteToolStripMenuItem
			});
			this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Calibri", 14));
			this->fileToolStripMenuItem->ForeColor = System::Drawing::SystemColors::Control;
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(81, 33);
			this->fileToolStripMenuItem->Text = L"Файл";
			// 
			// createToolStripMenuItem
			// 
			this->createToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->folderToolStripMenuItem,
					this->textFileToolStripMenuItem
			});
			this->createToolStripMenuItem->Name = L"createToolStripMenuItem";
			this->createToolStripMenuItem->Size = System::Drawing::Size(263, 34);
			this->createToolStripMenuItem->Text = L"Создать";
			// 
			// folderToolStripMenuItem
			// 
			this->folderToolStripMenuItem->Name = L"folderToolStripMenuItem";
			this->folderToolStripMenuItem->Size = System::Drawing::Size(263, 34);
			this->folderToolStripMenuItem->Text = L"Папку";
			this->folderToolStripMenuItem->Click += gcnew System::EventHandler(this, &PageFile::folderToolStripMenuItem_Click);
			// 
			// textFileToolStripMenuItem
			// 
			this->textFileToolStripMenuItem->Name = L"textFileToolStripMenuItem";
			this->textFileToolStripMenuItem->Size = System::Drawing::Size(263, 34);
			this->textFileToolStripMenuItem->Text = L"Текстовый файл";
			this->textFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &PageFile::textFileToolStripMenuItem_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(263, 34);
			this->deleteToolStripMenuItem->Text = L"Удалить";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &PageFile::deleteToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(260, 6);
			// 
			// renameToolStripMenuItem
			// 
			this->renameToolStripMenuItem->Name = L"renameToolStripMenuItem";
			this->renameToolStripMenuItem->Size = System::Drawing::Size(263, 34);
			this->renameToolStripMenuItem->Text = L"Переименовать";
			this->renameToolStripMenuItem->Click += gcnew System::EventHandler(this, &PageFile::renameToolStripMenuItem_Click);
			// 
			// moveToolStripMenuItem
			// 
			this->moveToolStripMenuItem->Name = L"moveToolStripMenuItem";
			this->moveToolStripMenuItem->Size = System::Drawing::Size(263, 34);
			this->moveToolStripMenuItem->Text = L"Переместить";
			this->moveToolStripMenuItem->Click += gcnew System::EventHandler(this, &PageFile::moveToolStripMenuItem_Click);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->Size = System::Drawing::Size(263, 34);
			this->copyToolStripMenuItem->Text = L"Копировать";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &PageFile::copyToolStripMenuItem_Click);
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->onlyFilesToolStripMenuItem,
					this->allToolStripMenuItem
			});
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(263, 34);
			this->pasteToolStripMenuItem->Text = L"Вставить";
			// 
			// onlyFilesToolStripMenuItem
			// 
			this->onlyFilesToolStripMenuItem->Name = L"onlyFilesToolStripMenuItem";
			this->onlyFilesToolStripMenuItem->Size = System::Drawing::Size(293, 34);
			this->onlyFilesToolStripMenuItem->Text = L"Только файл";
			this->onlyFilesToolStripMenuItem->Click += gcnew System::EventHandler(this, &PageFile::onlyFilesToolStripMenuItem_Click);
			// 
			// allToolStripMenuItem
			// 
			this->allToolStripMenuItem->Name = L"allToolStripMenuItem";
			this->allToolStripMenuItem->Size = System::Drawing::Size(293, 34);
			this->allToolStripMenuItem->Text = L"Все файлы и папки";
			this->allToolStripMenuItem->Click += gcnew System::EventHandler(this, &PageFile::allToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Calibri", 14));
			this->aboutToolStripMenuItem->ForeColor = System::Drawing::SystemColors::Control;
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(62, 33);
			this->aboutToolStripMenuItem->Text = L"RLE";
			// 
			// toolStrip1
			// 
			this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Location = System::Drawing::Point(0, 452);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(746, 25);
			this->toolStrip1->TabIndex = 6;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// PageFile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->treeView1);
			this->Name = L"PageFile";
			this->Size = System::Drawing::Size(746, 477);
			this->Load += gcnew System::EventHandler(this, &PageFile::PageFile_Load);
			this->contextMenuStrip1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool OneFile, Delete;
		TreeNode^ delnode;
		String^ NameList;
		String^ sourcePath;
		String^ fileName;
		System::Windows::Forms::ListViewItem^ SelectedItem;

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ filename = openFileDialog1->FileName;
			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(filename)).ToPointer();

			if (saveFileDialog1->ShowDialog() == DialogResult::OK)
			{
				String^ filenamesave = saveFileDialog1->FileName;
				String^ Text = richTextBox1->Text;
				const char* _ptr = (const char*)(Marshal::StringToHGlobalAnsi(filenamesave)).ToPointer();
				lzw->LZW_Compress(std::string(ptr), std::string(_ptr));
				std::string temp = rle->ReadFile(std::string(_ptr));
				richTextBox1->Text = gcnew System::String(temp.c_str());
			}
		}

		private: System::Void treeView1_BeforeExpand(System::Object^ sender, System::Windows::Forms::TreeViewCancelEventArgs^ e) {
			treeView1->BeginUpdate();

			for each (TreeNode ^ node in e->Node->Nodes)
			{
				GetDirs(node);
			}

			treeView1->EndUpdate();
		}

		private: System::Void treeView1_NodeMouseClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e) {
			delnode = e->Node;
		}

		private: System::Void treeView1_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
			TreeNode^ selectedNode = e->Node;
			String^ fullPath = selectedNode->FullPath;

			DirectoryInfo^ di = gcnew DirectoryInfo(fullPath);
			array<FileInfo^>^ fiArray;
			array<DirectoryInfo^>^ diArray;

			try
			{
				fiArray = di->GetFiles();
				diArray = di->GetDirectories();
			}
			catch (...)
			{
				return;
			}

			listView1->Items->Clear();

			for each (DirectoryInfo ^ dirInfo in diArray)
			{
				ListViewItem^ lvi = gcnew ListViewItem(dirInfo->Name);
				lvi->SubItems->Add("0");
				lvi->SubItems->Add(dirInfo->LastWriteTime.ToString());
				lvi->ImageIndex = 0;

				listView1->Items->Add(lvi);
			}

			for each (FileInfo ^ fileInfo in fiArray)
			{
				ListViewItem^ lvi = gcnew ListViewItem(fileInfo->Name);
				lvi->SubItems->Add(fileInfo->Length.ToString());
				lvi->SubItems->Add(fileInfo->LastWriteTime.ToString());

				String^ filenameExtension = Path::GetExtension(fileInfo->Name)->ToLower();

				if (filenameExtension == ".com")
				{
					lvi->ImageIndex = 2;
				}
				else if (filenameExtension == ".exe")
				{
					lvi->ImageIndex = 2;
				}
				else if (filenameExtension == ".hlp")
				{
					lvi->ImageIndex = 3;
				}
				else if (filenameExtension == ".txt")
				{
					lvi->ImageIndex = 4;
				}
				else if (filenameExtension == ".doc")
				{
					lvi->ImageIndex = 5;
				}
				else
				{
					lvi->ImageIndex = 1;
				}

				listView1->Items->Add(lvi);
			}
		}

	private: System::Void listView1_ItemActivate(System::Object^ sender, System::EventArgs^ e) {
		for each (ListViewItem ^ lvi in listView1->SelectedItems)
		{
			String^ ext = Path::GetExtension(lvi->Text)->ToLower();
			String^ fullPath = treeView1->SelectedNode->FullPath;
			if (ext == ".txt" || ext == ".htm" || ext == ".html")
			{
				try
				{
					richTextBox1->LoadFile(Path::Combine(fullPath, lvi->Text),
						RichTextBoxStreamType::PlainText);

					toolStrip1->Text = lvi->Text;
				}
				catch (...)
				{
					return;
				}
			}
			else if (ext == ".rtf")
			{
				try
				{
					richTextBox1->LoadFile(Path::Combine(fullPath, lvi->Text),
						RichTextBoxStreamType::RichText);

					toolStrip1->Text = lvi->Text;
				}
				catch (...)
				{
					return;
				}
			}
		}
	}

	private: System::Void listView1_AfterLabelEdit(System::Object^ sender, System::Windows::Forms::LabelEditEventArgs^ e) {
		if (e->Label != nullptr)
		{
			if (e->Label->Length > 0)
			{
				array <Char>^ temp = { '/','*','?','|', '\\', '<', '>','"' };
				if (e->Label->IndexOfAny(temp) == -1)
				{
					try
					{
						Directory::Move(treeView1->SelectedNode->FullPath + "\\" + listView1->SelectedItems[0]->Text, treeView1->SelectedNode->FullPath + "\\" + e->Label->ToString());
						GetDirs(delnode);
					}
					catch (...)
					{
						MessageBox::Show("Проверьте правильность ввода имени", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
				else
				{
					e->CancelEdit = true;
					MessageBox::Show("Имя папки(файла) не должно содержать следующих знаков: \/:*?<>|", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else
			{
				e->CancelEdit = true;
				MessageBox::Show("Имя папки(файла) не может быть пустым.", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}

	public: System::Void DriveTreeInit()
	{
	   array<String^>^ drivesArray = Directory::GetLogicalDrives();

	   treeView1->BeginUpdate();

	   treeView1->Nodes->Clear();

	   for each (String ^ s in drivesArray)
	   {
		   TreeNode^ drive = gcnew TreeNode(s, 0, 0);
		   treeView1->Nodes->Add(drive);

		   GetDirs(drive);
	   }

	   treeView1->EndUpdate();
	}

	public: System::Void GetDirs(TreeNode^ node)
	{
	   array<DirectoryInfo^>^ diArray;

	   node->Nodes->Clear();

	   String^ fullPath = node->FullPath;
	   DirectoryInfo^ di = gcnew DirectoryInfo(fullPath);

	   try
	   {
		   diArray = di->GetDirectories();
	   }
	   catch (...)
	   {
		   return;
	   }

	   for each (DirectoryInfo ^ dirinfo in diArray)
	   {
		   TreeNode^ dir = gcnew TreeNode(dirinfo->Name, 1, 2);
		   node->Nodes->Add(dir);
	   }
	}

	private: System::Void PageFile_Load(System::Object^ sender, System::EventArgs^ e) {
		Image^ myImage = Image::FromFile(".\\ImageList2\\35FLOPPY.jpg");
		imageList1->Images->Add(myImage);
		myImage = Image::FromFile(".\\ImageList2\\CLSDFOLD.jpg");
		imageList1->Images->Add(myImage);
		myImage = Image::FromFile(".\\ImageList2\\OPENFOLD.jpg");
		imageList1->Images->Add(myImage);

		myImage = Image::FromFile(".\\ImageList2\\CLSDFOLD.jpg");
		imageList2->Images->Add(myImage);
		myImage = Image::FromFile(".\\ImageList2\\DOC.jpg");
		imageList2->Images->Add(myImage);
		DriveTreeInit();
		myImage = Image::FromFile(".\\ImageList2\\EXE.jpg");
		imageList2->Images->Add(myImage);
		myImage = Image::FromFile(".\\ImageList2\\HLP.jpg");
		imageList2->Images->Add(myImage);
		myImage = Image::FromFile(".\\ImageList2\\TXT.jpg");
		imageList2->Images->Add(myImage);
		myImage = Image::FromFile(".\\ImageList2\\WINDOC.jpg");
		imageList2->Images->Add(myImage);

		DriveTreeInit();

		array<String^>^ drivesArray = Directory::GetLogicalDrives();

		for each (String ^ s in drivesArray)
			Console::Write("{0} ", s);

		general->ComboBoxTextChanged += gcnew PageGeneral::ComboBoxTextChangedEventHandler(this, &PageFile::UserControl1_ComboBoxTextChanged);
	}

	private: System::Void renameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listView1->SelectedItems->Count != 0)
		{
			listView1->SelectedItems[0]->BeginEdit();
		}
		else
		{
			MessageBox::Show("Не выбран(-а) файл или папка", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void copyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		sourcePath = treeView1->SelectedNode->FullPath;
		if (listView1->SelectedItems->Count != 0)
		{
			fileName = listView1->SelectedItems[0]->Text;
			OneFile = true;
		}
		else
		{
			fileName = treeView1->SelectedNode->Text;
			OneFile = false;
		}
	}

	private: System::Void onlyFilesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			String^ targetPath = treeView1->SelectedNode->FullPath;
			String^ sourceFile = Path::Combine(sourcePath, fileName);
			String^ destFile = Path::Combine(targetPath, fileName);

			if (OneFile == true)
			{
				if (!Directory::Exists(targetPath))
				{
					Directory::CreateDirectory(targetPath);
				}

				File::Copy(sourceFile, destFile, true);
				GetDirs(delnode);
			}
			else
			{
				if (Directory::Exists(sourcePath))
				{
					array<String^>^ files = Directory::GetFiles(sourcePath);

					for each (String ^ s in files)
					{
						fileName = Path::GetFileName(s);
						destFile = Path::Combine(targetPath, fileName);
						File::Copy(s, destFile, true);
						GetDirs(delnode);
					}
				}
				else
				{
					MessageBox::Show("Исходный путь не существует", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
		catch (...)
		{
			MessageBox::Show("Не был выбран файл(папка) для копирования или перемещения", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void allToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//Копирование из текущего каталога, включая в себя подкаталоги
		//Если в listView выбран элемент, то...
		if (listView1->SelectedItems->Count != 0)
		{
			DirectoryCopy(sourcePath, Path::Combine(treeView1->SelectedNode->FullPath, listView1->SelectedItems[0]->Text), true);
		}
		//В противном случае...
		else
		{
			DirectoryCopy(sourcePath, treeView1->SelectedNode->FullPath, true);
		}
	}

		public: System::Void DirectoryCopy(String^ sourceDirName, String^ destDirName, bool copySubDirs)
		{
			//Получение подкаталогов указанной директории
		  DirectoryInfo^ dir = gcnew DirectoryInfo(sourceDirName);

		  if (!dir->Exists)
		  {
		   throw gcnew DirectoryNotFoundException("Исходный каталог не существует или не может быть найден: " + sourceDirName);
		  }

		  array<DirectoryInfo^>^ dirs = dir->GetDirectories();
		  //Если каталог не существует, то создаём новый каталог
		  if (!Directory::Exists(destDirName))
		  {
			Directory::CreateDirectory(destDirName);
		  }

		  //Получение файлов каталога и копирование их на новое место
		  array<FileInfo^>^ files = dir->GetFiles();
		  for each (FileInfo ^ file in files)
		  {
		   String^ temppath = Path::Combine(destDirName, file->Name);
		   file->CopyTo(temppath, false);
		  }
		  //При копировании подкаталогов, то копировать их и их содержимое в новое место
		  if (copySubDirs)
		  {
		   for each (DirectoryInfo ^ subdir in dirs)
		   {
			   String^ temppath = Path::Combine(destDirName, subdir->Name);
			   DirectoryCopy(subdir->FullName, temppath, copySubDirs);
		   }
		  }
		  GetDirs(delnode);
		}

	private: System::Void folderToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//Счётчик
		int i = 2;
		//Запоминания полного пути для создания папки в стринговую переменную
		String^ DirectoryFolder = treeView1->SelectedNode->FullPath;
		String^ DirFoldName = "Новая папка";

		DirectoryInfo^ dir = gcnew DirectoryInfo(treeView1->SelectedNode->FullPath);
		array<DirectoryInfo^>^ dirs = dir->GetDirectories();

		StringBuilder^ strBuilder = gcnew StringBuilder(DirFoldName);

		for each (DirectoryInfo ^ FolderName in dirs)
		{
			if (DirFoldName == FolderName->Name)
			{

				strBuilder->Append(i.ToString());
				DirFoldName = strBuilder->ToString();
				i++;
			}
		}

		//Если каталог не существует, то создаём новый каталог
		if (!Directory::Exists(DirectoryFolder + "\\" + DirFoldName))
		{
			Directory::CreateDirectory(DirectoryFolder + "\\" + DirFoldName);
			listView1->Items->Add(DirFoldName);
			GetDirs(delnode);
			i = listView1->Items->Count - 1;
			listView1->Items[i]->Selected = true;
			listView1->SelectedItems[0]->BeginEdit();
		}
	}
	private: System::Void textFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		//Счётчик
		int i = 2;
		//Запоминания полного пути для создания папки в стринговую переменную
		String^ DirectoryFile = treeView1->SelectedNode->FullPath;
		String^ DirFileName = "Новый текстовый документ";

		DirectoryInfo^ file = gcnew DirectoryInfo(treeView1->SelectedNode->FullPath);
		array<FileInfo^>^ files = file->GetFiles();

		StringBuilder^ strBuilder = gcnew StringBuilder(DirFileName);

		for each (FileInfo ^ FileName in files)
		{
			if (DirFileName + ".txt" == FileName->Name)
			{

				strBuilder->Append(i.ToString());
				DirFileName = strBuilder->ToString();
				i++;
			}
		}

		//Если каталог не существует, то создаём новый каталог
		if (!File::Exists(DirectoryFile + "\\" + DirFileName + ".txt"))
		{
			File::Create(DirectoryFile + "\\" + DirFileName + ".txt");
			listView1->Items->Add(DirFileName + ".txt");
			GetDirs(delnode);
			i = listView1->Items->Count - 1;
			listView1->Items[i]->Selected = true;
			listView1->SelectedItems[0]->BeginEdit();
		}
	}
	private: System::Void moveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void deleteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listView1->SelectedItems->Count != 0)
		{
			NameList = listView1->SelectedItems[0]->Text;
			Delete = true;
		}
		else
		{
			Delete = false;
		}


		if (Delete == true)
		{
			if (Directory::Exists(Path::Combine(treeView1->SelectedNode->FullPath, NameList)))
			{
				if (MessageBox::Show("Вы действительно хотите удалить папку?", "Удаление", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				{
					try
					{

						Directory::Delete(Path::Combine(treeView1->SelectedNode->FullPath, NameList), true);
						listView1->Items->RemoveAt(listView1->SelectedIndices[0]);
						GetDirs(delnode);
					}
					catch (...)
					{
						MessageBox::Show("Невозможно удалить данную папку", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
			else if (File::Exists(Path::Combine(treeView1->SelectedNode->FullPath, NameList)))
			{
				if (MessageBox::Show("Вы действительно хотите удалить файл?", "Удаление", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				{
					try
					{
						File::Delete(Path::Combine(treeView1->SelectedNode->FullPath, NameList));
						listView1->Items->RemoveAt(listView1->SelectedIndices[0]);
						GetDirs(delnode);
					}
					catch (...)
					{
						MessageBox::Show("Невозможно удалить данный файл", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
		}
		else
		{
			if (Directory::Exists(treeView1->SelectedNode->FullPath))
			{
				if (MessageBox::Show("Вы действительно хотите удалить папку?", "Удаление", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				{
					try
					{
						Directory::Delete(treeView1->SelectedNode->FullPath, true);
						treeView1->Nodes->Remove(treeView1->SelectedNode);
					}
					catch (...)
					{
						MessageBox::Show("Невозможно удалить данную папку", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
			}
		}
	}
	private: System::Void CompressToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (aboutToolStripMenuItem->Text == "RLE")
		{
			NameList = this->SelectedItem->Text;
			NameList = Path::Combine(treeView1->SelectedNode->FullPath, NameList);

			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(NameList)).ToPointer();

			if (saveFileDialog1->ShowDialog() == DialogResult::OK)
			{
				String^ filenamesave = saveFileDialog1->FileName;
				const char* _ptr = (const char*)(Marshal::StringToHGlobalAnsi(filenamesave)).ToPointer();
				rle->RLE_Compress(std::string(ptr), std::string(_ptr));
				std::string temp = rle->ReadFile(std::string(_ptr));
				//richTextBox1->Text = gcnew System::String(temp.c_str());

				FileInfo^ info = gcnew FileInfo(saveFileDialog1->FileName);
				analysis->comp->rle = info->Length;
				analysis->Update();
			}
		}
		else if(aboutToolStripMenuItem->Text == "LZW")
		{
			NameList = this->SelectedItem->Text;
			NameList = Path::Combine(treeView1->SelectedNode->FullPath, NameList);

			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(NameList)).ToPointer();

			if (saveFileDialog1->ShowDialog() == DialogResult::OK)
			{
				String^ filenamesave = saveFileDialog1->FileName;
				const char* _ptr = (const char*)(Marshal::StringToHGlobalAnsi(filenamesave)).ToPointer();
				lzw->LZW_Compress(std::string(ptr), std::string(_ptr));
				std::string temp = rle->ReadFile(std::string(_ptr));

				FileInfo^ info = gcnew FileInfo(saveFileDialog1->FileName);
				analysis->comp->lzw = info->Length;
			}
		}
		else if (aboutToolStripMenuItem->Text == "Huffman compression")
		{
			NameList = this->SelectedItem->Text;
			NameList = Path::Combine(treeView1->SelectedNode->FullPath, NameList);

			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(NameList)).ToPointer();

			if (saveFileDialog1->ShowDialog() == DialogResult::OK)
			{
				String^ filenamesave = saveFileDialog1->FileName;
				const char* _ptr = (const char*)(Marshal::StringToHGlobalAnsi(filenamesave)).ToPointer();
				lzw->LZW_Compress(std::string(ptr), std::string(_ptr));
				std::string temp = rle->ReadFile(std::string(_ptr));

				FileInfo^ info = gcnew FileInfo(saveFileDialog1->FileName);
				analysis->comp->huffman = info->Length;
			}
		}
	}
	private: System::Void listView1_ItemSelectionChanged(System::Object^ sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^ e) {
		this->SelectedItem = e->Item;
	}

	private: System::Void расжатьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (aboutToolStripMenuItem->Text == "RLE")
		{
			NameList = this->SelectedItem->Text;
			NameList = Path::Combine(treeView1->SelectedNode->FullPath, NameList);

			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(NameList)).ToPointer();

			if (saveFileDialog1->ShowDialog() == DialogResult::OK)
			{
				String^ filenamesave = saveFileDialog1->FileName;
				const char* _ptr = (const char*)(Marshal::StringToHGlobalAnsi(filenamesave)).ToPointer();
				rle->RLE_Decompress(std::string(ptr), std::string(_ptr));
				std::string temp = rle->ReadFile(std::string(_ptr));
			}
		}
		else if (aboutToolStripMenuItem->Text == "LZW")
		{
			NameList = this->SelectedItem->Text;
			NameList = Path::Combine(treeView1->SelectedNode->FullPath, NameList);

			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(NameList)).ToPointer();

			if (saveFileDialog1->ShowDialog() == DialogResult::OK)
			{
				String^ filenamesave = saveFileDialog1->FileName;
				const char* _ptr = (const char*)(Marshal::StringToHGlobalAnsi(filenamesave)).ToPointer();
				lzw->LZW_Decompress(std::string(ptr), std::string(_ptr));
				std::string temp = rle->ReadFile(std::string(_ptr));
			}
		}
		else if (aboutToolStripMenuItem->Text == "Huffman compression")
		{
			NameList = this->SelectedItem->Text;
			NameList = Path::Combine(treeView1->SelectedNode->FullPath, NameList);

			const char* ptr = (const char*)(Marshal::StringToHGlobalAnsi(NameList)).ToPointer();

			if (saveFileDialog1->ShowDialog() == DialogResult::OK)
			{
				String^ filenamesave = saveFileDialog1->FileName;
				const char* _ptr = (const char*)(Marshal::StringToHGlobalAnsi(filenamesave)).ToPointer();
				lzw->LZW_Decompress(std::string(ptr), std::string(_ptr));
				std::string temp = rle->ReadFile(std::string(_ptr));
			}
		}
	}

};
}
