#include <iostream>
class Schemal;
class Model;
class Mdb {
	public:
		char* name;
		Schemal schemal();
		Model model(char& name, Schemal schemal);
};
class Schemal {
}; 
class Model {
	public:
		Schemal schemal;
		void find();
		void save();
		void remove();
}; 
