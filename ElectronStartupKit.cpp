// ElectronStartupKit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

std::unique_ptr<LPCWSTR> strToLPCSTR(std::string & str)
{
	std::unique_ptr<std::wstring> test = std::make_unique<std::wstring>(str.begin(), str.end());
	std::wstring temp = std::wstring(str.begin(), str.end());
	std::unique_ptr<LPCWSTR> value = std::make_unique<LPCWSTR>(test.get()->c_str());
	return value;
}

int main()
{
	std::string projectName;

	std::cout << "Welcome to the Electron Startup Kit" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << "Please enter your desired project name: " << std::endl;
	std::getline(std::cin, projectName);
	std::string username = getenv("USERNAME");

	std::string dir = "C:\\Users\\" + username + "\\Documents\\Electron Projects\\" + projectName;
	//std::wstring temp = std::wstring(dir.begin(), dir.end());
	//LPCWSTR Ldir = temp.c_str();
	std::unique_ptr<LPCWSTR> Ldir = strToLPCSTR(dir);

	if (!CreateDirectory(*Ldir, NULL))
	{
		std::cout << "Directory Already Exists!";
	}
}