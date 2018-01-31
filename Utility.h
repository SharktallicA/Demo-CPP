#pragma once

/*
	Useful static methods for C++ console applications
	Khalid Ali 2018
	http://khalidali.co.uk/
*/

#include <iostream>
#include <random>
#include <windows.h>
#include <conio.h>

using namespace std;

enum Colour
{
	black, blue, green, aqua, red, purple, yellow, default, gray, light_blue,
	light_green, light_aqua, light_red, light_purple, light_yellow, white
}; //enumeration of various colours for console foreground and background

class Utility
{
	//purpose: abstract class the encapulsaties static methods for various useful functions

private:
	Utility() {}; //constructor private to prevent any attempts at initialisation
public:
	int Utility::generateNumber(int min, int max)
	{
		//purpose:Mersenne Twister 19937 64-Bit based P-RNG with provided minimum and maximum values for range
		//parameters: (min) minimum bound for range, (max) maximum bound for range

		int result = 0;
		random_device randGenerator;
		mt19937_64 mersenne(randGenerator());
		uniform_int_distribution<int> distrib(min, max);
		result = distrib(mersenne);
		return result;
	}
	void Utility::clearScreen(void)
	{
		//purpose: clears the screen
		system("cls");
	}
	void Utility::setWindowTitle(string title)
	{
		//purpose: sets the window title
		//parametres: (title) specified title for window
		SetConsoleTitle(title.c_str());
	}
	void Utility::setWindowSize(unsigned int width, unsigned int height)
	{
		//purpose: sets the window size
		//parametres: (width) specified window width, (height) specified window height

		HWND console = GetConsoleWindow();
		RECT rectWindow;
		GetWindowRect(console, &rectWindow);
		MoveWindow(console, rectWindow.left, rectWindow.top, width, height, TRUE);
	}
	void Utility::setColour(Colour fore = WHITE, Colour back = BLACK)
	{
		//purpose: sets the console colour
		//parametres: (fore) enumeration for foreground colour (defaulted as white), (back) enumeration for background colour (defaulted as black)

		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		int colour = back * 16 + fore;
		SetConsoleTextAttribute(handle, colour);
	}
	void Utility::moveCursor(SHORT x, SHORT y)
	{
		//purpose: moves cursor 
		//parametres: (x) specified cursor X, (y) specified cursor Y

		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD point = { x, y };
		SetConsoleCursorPosition(handle, point);
	}
};