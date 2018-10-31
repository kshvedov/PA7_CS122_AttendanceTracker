#ifndef LIST_H
#define LIST_H

/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA7
* Date: 11/11/2017
* Description: this is the header file for List
*/

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

#include "ListNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::noskipws;
using std::istream;
using std::ostream;
using std::ofstream;
using std::ifstream;

class List
{
public:
	List();
	~List();

	ListNode *& getFrontPointer(void);

	void setFrontPointer(ListNode *newFront);

	bool isEmpty();

	bool insertAtFront(ListNode *newNode);

	ListNode *makeNode(ifstream &filestream);
	ListNode *makeMasterListNode(ifstream &fs);

private:
	ListNode *mpFront;

	void destroyList();
	void destroyListHelper(ListNode *pMem);
};

#endif