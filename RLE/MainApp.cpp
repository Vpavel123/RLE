#pragma once
#include "MainApp.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    RLE::MainApp form; //WinFormsTest - имя вашего проекта
    Application::Run(% form);
}