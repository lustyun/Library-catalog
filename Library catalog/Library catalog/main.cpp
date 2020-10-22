#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "Book.h"
#include "Magazine.h"
#include "Journal.h"
using namespace std;

vector<Book> book;
vector<Journal> jour;
vector<Magazine> mag;
void Search();
void Checkout();
void Return();
void AddItem();
void searchbyname();
void displayChoices();

void runProgram()
{
	//Load all the items when program runs.
	Magazine a(1, "Wired", 0, 3);
	mag.push_back(a);
	Magazine b(2, "Real Simple", 0, 6);
	mag.push_back(b);
	Magazine c(3, "The Economist", 0, 7);
	mag.push_back(c);
	Magazine d(4, "Cook's Illustrated", 0, 4);
	mag.push_back(d);
	Magazine e(5, "Esquire", 0, 2);
	mag.push_back(e);

	Journal a1(1, "Molecular Biology and Evolution", 0, 3);
	jour.push_back(a1);
	Journal b1(2, "Marine Mammals", 0, 5);
	jour.push_back(b1);
	Journal c1(3, "Deep Learning Applications", 0, 2);
	jour.push_back(c1);
	Journal d1(4, "Compiler Design", 0, 1);
	jour.push_back(d1);
	Journal e1(5, "Rapid Roboting", 0, 4);
	jour.push_back(e1);

	Book a2(1, "Harry Potter and the Sorcerer's Stone", 0, "J.K. Rowling");
	book.push_back(a2);
	Book b2(2, "Harry Potter and the Chamber of Secrets", 0, "J.K. Rowling");
	book.push_back(b2);
	Book c2(3, "Harry Potter and the Prisoner of Azkaban", 0, "J.K. Rowling");
	book.push_back(c2);
	Book d2(4, "Harry Potter and the Goblet of Fire", 0, "J.K. Rowling");
	book.push_back(d2);
	Book e2(5, "Harry Potter and the Order of the Phoenix", 0, "J.K. Rowling");
	book.push_back(e2);

	string trash = "";
	char action = 0;


	//Implementing the main menu for the user
	while (true)
	{
		try
		{
			displayChoices();
			cout << "\nPlease select: ";
			cin >> action;
			getline(cin, trash);

			switch (action)
			{
			case '1':
				Search();
				break;
			case '2':
				Checkout();
				break;
			case '3':
				Return();
				break;
			case '4':
				AddItem();
				break;
			case '5':
				return;
			default:
				cout << "Invalid Input. Try again.\n";
			}
		}
		catch (exception e)
		{
			cout << e.what() << endl;
			cin.clear();
			getline(cin, trash);
		}
	}
}

//Show the user the menu choices
void displayChoices()
{
	cout << "1. Search Catalog" << endl;
	cout << "2. Check out" << endl;
	cout << "3. Return" << endl;
	cout << "4. Add a new item " << endl;
	cout << "5. Exit" << endl;
}

//User adding items based on item types
void AddItem()
{
	string type, name, author;
	int id, vol, issuenum;

	cout << "What kind of an item would you like to add?(Book, Magazine, or Journal): ";
	cin >> type;
	cout << endl << "Enter the name of the item you want to add: ";
	cin.ignore();
	getline(cin, name);
	cout << endl << "Enter the ID number of " << name << ": ";
	cin >> id;

	//Exception incase user enters string instead of int
	while (!cin)
	{
		cout << "Invalid input. Please enter an integer: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> id;
	}
	if (type == "Book")
	{
		cout << endl << "Enter the author of " << name << ": ";
		cin.ignore();
		getline(cin, author);
		//Insert a new book object
		Book b(id, name, 0, author);
		book.push_back(b);
	}
	else if (type == "Magazine")
	{
		cout << endl << "Enter the issue number of " << name << ": ";
		cin >> issuenum;
		//Exception incase user enters string instead of int
		while (!cin)
		{
			cout << "Invalid input. Please enter an integer: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> issuenum;
		}
		//Insert a new magazine object
		Magazine m(id, name, 0, issuenum);
		mag.push_back(m);
	}
	else if (type == "Journal")
	{
		cout << endl << "Enter the volume number of " << name << ": ";
		cin >> vol;
		//Exception incase user enters string instead of int
		while (!cin)
		{
			cout << "Invalid input. Please enter an integer: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> vol;
		}
		//Insert a new journal object
		Journal j(id, name, 0, vol);
		jour.push_back(j);
	}
	else
		cout << "Invalid item type." << endl;
}

