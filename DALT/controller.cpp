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

void Controllers::desk()
{
    switch (views.desk())
    {
    case 0:
        controllers.home();
        break;
    case 1:
        controllers.deskShow();
        break;
    case 2:
        controllers.deskAdd();
        break;
    case 3:
        controllers.deskRemove();
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

void Controllers::menuShow()
{
    views.menuShow();
    controllers.menu();
};
void Controllers::menuAdd()
{
    Menu temp;
    temp = views.menuAdd();
    table.menu.insertFirst(temp);
    controllers.menu();
};
void Controllers::menuRemove()
{
    Menu temp;
    temp = views.menuRemove();
    table.menu.findOneAndRemove(temp);
    controllers.menu();
};
void Controllers::deskShow()
{
    views.deskShow();
    controllers.desk();
}
void Controllers::deskAdd()
{
    Desk temp;
    temp = views.deskAdd();
    table.desk.insertFirst(temp);
    controllers.desk();
}
void Controllers::deskRemove()
{
    Desk temp;
    temp = views.deskRemove();
    table.desk.findOneAndRemove(temp);
    controllers.desk();
}