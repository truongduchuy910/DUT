#ifndef TABLES_H
#define TABLES_H

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Menu;
class Menu
{
public:
	int foodId;
	string name;
	double cost;
	Menu()
	{
		this->foodId = 0;
		this->cost = 0.0;
	}
	static void head()
	{
		cout << setw(6) << "foodId" << setw(6) << "name" << setw(6) << "cost" << endl;
	}
	const bool operator==(const Menu&);
	friend ostream& operator<<(ostream&, const Menu&);
	friend istream& operator>>(istream&, Menu&);
};
const bool Menu::operator==(const Menu& menu)
{
	if (this->foodId == menu.foodId)
	{
		return true;
	}
	else
	{
		return false;
	}
};

ostream& operator<<(ostream& os, const Menu& menu)
{
	os << setw(6) << menu.foodId << setw(6) << menu.name << setw(6) << menu.cost;
	return os;
}
istream& operator>>(istream& is, Menu& menu)
{
	cout << "name: ";
	is.ignore();
	getline(is, menu.name);
	cout << "cost: ";
	is >> menu.cost;
	return is;
}
#endif
