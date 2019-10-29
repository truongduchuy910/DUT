
int Views::home()
{
    system("clear");
    cout << "---------- HOME ----------" << endl;
    cout << "Welcome to Summoner’s Rift" << endl;
    int n;
    do
    {
        cout << "1. menu" << endl;
        cout << "2. desk" << endl;
        cout << "3. order" << endl;
        cout << "4. bill" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 1 || n > 8);

    return n;
}

int Views::menu()
{
    system("clear");
    cout << "---------- MENU ----------" << endl;
    int n;
    do
    {
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "4. bach" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 1 || n > 8);

    return n;
};
int Views::desk()
{
    system("clear");
    cout << "---------- DESK ----------" << endl;

    int n;
    do
    {
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "4. bach" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 1 || n > 8);

    return n;
};
int Views::order()
{
    system("clear");
    cout << "---------- ORDER ----------" << endl;

    int n;
    do
    {
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "4. bach" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 1 || n > 8);

    return n;
};
int Views::bill()
{
    system("clear");
    cout << "---------- BILL ----------" << endl;

    int n;
    do
    {
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "4. bach" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 1 || n > 8);

    return n;
};