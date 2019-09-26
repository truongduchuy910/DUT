#include <fstream>
#include <iostream>
using namespace std;
 
int main ()
{
    
   char data[100];

   // mo mot file trong che do write.
   ofstream outfile;
   outfile.open("vietjack.dat");

   cout << "Ghi du lieu toi file!" << endl;
   cout << "Nhap ten cua ban: "; 
   cin.getline(data, 100);

   // ghi du lieu da nhap vao trong file.
   outfile << data << endl;

   cout << "Nhap tuoi cua ban: "; 
   cin >> data;
   cin.ignore();
   
   // ghi du lieu da nhap vao trong file.
   outfile << data << endl;

   // dong file da mo.
   outfile.close();

   // mo mot file trong che do read.
   ifstream infile; 
   infile.open("vietjack.dat"); 
 
   cout << "\n===========================\n" ;
   cout << "Doc du lieu co trong file!" << endl; 
   infile >> data; 

   // ghi du lieu tren man hinh.
   cout << data << endl;
   
   // tiep tuc doc va hien thi du lieu.
   infile >> data; 
   cout << data << endl; 

   // dong file da mo.
   infile.close();

   return 0;
}