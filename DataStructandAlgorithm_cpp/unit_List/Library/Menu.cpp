#include "Book.h"
#include "Patron.h"
#include "Author.h"
#include "libData.h"
#include "Show.h"
#include "Menu.h"

void Menu::Clear()
{
	system("cls");
}

void Menu::Pause()
{
	system("pause");
}

std::string Menu::InputString()
{
	std::string input;
	std::cin >> input;

	while (input.empty()) {
		std::cout << "输入不能为空，请重新输入 \n";
		std::cin >> input;
	}

	return input;
}

int Menu::InputInt()
{
	int number = -1;
	std::cin >> number;

	while (number < 0) {
		std::cout << "输入不能小于0，请重新输入 \n";
		std::cin >> number;
	}

	return number;
}

void Menu::libraryAddBook() 
{
	while (true) {
		Clear();

		std::cout << "输入书名和作者名（任意输入#quit 退出）: \n";
		std::string name = InputString();
		std::string authorName = InputString();
		if (name == "#quit" || authorName == "#quit")
			break;

		new Book(name, authorName);

		std::cout << "录入成功，";
		Pause();
	}
}

void Menu::libraryOutBook()
{
	while (true)
	{
		Clear();

		std::list<Book*> seachLs;
		std::cout << "输入你想查找的名字和按什么类型查找（bookName authorName）(任意输入#quit 退出): \n";
		std::string findname = InputString();
		std::string typeName = InputString();
		if (findname == "#quit" || typeName == "#quit")
			break;

		//匹配book进入seachLs
		if (typeName == "authorName") {
			for (int A = 'A'; A <= 'Z'; A++) {
				int id = libData::findNumber(A);
				auto authorIt = libData::authorLs[id].begin();
				for (authorIt; authorIt != libData::authorLs[id].end(); authorIt++) {
					
				}
			}
		}
		else {
			for (int A = 'A'; A <= 'Z'; A++) {
				int id = libData::findNumber(A);
				auto bookIt = libData::bookLs[id].begin();
				for (bookIt; bookIt != libData::bookLs[id].end(); bookIt++) {
					Book* em = *bookIt;
					if (em->getName().find(findname) != std::string::npos && &em->getPatron() == NULL)
						seachLs.push_back(em);
				}
			}
		} //错误输入就bookName
		Clear();
		
		//判断是否有书
		if (seachLs.size() == 0) {
			std::cout << "没有书可以借，失败，";
			Pause();
			break;
		}


		//显示book
		int num = 0;
		std::string patronname;
		Patron* patron = NULL;
		auto seachIt = seachLs.begin();
		for (seachIt; seachIt != seachLs.end(); seachIt++, num++) {
			Book* em = *seachIt;

			std::cout << " <" << num << "> ";
			Show::showBook(*em);
		}

		//选择book
		std::cout << "输入编号选择要借的书籍和你的姓名: ";
		num = InputInt();
		patronname = InputString();
		seachIt = seachLs.begin();
		for (seachIt; seachIt != seachLs.end() && num; seachIt++, num--);
		Book* seachBook = *seachIt;
		
		//查找名字符合的档案
		for (int A = 'A'; A <= 'Z'; A++) {
			int id = libData::findNumber(A);
			auto patronIt = libData::patronLs[id].begin();
			for (patronIt; patronIt != libData::patronLs[id].end(); patronIt++) {
				Patron* em = *patronIt;
				if (em->getName().find(patronname) != std::string::npos) {
					patron = em;
					break;
				}
			}
		}

		if (patron == NULL)
			patron = new Patron(patronname);
		seachBook->setPatron(*patron);

		std::cout << "借书成功，";
		Pause();
		break;
	}
}

void Menu::libraryReturnBook()
{

}

void Menu::libraryShowStatus()
{
	Clear();

	for (int A = 'A'; A <= 'Z'; A++) {
		int id = libData::findNumber(A);

		auto bookit = libData::bookLs[id].begin();
		for (bookit; bookit != libData::bookLs[id].end(); bookit++)
			Show::showBook(**bookit, true);
	}

	std::cout << "查找成功，";
	Pause();
}

void Menu::libraryQuit()
{
	std::cout << "\n读书是为了成为更好的自己，希望您下次再来。bey..." << std::endl;
}

int Menu::run()
{
	libData::Load();
	while (true) {
		std::cout << "(1) 添加新书 " << std::endl;
		std::cout << "(2) 选择借书 " << std::endl;
		std::cout << "(3) 全部书籍 " << std::endl;
		std::cout << "(4) Quit退出 " << std::endl;
		std::cout << "Input: ";
		
		std::string select = "-1";
		std::cin >> select;

		if (select == "1")
			libraryAddBook();
		else if (select == "2")
			libraryOutBook();
		else if (select == "3")
			libraryShowStatus();
		else break;

		Clear();
	}
	libData::Save();
	libraryQuit();

	return 0;
}