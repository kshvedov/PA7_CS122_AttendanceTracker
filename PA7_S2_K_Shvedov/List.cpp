#include "List.h"
/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA7
* Date: 11/11/2017
* Description: here we have the implementation of the linked list
*/
//list constructor
List::List()
{
	mpFront = nullptr;
}

//list destructor
List::~List()
{
	destroyList();
}

//returns the front of list pointer
ListNode *& List::getFrontPointer(void)
{
	return mpFront;
}

//sets the front pointer to the new adress
void List::setFrontPointer(ListNode *newFront)
{
	mpFront = newFront;
}

//checks if the list is empty
bool List::isEmpty()
{
	return (mpFront == nullptr);
}

//inserts a new node at front
bool List::insertAtFront(ListNode *newNode)
{
	bool t = false;
	ListNode *temp;
	if (newNode != nullptr)
	{
		t = true;
		newNode->setNextPtr(mpFront);
		setFrontPointer(newNode);
		if (newNode->getName() != "NA")
		{
			cout << *newNode << endl;
		}
	}
	//the csv file has an empty line at the end this makes an empty node
	//these lines get rid of it
	if (newNode->getName() == "NA")
	{
		temp = newNode;
		temp = temp->getNextPtr();
		setFrontPointer(temp);
		delete(newNode);
	}
	return t;
}

//makes a new node with info from the file stream
ListNode * List::makeNode(ifstream &filestream)
{
	ListNode *newNode = new ListNode();
	filestream >> *newNode;
	return newNode;
}

//makes a new node using masterlist info
ListNode * List::makeMasterListNode(ifstream &fs)
{
	ListNode *newNode = new ListNode();
	string temp;
	int value = 0;
	//record number
	fs >> temp;
	if (!temp.empty())
	{
		value = stoi(temp);
		newNode->setrNumb(value);
		//id number
		fs >> temp;
		value = stoi(temp);
		newNode->setidNumb(value);
		//name
		fs >> temp;
		newNode->setName(temp);
		//email
		fs >> temp;
		newNode->setEmail(temp);
		//units
		fs >> temp;
		newNode->setUnits(temp);
		//program
		fs >> temp;
		newNode->setProgram(temp);
		//level
		fs >> temp;
		newNode->setLevel(temp);
		//absences
		fs >> temp;
		value = stoi(temp);
		newNode->setAbs(value);
		getline(fs, temp);//solves an issue with reading in
		getline(fs, temp);
		while (!temp.empty())
		{
			newNode->getLAbs()->push(temp);
			getline(fs, temp);
		}
	}
	return newNode;
}

//calls a recursive destructor
void List::destroyList()
{
	destroyListHelper(mpFront);
}

//recursively destroys list
void List::destroyListHelper(ListNode * const node)
{
	if (node != nullptr)
	{
		destroyListHelper(node->getNextPtr());
		delete node;
	}
}