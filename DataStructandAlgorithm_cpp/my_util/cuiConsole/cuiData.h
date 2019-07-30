#pragma once
#include <Windows.h>
#include <string>

namespace cui
{
	//Pos
	const int NPos = -1;

	//Dirction
	enum CPrintDirction
	{
		enmDir_Center = 74,
		enmDir_Left   = 75,
		enmDir_Right  = 77,
	};

	//Key
	enum KeyCode 
	{
		enmKey_Enter    = 13,
		enmKey_Back     =  8,
		enmKey_SpaceKey = 32,
	};

	//Style
	enum CPrintStyle 
	{
		enmStyle_Normal =   256,
		enmStyle_Lines  = 32768,
	};

	//ForeColor
	enum CForeGroundColor
	{
		enmCFC_Red = FOREGROUND_INTENSITY | FOREGROUND_RED,
		enmCFC_Green = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		enmCFC_Blue = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
		enmCFC_Yellow = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
		enmCFC_Purple = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
		enmCFC_Cyan = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		enmCFC_Gray = FOREGROUND_INTENSITY,
		enmCFC_White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		enmCFC_HighWhite = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		enmCFC_Black = 0,
	};

	//BackColor
	enum CBackGroundColor
	{
		enmCBC_Red = BACKGROUND_INTENSITY | BACKGROUND_RED,
		enmCBC_Green = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
		enmCBC_Blue = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
		enmCBC_Yellow = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
		enmCBC_Purple = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
		enmCBC_Cyan = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
		enmCBC_White = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
		enmCBC_HighWhite = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
		enmCBC_Black = 0,
	};


	//ElementType
	enum CElementType
	{
		enmCET_out = 1,
		enmCET_in  = 2,
	};
};
