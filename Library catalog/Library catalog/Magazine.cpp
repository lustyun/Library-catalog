#include "Magazine.h"

Magazine::~Magazine()
{
}
Magazine::Magazine()
{
	setIssue_number(0);
}
Magazine::Magazine(int id, string name, bool status, int issue)
	:Item(id, name, status)
{
	setIssue_number(issue);
}
void Magazine::setData(int id, string name, bool status, int issue)
{
	Item::setData(id, name, status);
	setIssue_number(issue);
}
void Magazine::setIssue_number(int issue)
{
	Issue_number = issue;
}
int Magazine::getIssue_number() const
{
	return Issue_number;
}
//Overloading print function
void Magazine::print() const
{
	Item::print();
	cout << "Issue Number: " << Issue_number << endl;
}
