#include "MyForm.h"
#include "JournalThing.h"
#include <iostream>
#include <fstream>
#include <thread>
using namespace System;
using namespace System::Windows::Forms;
int main()
{
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	JourningProgram::MyForm form;
	Application::Run(% form);

	return 0;
}

