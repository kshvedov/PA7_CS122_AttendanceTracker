#include "ListNode.h"
/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA7
* Date: 11/11/2017
* Description: here we have the implementation the list node
*/

//constructor for node
ListNode::ListNode(int rNumb, int idNumb, string name, string email, string units, string program, string level)
{
	mRNumb = rNumb;
	mIDNumb = idNumb;
	mName = name;
	mEmail = email;
	mUnits = units;
	mProgram = program;
	mLevel = level;
	mAbs = 0;
	Stack<string> *newStack = new Stack<string>();
	mLAbs = newStack;
	mpNext = nullptr;
}

//destructor for node
ListNode::~ListNode()
{
	//empty
}


//All the data getters are here(retrieve info and return it)
int ListNode::getrNumb() const
{
	return mRNumb;
}
int ListNode::getidNumb() const
{
	return mIDNumb;
}
string ListNode::getName() const
{
	return mName;
}
string ListNode::getEmail() const
{
	return mEmail;
}
string ListNode::getUnits() const
{
	return mUnits;
}
string ListNode::getProgram() const
{
	return mProgram;
}
string ListNode::getLevel() const
{
	return mLevel;
}
int ListNode::getAbs() const
{
	return mAbs;
}
ListNode * ListNode::getNextPtr() const 
{
	return mpNext;
}
Stack<string> * ListNode::getLAbs()
{
	return mLAbs;
}

//All the data setters are here (sets a value to what is within the brackets)
void ListNode::setrNumb(int newRNumb)
{
	mRNumb = newRNumb;
}
void ListNode::setidNumb(int newIDNumb)
{
	mIDNumb = newIDNumb;
}
void ListNode::setName(string newName)
{
	mName = newName;
}
void ListNode::setEmail(string newEmail)
{
	mEmail = newEmail;
}
void ListNode::setUnits(string newUnits)
{
	mUnits = newUnits;
}
void ListNode::setProgram(string newProgram)
{
	mProgram = newProgram;
}
void ListNode::setLevel(string newLevel)
{
	mLevel = newLevel;
}
void ListNode::setAbs(int newAbs)
{
	mAbs = newAbs;
}
void ListNode::addAbs()
{
	mAbs++;
}
void ListNode::setNextPtr(ListNode * const pNewNext)
{
	mpNext = pNewNext;
}
void ListNode::addLabs(string date)
{
	mLAbs->push(date);
}


//overloaded operator for retrieving info from csv
ifstream &operator >> (ifstream &lhs, ListNode &rhs)
{
	string temp;
	int value = 0;
	//record number
	getline(lhs, temp, ',');
	if (!temp.empty())
	{
		value = stoi(temp);
		rhs.setrNumb(value);
		//id number
		getline(lhs, temp, ',');
		value = stoi(temp);
		rhs.setidNumb(value);
		//name

		getline(lhs, temp, '"');
		getline(lhs, temp, '"');
		rhs.setName(temp);
		getline(lhs, temp, ',');
		//email
		getline(lhs, temp, ',');
		rhs.setEmail(temp);
		//units
		getline(lhs, temp, ',');
		rhs.setUnits(temp);
		//program
		getline(lhs, temp, ',');
		rhs.setProgram(temp);
		//level
		getline(lhs, temp, '\n');
		rhs.setLevel(temp);
	}
	return lhs;
}

//overloaded insertion operator for printing tos string
ostream &operator << (ostream &lhs, ListNode &rhs)
{
	lhs << "Student ID: " << rhs.getidNumb() << endl;
	lhs << "Student Name: " << rhs.getName() << endl;

	return lhs;
}

//overloaded insertion operator for printing to master file
ofstream & operator << (ofstream &lhs, ListNode &rhs)
{
	lhs << rhs.getrNumb() << endl;
	lhs << rhs.getidNumb() << endl;
	lhs << rhs.getName() << endl;
	lhs << rhs.getEmail() << endl;
	lhs << rhs.getUnits() << endl;
	lhs << rhs.getProgram() << endl;
	lhs << rhs.getLevel() << endl;
	lhs << rhs.getAbs() << endl;

	return lhs;
}