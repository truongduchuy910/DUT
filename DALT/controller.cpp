void Controllers::home()
{
    switch (views.home())
    {
    case 0:
        cout << "a du!!!! :v";
        break;
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
    case 0:
        controllers.home();
        break;
    case 1:
        controllers.menuShow();
    case 2:
        controllers.menuAdd();
        break;
    case 3:
        controllers.menuRemove();
        break;    
    
    default:
        break;
    }
}
void Controllers::menuShow()
{
    cout << table.menu;
    controllers.menu();
};
void Controllers::menuAdd()
{
    // table.menu.insert(views.menuAdd());
    // controllers.menu();
    table.menu = views.menuAdd();
    controllers.menu();
};
void Controllers::menuRemove()
{
    views.menuRemove();
    controllers.menu();
};
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
    case 2:
    case 4:
        controllers.home();
        break;
    default:
        break;
    }
}