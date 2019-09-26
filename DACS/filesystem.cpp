#include <fstream>
#include <iostream>
using namespace std;
 
int main ()
{
    
   ofstream outfile;
   outfile.open("out.txt");
   outfile << "hello word" << endl;
   outfile.close();

   // mo mot file trong che do read.
   ifstream infile; 
   infile.open("in.txt"); 
   int data;
   while (infile >> data) {
	   cout << data;
   };
   infile.close();
   cout << endl;
   return 0;
}
