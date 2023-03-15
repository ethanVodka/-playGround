#include "pch.h"
#include "FormSelectTools.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String ^> ^args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Application::Run(gcnew TestSample::FormSelectTools());
    return 0;
}
