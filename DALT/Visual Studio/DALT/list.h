#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>
using namespace std;
template <class Data>
class List
{
private:
	List* next;
	Data data;

public:
	int length;
	List();
	~List();
	Data& operator[](int);
	List<Data>& insertFirst(const Data&);
	List<Data>& findOneAndRemove(Data&);
};
#include "list.cpp"
#endif
