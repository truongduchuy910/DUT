
int Views::home()
{
    
    cout << "---------- HOME ----------" << endl;
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
    
    cout << "---------- MENU ----------" << endl;
    int n;
    do
    {
        cout << "1. show" << endl;
        cout << "2. add" << endl;
        cout << "3. remove" << endl;
        cout << "4. back" << endl;
        cout << "Choose your option [1-4]: ";
        cin >> n;
    } while (n < 1 || n > 8);

    return n;
};
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
    } while (n < 1 || n > 8);

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
    } while (n < 1 || n > 8);

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
    } while (n < 1 || n > 8);

    return n;
};