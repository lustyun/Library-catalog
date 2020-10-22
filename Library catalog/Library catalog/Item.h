#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Item
{
public:
	Item();
	virtual ~Item();
	Item (int id, string name, bool status);
	void setData(int id, string name, bool status);
	void setID(int id);
	void setName(string name);
	void setStatus(int status);
	int getID() const;
	virtual string getName() const;
	bool getStatus() const;
	virtual void print() const;

private:
	int ID;
	string Name;
	bool Status;
};
#endif