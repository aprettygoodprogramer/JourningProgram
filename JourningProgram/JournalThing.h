#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
struct JournalHolder
{
	std::string MainText;
	bool WriteToFile;
	bool RightToFile;
	std::string Date;
};

struct JournalHolder JournalHolder ;

void saveToFile()
{


	std::ofstream outFile("Text.txt");
	if (outFile.is_open()) {
		outFile << JournalHolder.MainText;
	}
	outFile.close();


}




void RunSaveToFile()
{
	std::thread t1(saveToFile);
	t1.detach();
}