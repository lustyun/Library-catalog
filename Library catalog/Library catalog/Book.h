#ifndef BOOK_H
#define BOOK_H
#include "Item.h"
class Book :public Item
{
public:
	Book();
	~Book();
	Book (int id, string name, bool status, string author);
	void setData(int id, string name, bool status, string author);
	void setAuthor(string author);
	string getAuthor() const;
	void print() const;

private:
	string Author_name;
};
#endif