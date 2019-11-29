class SqlConnect
{
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
public:
	void init();
    void getTableName();
	void close();
};
