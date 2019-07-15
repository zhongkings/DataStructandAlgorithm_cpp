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
	static void libraryShowStatus(); //可以显示某个作者所有书籍，那些书没有借出，那些书已经借出，显示全部书籍
	static void libraryQuit();
public:
	static int run();
};