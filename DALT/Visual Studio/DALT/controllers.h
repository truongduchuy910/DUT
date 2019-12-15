
#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include <iostream>
#include <iomanip>
#include <string>
#include "tables.h"
#include "list.h"
using namespace std;
class {
public:
	List<Menu> menus;
} db;
class Controllers
{
public:
	class
	{
	public:
		void render()
		{
			cout << endl;
			cout << "============= HOME CONTROLL" << endl
				<< "0. Exit" << endl
				<< "1. Menu" << endl;
			int n;
			cin >> n;
			switch (n)
			{
			case 1:
				menus.render();
				render();
				break;
			}
		};
		class
		{
		public:
			class
			{
			public:
				void render()
				{
					cout << endl;
					cout << "============= MENU ADD" << endl;
					Menu menu;
					cin >> menu;
					db.menus.insert(menu);
				}
			} add;
			class
			{

			public:
				void render()
				{
					cout << endl;
					cout << "============= MENU SHOW" << endl;
					Menu::head();
					db.menus.print();
				}
			} show;
			class
			{

			public:
				void render()
				{
					cout << endl;
					cout << "============= MENU REMOVE" << endl;
					Menu menu;
					cout << "input foodId to remove: ";
					cin >> menu.foodId;
					db.menus.findAndRemove(menu);
				}
			} remove;
			void render()
			{
				cout << endl;
				cout << "============= MENU CONTROLL" << endl
					<< "0. Back" << endl
					<< "1. Add" << endl
					<< "2. Show" << endl
					<< "3. Remove" << endl;
				int n;
				cin >> n;
				switch (n)
				{
				case 0:
					break;
				case 1:
					add.render();
					render();
					break;
				case 2:
					show.render();
					render();
					break;
				case 3:
					remove.render();
					render();
					break;
				}
			};

		} menus;
	} home;

};
#endif