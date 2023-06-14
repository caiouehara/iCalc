#include "./ajusteLinearMMQ.h"
#include <iostream>
using namespace std;

void ajusteLinearMMQF(float* fx, float* x, int n){
    float numA = 0.0;
    float numB = 0.0;
    float denom = 0.0;
    float a = 0.0;
    float b = 0.0;

    float sumSquareFX = 0.0; 
    float sumFX = 0.0;
    float sumX = 0.0;
    float sumSquareX = 0.0;
    float sumXFX = 0.0;
    (float) n;

    //Elementos do sistema normal (discreto)
    for(int i=0; i < n; i++){
        sumSquareFX += fx[i] * fx[i];
        sumFX += fx[i];
        sumX += x[i];
        sumSquareX += x[i] * x[i];
        sumXFX += (fx[i] *  x[i]);
    }

    //Crammer Rule
    numA = (sumFX * sumSquareX) - (sumX * sumXFX);
    numB = (n* sumXFX) - (sumFX * sumX);
    denom = (n * sumSquareX) - (sumX * sumX);

    a = numA/denom;
    b = numB/denom;

    cout << "a: " << a << " " << "b: " << b << endl;
};
