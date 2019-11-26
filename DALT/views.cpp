
int Views::home()
{

    cout << "--------------- HOME CONTROL" << endl;
    int n;
    do
    {
        cout << "0. exit" << endl;
        cout << "1. menu" << endl;
        cout << "2. desk" << endl;
        cout << "3. order" << endl;
        cout << "4. bill" << endl;
        cout << "Choose your option [0-4]: ";
        cin >> n;
    } while (n < 0 || n > 8);

    return n;
}

int Views::menu()
{

    cout << "--------------- MENU CONTROL" << endl;
    int n;
    do
    {
        cout << "0. back" << endl;
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "Choose your option [0-3]: ";
        cin >> n;
    } while (n < 0 || n > 8);

    return n;
};
int Views::menuShow()
{
    cout << "--------------- MENU SHOW" << endl
         << "foodId name         cost" << endl;
    for (int i = 0; i < table.menu.length; i++)
    {
        cout << table.menu[i];
    }
}
Menu Views::menuAdd()
{
    Menu newMenu;
    cin >> newMenu;
    return newMenu;
}
Menu Views::menuRemove()
{
    Menu newMenu;
    cout << "--------------- MENU REMOVE" << endl;
    cout << "Input condition:" << endl;
    cin >> newMenu;
    return newMenu;
}
int Views::desk()
{
    cout << "--------------- DESK CONTROL" << endl;
    int n;
    do
    {
        cout << "0. back" << endl;
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "Choose your option [0-3]: ";
        cin >> n;
    } while (n < 0 || n > 8);

    return n;
};
int Views::deskShow()
{
    cout << "--------------- DESK SHOW" << endl
         << "deskId status" << endl;
    for (int i = 0; i < table.desk.length; i++)
    {
        cout << table.desk[i];
    }
}
Desk Views::deskAdd()
{
    cout << "--------------- DESK ADD" << endl;
    Desk newDesk;
    cin >> newDesk;
    return newDesk;
}
Desk Views::deskRemove()
{
    Desk newDesk;
    cin >> newDesk;
    return newDesk;
}
int Views::order()
{

    cout << "--------------- ORDER CONTROL" << endl;

    int n;
    do
    {
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "4. back" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 0 || n > 8);

    return n;
};
int Views::bill()
{

    cout << "--------------- BILL CONTROL" << endl;

    int n;
    do
    {
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "4. back" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 0 || n > 8);

    return n;
};