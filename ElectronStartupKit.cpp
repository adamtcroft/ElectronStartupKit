// ElectronStartupKit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

inline LPCWSTR stringToLPCWSTR(std::string str)
{
	std::wstring temp = std::wstring(str.begin(), str.end());
	LPCWSTR oString = temp.c_str();
	return 
}

int main()
{
	std::string projectName;

	std::cout << "Welcome to the Electron Startup Kit" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "Please enter your desired project name: " << std::endl;
	std::getline(std::cin, projectName);
	std::string username = getenv("USERNAME");

	LPCWSTR directory = stringToLPCWSTR("C:\\Users\\" + username + "\\Documents\\Electron Projects\\" + projectName + "\\");

	CreateDirectory(directory, NULL);

	if (!CreateDirectory(directory, NULL))
	{
		std::cout << "Directory Already Exists!";
	}

	//system("npm init");
}