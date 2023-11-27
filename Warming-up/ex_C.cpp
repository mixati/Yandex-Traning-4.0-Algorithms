#include <iostream>
#include <cmath>

#define _USE_MATH_DEFINES

using namespace std;
int main() {
    double xa, ya, xb, yb;

    cin >> xa >> ya >> xb >> yb;
    double r1 = sqrt(xa*xa + ya*ya);
    double r2 = sqrt(xb*xb + yb*yb);
    if (xa / ya == xb / yb) {
        if (((xa >= 0 && xb >= 0) || (xa <= 0 && xb <= 0)) && \
            ((ya >= 0 && yb >= 0) || (ya <= 0 && yb <= 0))) {
            cout << fixed << abs(r1 - r2) << endl;
            return 0;
        }
        else {
            cout << fixed << abs(abs(r1) + abs(r2)) << endl;
            return 0;
        }
    }
    
    double var1, var2;
    
    var1 = r1 + r2; //вариант 1: до центра и то точки
    double round, lin;
    double alfa, beta, osn; // угол между точками и основание равнобедренного треугольника
    lin = abs(r1 - r2);
    alfa = atan2(xa, ya);
    // cout << alfa << endl; //
    beta = atan2(xb, yb);
    // cout << beta << endl; //
    alfa = abs(alfa - beta);
    if (alfa > M_PI)
        alfa = 2*M_PI - alfa;
    // cout << alfa << endl; //
    if (r1 < r2)
        round = r1*alfa;
    else
        round = r2*alfa;
    var2 = lin + round;
    if (var1 < var2)
        cout << fixed << var1 << endl;
    else
        cout << fixed << var2 << endl;

    return 0;
}
// DONE
