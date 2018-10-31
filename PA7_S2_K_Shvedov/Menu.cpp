#include "Menu.h"
/*
* Programmer: Konstantin Shvedov
* Class: CptS 122
* Programming Assignment: PA7
* Date: 11/11/2017
* Description: here we have the implementation of the Menu
*/

//menu constructor
Menu::Menu()
{
	//empty
}

//menu destructor
Menu::~Menu()
{
	//empty
}

//runs the app
void Menu::runApp(void)
{
	mcDate = createCurrDate();
	char yon;
	ListNode *temp;
	int choice = 0;
	cout << "Welcome to the Attendance Tracker" << endl;
	system("pause");
	system("cls");
	while (choice != 7)
	{
		displayMenu();
		cout << "\nPlease select an option (1-7): ";
		cin >> choice;
		cout << endl;
		system("cls");
		//retrieves student info from csv
		if (choice == 1)
		{
			ifstream file;
			ListNode *newN = nullptr;
			file.open("classList.csv");
			if (file.is_open())
			{
				masterList.~List();
				masterList.setFrontPointer(newN);
				importCourses(file);
				file.close();
				cout << "Student Info Retrieved" << endl;
			}
			else
			{
				cout << "There was an error reading file" << endl;
			}
		}
		//retrieves students infor from master.txt
		else if (choice == 2)
		{
			ifstream file;
			ListNode *newN = nullptr;
			file.open("master.txt");
			if (file.is_open())
			{
				masterList.~List();
				masterList.setFrontPointer(newN);
				loadMasterList(file);
				file.close();
				cout << "Student Info Retrived" << endl;
			}
			else
			{
				cout << "There was an error reading file" << endl;
			}
		}
		//prints stduents info to master.txt
		else if (choice == 3)
		{
			if (!masterList.isEmpty())
			{
				ofstream file;
				file.open("master.txt");
				if (file.is_open())
				{
					storeMasterList(file);
					file.close();
					cout << "Student Info saved to master.txt" << endl;
				}
				else
				{
					cout << "There was an error reading file" << endl;
				}
			}
			else
			{
				cout << "Master List is currently empty, nothing to print to the txt" << endl;
			}
		}
		//promts user student by student if someone is presant or absent
		else if (choice == 4)
		{
			if (!masterList.isEmpty())
			{
				temp = masterList.getFrontPointer();
				while (temp != nullptr)
				{
					cout << *temp;
					cout << "Is the student absent(type y or n): ";
					cin >> yon;
					if (yon == 'y')
					{
						temp->addAbs();
						temp->addLabs(mcDate);
					}
					cout << endl << endl;
					temp = temp->getNextPtr();
				}
			}
			else
			{
				cout << "Master List is currently empty, no students to mark absent" << endl;
			}
		}
		//prompts user to either inout name or id and then asks what date should be removed
		else if (choice == 5)
		{
			if (!masterList.isEmpty())
			{
				string rDate;
				temp = masterList.getFrontPointer();
				cout << "Searching by:" << endl;
				cout << "1.\tStudent ID\n2.\tStudent Name" << endl;
				cout << "Please choose what you are going to search by (1 or 2): ";
				cin >> yon;
				cout << endl;
				if (yon == '1')
				{
					int id;
					cout << "Please input full Student ID: ";
					cin >> id;
					while (temp != nullptr && temp->getidNumb() != id)
					{
						temp = temp->getNextPtr();
					}
					if (temp == nullptr)
					{
						cout << "Student ID not found" << endl;
					}
					else
					{
						cout << "Please input date to be removed(format: yyyy/mm/dd): ";
						cin >> rDate;
						if (temp->getLAbs()->removeItem(rDate))
						{
							cout << endl << "Date has been removed" << endl;
							temp->setAbs(temp->getAbs() - 1);
						}
						else
						{
							cout << endl << "Date Not Found" << endl;
						}
					}
				}
				else if (yon == '2')
				{
					string name;
					cout << "Please input full Student Name (format(no spaces): Last,First): ";
					cin >> name;
					while (temp != nullptr && temp->getName() != name)
					{
						temp = temp->getNextPtr();
					}
					if (temp == nullptr)
					{
						cout << "Student Name not found" << endl;
					}
					else
					{
						cout << "Please input date to be removed(format: yyyy/mm/dd): ";
						cin >> rDate;
						if (temp->getLAbs()->removeItem(rDate))
						{
							cout << endl << "Date has been removed" << endl;
							temp->setAbs(temp->getAbs() - 1);
						}
						else
						{
							cout << endl << "Date Not Found" << endl;
						}
					}
				}
				else
				{
					cout << "invalid input";
				}
			}
			else
			{
				cout << "Master List is currently empty, no students to edit" << endl;
			}
		}
		//propts the user to choose a report type and prints it both to screen or to a .txt file
		else if (choice == 6)
		{
			if (!masterList.isEmpty())
			{
				temp = masterList.getFrontPointer();
				cout << "Types of report:" << endl;
				cout << "1.\tStudents and latest absence\n2.\tStudents absent more than..." << endl;
				cout << "Please choose what you are going to search by (1 or 2): ";
				cin >> yon;
				cout << endl;
				if (yon == '1')
				{
					ofstream file;
					file.open("reportType1.txt");
					string printDate;
					if (file.is_open())
					{
						file << "Last,First,#Absences,Latest absence" << endl;
						while (temp != nullptr)
						{
							printDate = "";
							temp->getLAbs()->peek(printDate);
							file << temp->getName() << "," << temp->getAbs() << "," << printDate << endl;
							cout << temp->getName() << "," << temp->getAbs() << "," << printDate << endl;
							temp = temp->getNextPtr();
						}

						file.close();
						cout << endl <<"Report printed to reportType1.txt" << endl;
					}
					else
					{
						cout << "There was an error reading file" << endl;
					}
				}
				else if (yon == '2')
				{
					ofstream file;
					file.open("reportType2.txt");
					string printDate;
					if (file.is_open())
					{
						int i = 0;
						cout << "Choose a threshold for absences to make report: ";
						cin >> i;
						cout << endl;
						while (temp != nullptr)
						{
							if (temp->getAbs() > i)
							{
								file << temp->getName() << endl;
								cout << temp->getName() << endl;
								temp->getLAbs()->printToScreen();
								cout << endl;
								temp->getLAbs()->printToFile(file);
								file << endl;
							}
							temp = temp->getNextPtr();
						}

						file.close();
						cout << "Report printed to reportType2.txt" << endl;
					}
					else
					{
						cout << "There was an error reading file" << endl;
					}

				}
				else
				{
					cout << "Invalid Input" << endl;
				}
			}
			else
			{
				cout << "Master List is currently empty, no students to make a report of" << endl;
			}
		}
		//exits the program
		else if (choice == 7)
		{
			cout << "Thank you for using this program!" << endl << endl;
			return;
		}
		else if (choice != 7)
		{
			cout << "Invalid Input, please try again" << endl;
			choice = 0;
		}
		system("pause");
		system("cls");
	}
}

