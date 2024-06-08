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

void saveToFile()
{


	std::ofstream outFile("Text.txt", std::ios::app);
	if (outFile.is_open()) {

		outFile << "\n";
		if (JournalHolder.Date == "DEEZ NUTS")
		{
			auto currentTime = std::chrono::system_clock::now();
			std::time_t time = std::chrono::system_clock::to_time_t(currentTime);


			char formattedTime[11];
			std::strftime(formattedTime, sizeof(formattedTime), "%Y-%m-%d", std::localtime(&time));
			outFile << formattedTime;

		}
		else
		{
			outFile << JournalHolder.Date;
		}
		outFile << "\n";
		outFile << JournalHolder.MainText;
		outFile << "\n";
		outFile << "\n";
		outFile << "..";

	}
	outFile.close();


}




void RunSaveToFile()
{
	std::thread t1(saveToFile);
	t1.detach();
}

void  retreiveData()
{
	std::ifstream file("Text.txt");
	std::string result = "";
	bool FoundDate = false;
	std::string line;
	while (std::getline(file, line)) {
		
		if (line == JournalHolder.DateLookingFor && FoundDate == false)
		{
			
			result += "\n";
			result += "\n";
			FoundDate = true;
		}
		if (FoundDate == true)
		{
			result += line;
			result += "\n";
		}
		if (FoundDate == true && line == "..")
		{
			break;
		}
	}

	file.close();
	
	JournalHolder.result = result;
}

void RunRetreiveData()
{
	std::thread t1(retreiveData);
	t1.detach();
}