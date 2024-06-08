#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

#include <thread>
struct JournalHolder
{
	std::string MainText;
	bool WriteToFile;
	bool RightToFile;
	std::string Date = "DEEZ NUTS";
	std::string DateLookingFor;
	std::string result;
};

struct JournalHolder JournalHolder ;

