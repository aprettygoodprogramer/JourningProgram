#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
int WinMain()
{
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	JourningProgram::MyForm form;
	Application::Run(% form);
	return 0;
}