//include the below additional libraries
#include <iostream>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <stdlib.h>

//use the std namespace
using namespace std;
int main()
{

#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000

    //define handles and variables
    SQLHANDLE sqlConnHandle;
    SQLHANDLE sqlStmtHandle;
    SQLHANDLE sqlEnvHandle;
    SQLCHAR retconstring[SQL_RETURN_CODE_LEN];

    //initializations
    sqlConnHandle = NULL;
    sqlStmtHandle = NULL;

    //allocations
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))

        if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))

            if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))

                //output
                cout << "Attempting connection to SQL Server...";
    cout << "\n";

    //connect to SQL Server
    //I am using a trusted connection and port 14808
    //it does not matter if you are using default or named instance
    //just make sure you define the server name and the port
    //You have the option to use a username/password instead of a trusted connection
    //but is more secure to use a trusted connection
    switch (SQLDriverConnect(sqlConnHandle,
                             NULL,
                             (SQLCHAR *)L"DRIVER={truongduchuy910};SERVER=localhost, 1433;DATABASE=DALT;UID=SA;PWD=Doanlaptrinh.;",
                             //(SQLCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=master;Trusted=true;",
                             SQL_NTS,
                             retconstring,
                             1024,
                             NULL,
                             SQL_DRIVER_NOPROMPT))
    {

    case SQL_SUCCESS:
        cout << "Successfully connected to SQL Server";
        cout << "\n";
        break;

    case SQL_SUCCESS_WITH_INFO:
        cout << "Successfully connected to SQL Server";
        cout << "\n";
        break;

    case SQL_INVALID_HANDLE:
        cout << "SQL_INVALID_HANDLE Could not connect to SQL Server";
        cout << "\n";

    case SQL_ERROR:
        cout << "SQL_ERROR Could not connect to SQL Server";
        cout << "\n";

    default:
        break;
    }

    //if there is a problem connecting then exit application
    if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))

        //output
        cout << "\n";
    cout << "Executing T-SQL query...";
    cout << "\n";
    int question = 1;
    cout << "You choice the sql command to execute: 1.SELECT, 2.INSERT, 3.UPDATE, 4.DELETE:";
    cin >> question;
    switch (question)
    {
    case 1:
        //if there is a problem executing the query then exit application
        //else display query result
        if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLCHAR *)L"SELECT * from TAIKHOAN WHERE sotien>= all (select sotien from taikhoan)", SQL_NTS))
        {
            cout << "Error querying SQL Server";
            cout << "\n";
        }
        else
        {
            char sotk[4];
            int sotien;
            cout << "TAI KHOAN CO SO TIEN CAO NHAT:"
                 << "\n";
            while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
            {
                SQLGetData(sqlStmtHandle, 1, SQL_C_CHAR, sotk, 4, NULL);
                SQLGetData(sqlStmtHandle, 2, SQL_C_LONG, &sotien, 4, NULL);

                cout << sotk << " " << sotien << endl;
            }
            break;
        case 2: //Insert
            if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLCHAR *)L"insert into RUT values (2, '11', 30)", SQL_NTS))
            {
                cout << "Error querying SQL Server";
                cout << "\n";
            }
            break;
        }
    }

//close connection and free resources
COMPLETED:
    SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
    SQLDisconnect(sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
    SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);

    //pause the console window - exit when key is pressed
    cout << "\nPress any key to exit...";
    getchar();
}