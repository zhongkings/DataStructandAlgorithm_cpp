#pragma once
#include <Windows.h>

namespace cui {
//Pos
static const int NPos = -1;

//Color
static const int Red   = 4;
static const int Green = 2;
static const int Blue  = 1;
static const int White = Red | Green | Blue;

//Style
static const int normalStyle = 256;
static const int lineasStyle = 32768;

//Key
static int EnterKey = 13;
static int BackKey  = 8;
static int SpaceKey = 32;

//Windows Handle
extern HANDLE handle;
extern CONSOLE_SCREEN_BUFFER_INFO csbInfo;
};