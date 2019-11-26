
int Views::home()
{

    cout << "---------- HOME ----------" << endl;
    int n;
    do
    {
        cout << "0. exit" << endl;
        cout << "1. menu" << endl;
        cout << "2. desk" << endl;
        cout << "3. order" << endl;
        cout << "4. bill" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 0 || n > 8);

    return n;
}

int Views::menu()
{

    cout << "---------- MENU ----------" << endl;
    int n;
    do
    {
        cout << "0. back" << endl;
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 0|| n > 8);

    return n;
};
int Views::menuShow()
{
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
    cout << "---------- REMOVE MENU ----------" << endl;
    cout << "Input condition:" << endl;
    cin >> newMenu;
    return newMenu;
}
int Views::desk()
{

    cout << "---------- DESK ----------" << endl;

    int n;
    do
    {
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "4. back" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 0|| n > 8);

    return n;
};
int Views::order()
{

    cout << "---------- ORDER ----------" << endl;

    int n;
    do
    {
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "4. back" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 0|| n > 8);

    return n;
};
int Views::bill()
{

    cout << "---------- BILL ----------" << endl;

    int n;
    do
    {
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "4. back" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 0|| n > 8);

    return n;
};