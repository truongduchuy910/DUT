#ifndef MODELS_CPP
#define MODELS_CPP
#include "models.h"
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

void Models::getAllMenu(List<Menu>& menus) {
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM MENU", SQL_NTS)) {
		SQLCHAR sqlVersion[SQL_RESULT_LEN];
		SQLINTEGER ptrSqlVersion;
		Menu temp;
		cout << "Quering..." << endl;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &temp.foodId, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, &temp.foodName, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_DOUBLE, &temp.cost, SQL_RESULT_LEN, &ptrSqlVersion);
			menus.insertFirst(temp);
		}
		cout << "Quering done!" << endl;
	}
	else {
		cout << "fail" << endl;
	}
}void Models::menuAdd(const Menu& menu) {
	string command = "INSERT INTO MENU (FoodName, Cost) VALUES('";
	command += string(menu.foodName) + AND + to_string(menu.cost);
	command += "')";
	std::wstring stemp = s2ws(command);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	switch (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS)) {
	case SQL_SUCCESS:
		cout << "[INSERT] Successful!" << endl;
		break;
	case SQL_SUCCESS_WITH_INFO:
		cout << "[INSERT] Successful!" << endl;
		break;
	default:
		cout << "[INSERT] Fail!" << endl;
		break;
	}
}
void Models::menuRemove(const int& foodId) {
	string command = "DELETE FROM MENU WHERE FoodId = '" + to_string(foodId) + s;
	cout << command << endl;
	std::wstring stemp = s2ws(command);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	switch (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS)) {
	case SQL_SUCCESS:
		cout << "[DELETE] Successful!" << endl;
		break;
	case SQL_SUCCESS_WITH_INFO:
		cout << "[DELETE] Successful!" << endl;
		break;
	default:
		cout << "[DELETE] Fail!" << endl;
		break;
	}
}
void Models::menuUpdate(const Menu& menu) {
	string command = "UPDATE MENU SET FoodName = '";
	command += string(menu.foodName) + s;
	command += ", Cost = '";
	command += to_string(menu.cost) + s;
	command += " WHERE FoodId = '";
	command += to_string(menu.foodId) + s;
	std::wstring stemp = s2ws(command);
	LPCWSTR result = stemp.c_str();
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	switch (SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)result, SQL_NTS)) {
	case SQL_SUCCESS:
		cout << "[UPDATE] Successful!" << endl;
		break;
	case SQL_SUCCESS_WITH_INFO:
		cout << "[UPDATE] Successful!" << endl;
		break;
	default:
		cout << "[UPDATE] Fail!" << endl;
		break;
	}
}
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