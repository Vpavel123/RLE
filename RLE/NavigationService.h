#pragma once

using namespace System;
using namespace System::Windows::Forms;

class NavigationService
{
public:
    static NavigationService* getInstance()
    {
        if (instance == nullptr)
        {
            instance = new NavigationService();
        }
        return instance;
    }

    void Navigate(Control^ Page, Panel^ panel)
    {
        panel->Controls->Clear();
        panel->Controls->Add(Page);
    }
    
    void Navigate(String^ text, Label^ label, Control^ Page, Panel^ panel)
    {
        panel->Controls->Clear();
        panel->Controls->Add(Page);
        label->Text = text;
    }

private:
    NavigationService() {}
    NavigationService(const NavigationService&) = delete;
    NavigationService& operator=(const NavigationService&) = delete;

    static NavigationService* instance;
};