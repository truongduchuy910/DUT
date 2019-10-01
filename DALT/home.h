#include <iostream>
using namespace std;
int home{
    system("slear");
    int n;
    do{
        cout << "1. Nhập thông tin khách hàng!" << endl;
        cout << "2. Xem thông tin bàn trống!" << endl;
        cout << "3. Nhập thông tin bàn!" << endl;
        cout << "4. Gọi mói!" << endl;
        cout << "5. Xuất hóa đơn!" << endl;
        cout << "Choose your option [1-5]: ";
        cin >> n;
        swithch(n){
            case 1:{

            }
            case 2:{
                
            }
            case 3:{

            }
            case 4:{

            }
            case 5:{

            }
            case 6:{
                break;
            }
        }while(n!=6);
    }
    while (n < 1 || n > 8);
}