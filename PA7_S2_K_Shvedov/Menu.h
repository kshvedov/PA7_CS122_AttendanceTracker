#ifndef MENU_H
#define MENU_H
/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA7
* Date: 11/11/2017
* Description: this is the header file for the Menu
*/

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctime>

#include "List.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::fstream;
using std::ifstream;
using std::string;
using std::to_string;

class Menu
{
public:
	Menu();
	~Menu();

	void runApp(void);
	void importCourses(ifstream &fileStream);
	void loadMasterList(ifstream &fs);
	void storeMasterList(ofstream &fs);

	void displayMenu(void);
	string createCurrDate(void) const;

private:
	string mcDate;
	List masterList;
};


#endif