#include "Item.h"
#include "Book.h"
#include "Magazine.h"
#include "Journal.h"
using namespace std;



//Destructor
Item::~Item()
{
}

//Defaut constructor
Item::Item()
{
	setID(0);
	setName("Unknown");
	setStatus(0);
}

//Paramaterized constructor
Item::Item(int id, string name, bool status)
{
	setData(id, name, status);
}

//Setting all the datas
void Item::setData(int id, string name, bool status)
{
	setID(id);
	setName(name);
	setStatus(status);
}
void Item::setID(int id)
{
	ID = id;
}
void Item::setName(string name)
{
	Name = name;
}
void Item::setStatus(int status)
{
	Status = status;
}

//Returning all the datas
int Item::getID() const
{
	return ID;
}
string Item::getName() const
{
	return Name;
}
bool Item::getStatus() const
{
	return Status;
}



//Prints all the data of an object
void Item::print() const
{
	string stat;
	if (Status == 0)
	{
		stat = "Available";
	}
	else
	{
		stat = "Not Available";
	}

	cout << left << setw(4) << ID << "| " << left << setw(45) << Name << "| " << left << setw(25) << stat;
}