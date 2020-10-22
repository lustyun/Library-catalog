#include "Journal.h"

Journal::~Journal()
{

}
Journal::Journal()
{
	setVol(0);
}
Journal::Journal(int id, string name, bool status, int vol)
	:Item(id, name, status)
{
	setVol(vol);
}
void Journal::setData(int id, string name, bool status, int volume)
{
	Item::setData(id, name, status);
	setVol(volume);
}
void Journal::setVol(int vol)
{
	Volume = vol;
}
int Journal::getVol() const
{
	return Volume;
}
//Overloading print function
void Journal::print() const
{
	Item::print();
	cout << "Volume: " << Volume << endl;
}