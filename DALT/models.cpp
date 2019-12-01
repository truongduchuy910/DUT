void SqlConnect::init()
{
	cout << "00%... initialize connecting." << endl;
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		close();
	else
		cout << " 15%... SQLAllocHandle." << endl;

	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		close();
	else
		cout << " 30%... SQLSetEnvAttr." << endl;
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
		close();
	else
		cout << " 45%... SQLAllocHandle. Attempting connection to SQL Server." << endl;
	switch (SQLDriverConnect(sqlConnHandle,
							 NULL,
							 (SQLWCHAR *)L"DRIVER={SQL Server};SERVER=DESKTOP-H0668TV;DATABASE=DALT;Trusted=true;UID=sa;PWD=truongduc910",
							 SQL_NTS,
							 retconstring,
							 1024,
							 NULL,
							 SQL_DRIVER_NOPROMPT))
	{

	case SQL_SUCCESS:
		cout << "100%... Successfully connected to SQL Server." << endl;
		break;

	case SQL_SUCCESS_WITH_INFO:
		cout << "100%... Successfully connected to SQL Server." << endl;
		break;
	default:
		cout << "Error:  Could not connect to SQL Server";
		cout << "\n";
		close();
		break;
	}
}
void SqlConnect::getTableName()
{

	if (SQL_SUCCESS == SQLExecDirect(sqlStmtHandle, (SQLWCHAR *)L"SELECT * FROM sys.tables", SQL_NTS) && SQL_SUCCESS == SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
	{

		SQLCHAR sqlVersion[SQL_RESULT_LEN];
		SQLINTEGER ptrSqlVersion;
		// char name[64];

		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
		{
			// SQLGetData(sqlStmtHandle, 1, SQL_CHAR, name, SQL_RESULT_LEN, (SQLLEN*)&ptrSqlVersion);
		}
	}
	else
	{
		cout << "Error querying SQL Server" << endl;
		close();
	}
}
void SqlConnect::close()
{
	cout << "Disconnect SQL Server!" << endl;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	exit(0);
}
