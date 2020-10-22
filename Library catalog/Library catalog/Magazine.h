#ifndef MEGAZINE_H
#define MEGAZINE_H
#include "Item.h"
class Magazine :public Item
{
public:
	Magazine();
	~Magazine();
	Magazine (int id, string name, bool status, int issue);
	void setData(int id, string name, bool status, int issue);
	void setIssue_number(int issue);
	int getIssue_number() const;
	void print() const;

private:
	int Issue_number;
};
#endif