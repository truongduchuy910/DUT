void Controllers::home()
{
    switch (views.home())
    {
    case 1:
        controllers.menu();
        break;
    case 2:
        controllers.desk();
        break;
    case 3:
        controllers.order();
        break;
    case 4:
        controllers.bill();
        break;
    default:
        break;
    }
}
void Controllers::menu()
{
    switch (views.menu())
    {
    case 2:
        controllers.menuAdd();
        break;
    case 4:
        controllers.home();
        break;
    default:
        break;
    }
}
void Controllers::menuShow(){};
void Controllers::menuAdd()
{
    // table.menu.insert(views.menuAdd());
    // controllers.menu();
    cout << views.menuAdd();
    controllers.menu();
};
void Controllers::menuRemove(){};
void Controllers::desk()
{
    switch (views.desk())
    {
    case 4:
        controllers.home();
        break;
    default:
        break;
    }
}

void Controllers::order()
{
    switch (views.order())
    {
    case 4:
        controllers.home();
        break;
    default:
        break;
    }
}

void Controllers::bill()
{
    switch (views.bill())
    {
    case 4:
        controllers.home();
        break;
    default:
        break;
    }
}