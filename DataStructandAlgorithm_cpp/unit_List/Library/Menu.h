#pragma once
#include <iostream>
#include <string>

class Menu
{
private:
	static void Clear();
	static void Pause();
	static std::string InputString();
	static int InputInt();

	static void libraryAddBook();
	static void libraryOutBook();
	static void libraryReturnBook();
	static void libraryShowStatus(); //������ʾĳ�����������鼮����Щ��û�н������Щ���Ѿ��������ʾȫ���鼮
	static void libraryQuit();
public:
	static int run();
};