#include "./ajusteLinearMMQ.h"
#include <iostream>
using namespace std;

int main(){
    cout << "Programa Iniciado" << endl;

    float x[11] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    float fx[11] = {0.94, 0.96, 1, 1.05, 1.07, 1.09, 1.14, 1.17, 1.21, 1.24, 1.28};

    ajusteLinearMMQF(fx, x, 11);

    return 0;
}