//inserts infor from csv
void Menu::importCourses(ifstream &fileStream)
{
	string temp;
	getline(fileStream, temp);
	while (!fileStream.eof())
	{
		masterList.insertAtFront(masterList.makeNode(fileStream));
	}
}

//loads student info from master.txt
void Menu::loadMasterList(ifstream &fs)
{
	ListNode *newNode;
	while (!fs.eof())
	{
		newNode = masterList.makeMasterListNode(fs);
		if (newNode->getName() == "NA")
		{
			delete(newNode);
			ListNode *newNode;
		}
		else
		{
			masterList.insertAtFront(newNode);
		}
	}
}

//stores students info to master.txt
void Menu::storeMasterList(ofstream &fs)
{
	ListNode *temp;
	temp = masterList.getFrontPointer();
	while (temp != nullptr)
	{
		fs << *temp;
		if (temp->getAbs() != 0)
		{
			temp->getLAbs()->printToFile(fs);
		}
		temp = temp->getNextPtr();
		fs << endl;
	}
}

//displays the menu options
void Menu::displayMenu(void)
{
	cout << "1.\tImport course list" << endl;
	cout << "2.\tLoad master list" << endl;
	cout << "3.\tStore master list" << endl;
	cout << "4.\tMark absences" << endl;
	cout << "5.\tEdit absences" << endl;
	cout << "6.\tGenerate report" << endl;
	cout << "7.\tExit" << endl;
}

//creates a string of the current dat in the format of yyyy/mm/dd
string Menu::createCurrDate(void) const
{
	// retrieved from stackoverflow - http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	//edited to suit my needs from here on
	string date;
	date = to_string(now->tm_year + 1900);
	date += "/";
	date += to_string(now->tm_mon + 1);
	date += "/";
	date += to_string(now->tm_mday);
	return date;
}