#ifndef CONTROLLERS_CPP
#define CONTROLLERS_CPP
#include "controller.h"
void Controllers::home()
{
	switch (views.home())
	{
	case 0:
		cout << "a du!!!! :v";
		break;
	case 1:
		menu();
		break;
		/* case 2:
			 desk();
			 break;
		 case 3:
			 order();
			 break;
		 case 4:
			 bill();
			 break;*/
	default:
		break;
	}
}
void Controllers::menu()
{
	switch (views.menu())
	{
	case 0:
		home();
		break;
	case 1:
		menuShow();
		break;
	case 2:
		menuAdd();
		break;
	case 3:
		menuRemove();
		break;
	case 4:
		menuUpdate();
		break;
	default:
		break;
	}
}
//
//void Controllers::desk()
//{
//    switch (views.desk())
//    {
//    case 0:
//        home();
//        break;
//    case 1:
//        deskShow();
//        break;
//    case 2:
//        deskAdd();
//        break;
//    case 3:
//        deskRemove();
//        break;
//    default:
//        break;
//    }
//}
//
//void Controllers::order()
//{
//    switch (views.order())
//    {
//    case 0:
//        home();
//        break;
//    case 1:
//        orderAdd();
//        break;
//    default:
//        break;
//    }
//}
//
//void Controllers::bill()
//{
//    switch (views.bill())
//    {
//    case 0:
//        home();
//        break;
//    case 1:
//        billAdd();
//        break;
//    case 2:
//        //billOrder();
//        break;
//    case 3:
//        // billPayment();
//        break;
//    default:
//        break;
//    }
//}
//
void Controllers::menuShow()
{
	List<Menu> menus;
	models.getAllMenu(menus);
	views.menuShow(menus);
	menu();
};
void Controllers::menuAdd()
{
	List<Menu> menus;
	models.getAllMenu(menus);
	Menu temp;
	temp = views.menuAdd();
	models.menuAdd(temp);
	menu();
};
void Controllers::menuRemove()
{
	List<Menu> menus;
	models.getAllMenu(menus);
	int foodId;
	foodId = views.menuRemove(menus);
	models.menuRemove(foodId);
	views.menuShow(menus);
	menu();
};
void Controllers::menuUpdate()
{
	List<Menu> menus;
	models.getAllMenu(menus);
	Menu temp;
	temp = views.menuUpdate(menus);
	models.menuUpdate(temp);
	menu();
};

//void Controllers::deskShow()
//{
//    views.deskShow();
//    desk();
//}
//void Controllers::deskAdd()
//{
//    Desk temp;
//    temp = views.deskAdd();
//    table.desk.insertFirst(temp);
//    desk();
//}
//void Controllers::deskRemove()
//{
//    Desk temp;
//    temp = views.deskRemove();
//    table.desk.findOneAndRemove(temp);
//    desk();
//}
//void Controllers::orderAdd()
//{
//    Order temp;
//    temp = views.orderAdd();
//    table.order.insertFirst(temp);
//    order();
//}
//void Controllers::billAdd()
//{
//    Bill temp;
//    temp = views.billAdd();
//   // table.bill.insertFirst(temp);
//    bill();
//}
#endif
