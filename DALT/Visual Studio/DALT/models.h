#ifndef MODELS_H
#define MODELS_H
#include <Windows.h>
#include <iostream>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include "list.h"
#include "table.h"
#include <string>
#include <cstring>
using namespace std;
class Models {

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
	string AND = "', '";
	string s = "'";

public:
	Models();
	~Models() {};
	void getAllMenu(List<Menu>& menus);
	void menuAdd(const Menu&);
	void menuRemove(const int&);
	void menuUpdate(const Menu&);
	wstring s2ws(const string& s);

};
#endif // !MODEL_H
