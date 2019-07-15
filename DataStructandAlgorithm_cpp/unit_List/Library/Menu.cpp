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
		std::cout << "���벻��Ϊ�գ����������� \n";
		std::cin >> input;
	}

	return input;
}

int Menu::InputInt()
{
	int number = -1;
	std::cin >> number;

	while (number < 0) {
		std::cout << "���벻��С��0������������ \n";
		std::cin >> number;
	}

	return number;
}

void Menu::libraryAddBook() 
{
	while (true) {
		Clear();

		std::cout << "��������������������������#quit �˳���: \n";
		std::string name = InputString();
		std::string authorName = InputString();
		if (name == "#quit" || authorName == "#quit")
			break;

		new Book(name, authorName);

		std::cout << "¼��ɹ���";
		Pause();
	}
}

void Menu::libraryOutBook()
{
	while (true)
	{
		Clear();

		std::list<Book*> seachLs;
		std::cout << "����������ҵ����ֺͰ�ʲô���Ͳ��ң�bookName authorName��(��������#quit �˳�): \n";
		std::string findname = InputString();
		std::string typeName = InputString();
		if (findname == "#quit" || typeName == "#quit")
			break;

		//ƥ��book����seachLs
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
		} //���������bookName
		Clear();
		
		//�ж��Ƿ�����
		if (seachLs.size() == 0) {
			std::cout << "û������Խ裬ʧ�ܣ�";
			Pause();
			break;
		}


		//��ʾbook
		int num = 0;
		std::string patronname;
		Patron* patron = NULL;
		auto seachIt = seachLs.begin();
		for (seachIt; seachIt != seachLs.end(); seachIt++, num++) {
			Book* em = *seachIt;

			std::cout << " <" << num << "> ";
			Show::showBook(*em);
		}

		//ѡ��book
		std::cout << "������ѡ��Ҫ����鼮���������: ";
		num = InputInt();
		patronname = InputString();
		seachIt = seachLs.begin();
		for (seachIt; seachIt != seachLs.end() && num; seachIt++, num--);
		Book* seachBook = *seachIt;
		
		//�������ַ��ϵĵ���
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

		std::cout << "����ɹ���";
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

	std::cout << "���ҳɹ���";
	Pause();
}

void Menu::libraryQuit()
{
	std::cout << "\n������Ϊ�˳�Ϊ���õ��Լ���ϣ�����´�������bey..." << std::endl;
}

int Menu::run()
{
	libData::Load();
	while (true) {
		std::cout << "(1) ������� " << std::endl;
		std::cout << "(2) ѡ����� " << std::endl;
		std::cout << "(3) ȫ���鼮 " << std::endl;
		std::cout << "(4) Quit�˳� " << std::endl;
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