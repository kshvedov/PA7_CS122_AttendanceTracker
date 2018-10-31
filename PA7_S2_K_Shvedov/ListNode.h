#ifndef LISTNODE_H
#define LISTNODE_H

/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA7
* Date: 11/11/2017
* Description: this is the header file for ListNode
*/

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::noskipws;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;
using std::getline;
using std::stoi;

class ListNode
{
public:
	ListNode(int rNumb = 0, int idNumb = 0, string name = "NA", string email = "NA", string units = "NA", string program = "NA", string level = "NA");
	~ListNode();

	int getrNumb() const;
	int getidNumb() const;
	string getName() const;
	string getEmail() const;
	string getUnits() const;
	string getProgram() const;
	string getLevel() const;
	int getAbs() const;
	Stack<string> *getLAbs();
	ListNode * getNextPtr() const;

	void setrNumb(int newRNumb);
	void setidNumb(int newIDNumb);
	void setName(string newName);
	void setEmail(string newEmail);
	void setUnits(string newUnits);
	void setProgram(string newProgram);
	void setLevel(string newLevel);
	void setAbs(int setAbs);
	void addAbs();
	void addLabs(string date);
	void setNextPtr(ListNode * const pNewNext);

private:
	int mRNumb; //record Number
	int mIDNumb;
	string mName;
	string mEmail;
	string mUnits;
	string mProgram;
	string mLevel;
	int mAbs;//Number of absences
	Stack<string> *mLAbs;//stack of latest absences
	ListNode *mpNext;
};

ifstream &operator >> (ifstream &lhs, ListNode &rhs);
ostream &operator << (ostream &lhs, ListNode &rhs);
ofstream & operator << (ofstream &lhs, ListNode &rhs);
#endif