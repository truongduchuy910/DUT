#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <iomanip>
#include <string>
#include "tables.h"
#include "models.h"
using namespace std;
class DB;
template <typename Data>
class List;
template <typename Data>
class Node;
class Menu;

template <typename Data>
class Node
{
	friend class List<Data>;

public:
	Node(Data);
	Data getData();

private:
	Data data;
	Node* next;
};

template <typename Data>
Node<Data>::Node(Data dataIn)
{
	data = dataIn;
	next = NULL;
}

template <typename Data>
Data Node<Data>::getData()
{
	return data;
}

template <typename Data>
class List
{
public:
	List();
	~List();
	void insert(const Data&);
	void findAndRemove(const Data&);
	void print();

private:
	Node<Data>* start;
	bool isEmpty();
};

template <typename Data>
List<Data>::List()
{
	start = NULL;
}

template <typename Data>
List<Data>::~List()
{
	if (!isEmpty())
	{
		Node<Data>* currentNode = start;
		Node<Data>* temp;

		while (currentNode != 0)
		{
			temp = currentNode;
			currentNode = currentNode->next;
			delete temp;
		}
	}
}

template <typename Data>
bool List<Data>::isEmpty()
{
	if (start == NULL)
		return 1;
	else
		return 0;
}

template <typename Data>
void List<Data>::insert(const Data& dataIn)
{
	if (isEmpty())
	{
		Node<Data>* newNode = new Node<Data>(dataIn);
		start = newNode;
	}
	else
	{

		Node<Data>* newNode = new Node<Data>(dataIn);
		newNode->next = start;
		start = newNode;
	}
}

template <typename Data>
void List<Data>::findAndRemove(const Data& dataIn)
{
	Node<Data>* temp = this->start;
	while (temp != NULL && !(temp->data == dataIn))
	{
		temp = temp->next;
	}
	if (temp != NULL)
	{
		delete temp;
		start = start->next;
	}
}

template <typename Data>
void List<Data>::print()
{
	if (isEmpty())
	{
		cout << "The list is empty" << endl;
	}
	else
	{
		Node<Data>* currentNode = start;
		while (currentNode != NULL) //prints until the end of the list is reached
		{
			cout << currentNode->data << endl;
			currentNode = currentNode->next; //moves to next node in list
		}
	}
}
class DB
{
public:
	List<Menu> menus;
};
#endif