//Search by name of the item.
void searchbyname()
{
	char action = 0;
	char item = 0;
	bool exist = false;
	string name;
	string itemtype;

	vector<Book>::iterator it;
	vector<Magazine>::iterator it2;
	vector<Journal>::iterator it3;

	cout << "1. Book" << endl;
	cout << "2. Magazine" << endl;
	cout << "3. Journal" << endl << endl;
	cin >> action;

	//Searches for an item and checks and prints it if it exists

	switch (action)
	{
	case '1':
		cout << "Enter the name of the item: ";
		cin.ignore();
		getline(cin, name);
		cout << endl << "ID: | Name:                                        |  Status:" << endl;
		cout << "======================================================================================================" << endl;
		for (it = book.begin(); it < book.end(); it++)
		{
			if (it->getName() == name)
			{
				cout << "Item found!" << endl;

				it->print();
				exist = true;
			}
		}
		break;
	case '2':
		cout << "Enter the name of the item: ";
		cin.ignore();
		getline(cin, name);
		cout << endl << "ID: | Name:                                        |  Status:" << endl;
		cout << "======================================================================================================" << endl;
		for (it2 = mag.begin(); it2 < mag.end(); it2++)
		{
			if (it2->getName() == name)
			{
				cout << "Item found!" << endl;

				it2->print();
				exist = true;
			}
		}
		break;
	case '3':
		cout << "Enter the name of the item: ";
		cin.ignore();
		getline(cin, name);
		cout << endl << "ID: | Name:                                        |  Status:" << endl;
		cout << "======================================================================================================" << endl;
		for (it3 = jour.begin(); it3 < jour.end(); it3++)
		{
			if (it3->getName() == name)
			{
				cout << "Item found!" << endl;

				it3->print();
				exist = true;
			}
		}
		break;
		cout << endl;
	default:
		cout << "Invalid Input. Try again.\n";
		exist = true;
	}
	if (exist == false)
		cout << "This item does not exist." << endl;
	cout << endl;
}
//User can search by the name of the item or type if the item
void Search()
{
	char action = 0;
	char item = 0;
	bool exist = false;
	string name;
	string itemtype;

	vector<Book>::iterator it;
	vector<Magazine>::iterator it2;
	vector<Journal>::iterator it3;

	cout << "1. Search an item by name" << endl;
	cout << "2. List items by category" << endl;
	cout << "3. Search an item by author" << endl << endl;
	cin >> action;

	switch (action)
	{
	case '1':
	{
		searchbyname();
		break;
	}

	case '2':
		exist = false;
		cout << "Which item type would you like to print?(Book, Magazine, Journal): ";
		cin >> itemtype;

		//Prints by type
		cout << endl << "ID: | Name:                                        |  Status:" << endl;
		cout << "======================================================================================================" << endl;
		for (it = book.begin(); it < book.end(); it++)
		{
			if (itemtype == "Book" || itemtype == "book")
			{
				it->print();
				exist = true;
			}
		}
		for (it2 = mag.begin(); it2 < mag.end(); it2++)
		{
			if (itemtype == "Magazine" || itemtype == "magazine")
			{
				it2->print();
				exist = true;
			}
		}
		for (it3 = jour.begin(); it3 < jour.end(); it3++)
		{
			if (itemtype == "Journal" || itemtype == "journal")
			{
				it3->print();
				exist = true;
			}
		}
		if (exist == false)
			cout << "Invalid item type." << endl;
		cout << endl;
		break;

	case '3':
		exist = false;
		cout << "Enter the name of the author: ";
		cin.ignore();
		getline(cin, name);

		//Searches for an item and checks and prints it if it exists
		for (it = book.begin(); it < book.end(); it++)
		{
			if (it->getAuthor() == name)
			{
				cout << "Item found!" << endl;
				cout << endl << "ID: | Name:                                        |  Status:" << endl;
				cout << "======================================================================================================" << endl;
				it->print();
				exist = true;
			}
		}
			if (exist == false)
				cout << "This item does not exist." << endl;
		cout << endl;
		break;
		return;
	default:
		cout << "Invalid Input. Try again.\n";
	}
}

//Changes the status of the item when checked out. Cannot check out if has already been checked out
void Checkout()
{
	searchbyname();

	string name;
	cout << "Enter the name of the item you would like to checkout: ";
	getline(cin, name);
	bool exist = false;
	
	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].getName() == name)
		{
			if (book[i].getStatus() == 1)
			{
				cout << "This item has already been checked out." << endl;
			}
			else
			{
				cout << name << " has been checked out." << endl;
				book[i].setStatus(1);
			}
			exist = true;
		}
	}
	for (int i = 0; i < mag.size(); i++)
	{
		if (mag[i].getName() == name)
		{
			if (mag[i].getStatus() == 1)
			{
				cout << "This item has already been checked out." << endl;
			}
			else
			{
				cout << name << " has been checked out." << endl;
				mag[i].setStatus(1);
			}
			exist = true;
		}
	}	
	for (int i = 0; i < jour.size(); i++)
	{
		if (jour[i].getName() == name)
		{
			if (jour[i].getStatus() == 1)
			{
				cout << "This item has already been checked out." << endl;
			}
			else
			{
				cout << name << " has been checked out." << endl;
				jour[i].setStatus(1);
			}
			exist = true;
		}
	}
	if (exist == false)
		cout << "This item does not exist." << endl;
	cout << endl;
}

//Changes the status of the item when returned. Cannot return if has already been returned
void Return()
{
	searchbyname();

	string name;
	cout << "Enter the name of the item you would like to return: ";
	getline(cin, name);
	bool exist = false;

	for (int i = 0; i < book.size(); i++)
	{
		if (book[i].getName() == name)
		{
			if (book[i].getStatus() == 0)
			{
				cout << "You can't return an item that hasn't been checked out." << endl;
			}
			else
			{
				cout << name << " has been returned." << endl;
				book[i].setStatus(0);
			}
			exist = true;
		}
	}
	for (int i = 0; i < mag.size(); i++)
	{
		if (mag[i].getName() == name)
		{
			if (mag[i].getStatus() == 0)
			{
				cout << "You can't return an item that hasn't been checked out." << endl;
			}
			else
			{
				cout << name << " has been returned." << endl;
				mag[i].setStatus(0);
			}
			exist = true;
		}
	}
	for (int i = 0; i < jour.size(); i++)
	{
		if (jour[i].getName() == name)
		{
			if (jour[i].getStatus() == 0)
			{
				cout << "You can't return an item that hasn't been checked out." << endl;
			}
			else
			{
				cout << name << " has been returned." << endl;
				jour[i].setStatus(0);
			}
			exist = true;
		}
	}
	if (exist == false)
		cout << "This item does not exist." << endl;
	cout << endl;
}

int main()
{
	//Runs the entire program
	runProgram();
	return 0;
}