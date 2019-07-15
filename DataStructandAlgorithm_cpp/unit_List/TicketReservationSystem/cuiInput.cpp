#include "cuiInput.h"
#include <istream>
#include <conio.h>

namespace cui
{
	Input::Input(int x, int y, int color, int format) : Widget(color, format, false)
	{
	
	}

	std::istream& Input::blockBegin(std::istream& in)
	{
		COORD coord = { pos.X + curTextInterval, pos.Y };
		SetConsoleCursorPosition(handle, coord);
		SetConsoleTextAttribute(handle, color | style);

		in >> content;
		//�ָ�Ĭ����ʽ
		SetConsoleTextAttribute(handle, White | normalStyle);
		
		return in;
	}

	std::istream& Input::Begin(std::istream& in)
	{
		COORD coord = { pos.X + curTextInterval, pos.Y };
		SetConsoleCursorPosition(handle, coord);
		SetConsoleTextAttribute(handle, color | style);

		content += _getch();
		//�ָ�Ĭ����ʽ
		SetConsoleTextAttribute(handle, White | normalStyle);

		return in;
	}
};