//this file is based of a lab where a small part of the code was
//provided, but the implementation of function is mine
/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA7
* Date: 11/11/2017
* Description: here we have the implementation of an array based stack
*/
#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;

template <class T>
class Stack
{
public:
	Stack(int newSize = 0);
	~Stack();

	bool push(T &newItem);
	bool pop(T &poppedItem);
	bool peek(T &item);

	bool isEmpty();

	bool removeItem(T &find);

	void printToFile(ofstream &sf);
	void Stack<T>::printToScreen();

private:
	int mSize;
	int mMaxSize;
	T *mTop;
};

//this is the constructor for the templated class of list
template <class T>
Stack<T>::Stack(int newSize)
{
	mSize = newSize;
	mMaxSize = 365; // this value was chosen based on days in a year, 182/183 is usually the amount of days studied though
	mTop = new T[365];
}

//this is the destructor for the templated class of list
template <class T>
Stack<T>::~Stack()
{
	delete[] mTop;
}

//the push function is in charge of adding an item to a stack if there is enough space
template <class T>
bool Stack<T>::push(T &newItem)
{
	if (mSize != mMaxSize)
	{
		mTop[mSize] = newItem;
		mSize++;
		return true;
	}
	else
	{
		//cout << "Out of Space Mate!" << endl;
		return false;
	}
}

//this is the pop class, first check if list is empty and only after pop from it if not empty
template <class T>
bool Stack<T>::pop(T &poppedItem)
{
	if (isEmpty())
	{
		//cout << "Empty stack mate!" << endl;
		return false;
	}
	else
	{
		mSize--;
		poppedItem = mTop[mSize];
		return true;
	}
}

//the peek function is the function that allows a user to lookm at the last item imputed into the stack
template <class T>
bool Stack<T>::peek(T &item)
{
	if (isEmpty())
	{
		//cout << "Empty stack mate!" << endl;
		return false;
	}
	else
	{
		item = mTop[mSize - 1];
		return true;
	}
}

// Returns true if the stack is empty; false otherwise
template <class T>
bool Stack<T>::isEmpty()
{
	if (this->mSize == 0)
	{
		return true;
	}
	else return false;
}

//This function finds an item by poping an item and then pushing it into another stack until the
//right one is found or not and after placing all of it back in the right order
template <class T>
bool Stack<T>::removeItem(T &find)
{
	Stack<T> *tempStack = new Stack<T>();
	int i = 0;
	T temp;
	bool t;
	this->peek(temp);
	while (temp != find && !isEmpty())
	{
		this->pop(temp);
		tempStack->push(temp);
		i++;
		this->peek(temp);
	}
	if (isEmpty())
	{
		t = false;
	}
	else
	{
		t = true;
		this->pop(temp);
	}
	while (i != 0)
	{
		tempStack->pop(temp);
		this->push(temp);
		i--;
	}
	tempStack->~Stack();
	return t;
}

//prints all dates in reverse order to file to be read in latest first order
template <class T>
void Stack<T>::printToFile(ofstream &sf)
{
	Stack<T> *tempStack = new Stack<T>();
	int i = 0;
	T temp;
	while (!isEmpty())
	{
		this->pop(temp);
		tempStack->push(temp);
		i++;
	}
	while (i != 0)
	{
		tempStack->pop(temp);
		sf << temp << endl;
		this->push(temp);
		i--;
	}
	tempStack->~Stack();
}

//prints all to screen in reverse
template <class T>
void Stack<T>::printToScreen()
{
	Stack<T> *tempStack = new Stack<T>();
	int i = 0;
	T temp;
	while (!isEmpty())
	{
		this->pop(temp);
		tempStack->push(temp);
		i++;
	}
	while (i != 0)
	{
		tempStack->pop(temp);
		cout << temp << endl;
		this->push(temp);
		i--;
	}
	tempStack->~Stack();
}

#endif