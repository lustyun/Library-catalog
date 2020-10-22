#include "Book.h"

Book::~Book()
{

}
Book::Book()
{
	setAuthor("Uknown");
}
Book::Book(int id, string name, bool status, string author)
	:Item(id, name, status)
{
	setAuthor(author);
}
void Book::setData(int id, string name, bool status, string author)
{
	Item::setData(id, name, status);
	setAuthor(author);
}
void Book::setAuthor(string author)
{
	Author_name = author;
}
string Book::getAuthor() const
{
	return Author_name;
}
//Overloading print function
void Book::print() const
{
	Item::print();
	cout << "Author Name: " << Author_name << endl;
}