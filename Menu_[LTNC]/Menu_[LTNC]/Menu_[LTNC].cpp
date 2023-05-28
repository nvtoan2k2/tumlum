
#include <iostream>
#include<math.h>
using namespace std;

int GPTB2(double a, double b, double c, double &x1, double &x2) {
    
  
    double delta = b * b - 4 * a * c;
    if (delta < 0) {
        x1 = x2 = 0.0;
        return 0;
    }
    else if (delta == 0) {
        x1 = -b / (2 * a);
        return 1;
    }
    else {
        double x = sqrt(delta);
        x1 = (-b + x) / (2 * a);
        x2 = (-b - x) / (2 * a);
        return 2;
    }
}
void GPT() {
    int a, b, c;
    double  x1, x2;
    cout << "Nhap a = ";
    cin >> a;
    cout << "Nhap b = ";
    cin >> b;
    cout << "Nhap c = ";
    cin >> c;
    int gptb2 = GPTB2(a, b, c, x1, x2);
    if (gptb2 < 0) {
        cout << "phuong trinh vo nghiem";
    }
    else if (gptb2 == 0) {
        cout << "Phuong trinh co nghiem kep x1 = x2 = " << x1;
    }
    else {
        cout << "Phuong trinh co 2 nghiem phan biet: \n";
        cout << "x1 = " << x1<<"\n";
        cout << "x2 = " << x2<<"\n";
    }
}
int main()
{
    int n;
    while (true) {
        cout << "\n\n\t\tMenu\n";
        cout << "1.Giai phuong trinh bac 2\n";
        cout << "2.Tim so nguyen to\n";
        cout << "3.So chan le\n";
        cout << "4.Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> n;
        if (n > 4 || n < 0)
            continue;
        switch (n)
        {
        case 1:
            cout << "Chon giai phuong trinh bac 2\n";
            GPT();
        }
    }
    return 0;

}