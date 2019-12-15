#ifndef LIST_H
#define LIST_H
#include <Windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "tables.h"
//#include "models.h"
using namespace std;
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
};
class Models {
public:

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
	string AND = "', '";
	string s = "'";

	Models();
	~Models() {};
	void get(List<Menu>&);
	//void menuShow(List<Menu>& menus);
	//void menuAdd(const Menu&);
	//void menuRemove(const int&);
	//void menuUpdate(const Menu&);

	wstring s2ws(const string& s);

};
Models::Models() {

	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	cout << "Connecting   0%... Initialize." << endl;
	if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle)) {
		cout << "Connecting  15%... SQLAllocHandle." << endl;
	}
	if (SQL_SUCCESS == SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) {
		cout << "Connecting  30%... SQLSetEnvAttr." << endl;
	}
	if (SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle)) {
		cout << "Connecting  45%... SQLAllocHandle." << endl;
	}
	switch (SQLDriverConnect(sqlConnHandle,
		NULL,
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost;DATABASE=qlNhaHang;Trusted=true;UID=sa;PWD=truongduc910",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT))
	{
	case SQL_SUCCESS:
		cout << "Connecting  95%... Successfully connected to SQL Server." << endl;
		break;
	case SQL_SUCCESS_WITH_INFO:
		cout << "Connecting  95%... Successfully connected to SQL Server." << endl;
		break;
	default:
		cout << "Connecting fail... Could not connect to SQL Server." << endl;
		break;
	}
	cout << "Connecting 100%... Ready to query." << endl;
}

void Models::get(List<Menu>& menus) {
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM MENU", SQL_NTS)) {
		SQLCHAR sqlVersion[SQL_RESULT_LEN];
		SQLINTEGER ptrSqlVersion;
		Menu temp;
		cout << "Quering..." << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.foodId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, &temp.name, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_DOUBLE, &temp.cost, SQL_RESULT_LEN, &ptrSqlVersion);
			menus.insert(temp);
		}
		cout << "Quering done!" << endl;
	}
	else {
		cout << "fail" << endl;
	}
}
//void Models::menuAdd(const Menu& menu) {
//	string command = "INSERT INTO MENU (FoodName, Cost) VALUES('";
//	command += string(menu.name) + AND + to_string(menu.cost);
//	command += "')";
//	std::wstring stemp = s2ws(command);
//	LPCWSTR result = stemp.c_str();
//	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
//	switch (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS)) {
//	case SQL_SUCCESS:
//		cout << "[INSERT] Successful!" << endl;
//		break;
//	case SQL_SUCCESS_WITH_INFO:
//		cout << "[INSERT] Successful!" << endl;
//		break;
//	default:
//		cout << "[INSERT] Fail!" << endl;
//		break;
//	}
//}
//void Models::menuRemove(const int& foodId) {
//	string command = "DELETE FROM MENU WHERE FoodId = '" + to_string(foodId) + s;
//	cout << command << endl;
//	std::wstring stemp = s2ws(command);
//	LPCWSTR result = stemp.c_str();
//	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
//	switch (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS)) {
//	case SQL_SUCCESS:
//		cout << "[DELETE] Successful!" << endl;
//		break;
//	case SQL_SUCCESS_WITH_INFO:
//		cout << "[DELETE] Successful!" << endl;
//		break;
//	default:
//		cout << "[DELETE] Fail!" << endl;
//		break;
//	}
//}
//void Models::menuUpdate(const Menu& menu) {
//	string command = "UPDATE MENU SET FoodName = '";
//	command += string(menu.foodName) + s;
//	command += ", Cost = '";
//	command += to_string(menu.cost) + s;
//	command += " WHERE FoodId = '";
//	command += to_string(menu.foodId) + s;
//	std::wstring stemp = s2ws(command);
//	LPCWSTR result = stemp.c_str();
//	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
//	switch (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS)) {
//	case SQL_SUCCESS:
//		cout << "[UPDATE] Successful!" << endl;
//		break;
//	case SQL_SUCCESS_WITH_INFO:
//		cout << "[UPDATE] Successful!" << endl;
//		break;
//	default:
//		cout << "[UPDATE] Fail!" << endl;
//		break;
//	}
//}
wstring Models::s2ws(const string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	wstring r(buf);
	delete[] buf;
	return r;
}
#endif
