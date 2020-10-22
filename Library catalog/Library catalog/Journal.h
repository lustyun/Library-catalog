#ifndef JOURNAL_H
#define JOURNAL_H
#include "Item.h"
class Journal :public Item
{
public:
	Journal();
	~Journal();
	Journal(int id, string name, bool status, int vol);
	void setData(int id, string name, bool status, int volume);
	void setVol(int vol);
	int getVol() const;
	void print() const;

private:
	int Volume;
};
#endif