#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float (*callbacks[])(float x);

float g1(float x){
    return (0.4*x);
}

float g2(float x){
    return (1*x);
}

callbacks funcoesParametros =
{
  g1,
  g2
};

void sistemaNormal(float* fx, float* x, callbacks g, int n){
    float a1 = 0;
    float a2 = 0;
    float numA1 = 0;
    float numA2 = 0;
    float denom = 0;

    float g1_g1 = 0;
    float g1_g2 = 0;
    float g2_g1 = 0;
    float g2_g2 = 0;
    float g1_fx = 0;
    float g2_fx = 0;

    //Elementos do sistema normal (discreto)
    for(int i=0; i < n; i++){
        g1_g1 = g[0](x[i]) * g[0](x[i]);
        g1_g2 = g[0](x[i]) * g[1](x[i]);
        g2_g1 = g[1](x[i]) * g[0](x[i]);
        g2_g2 = g[1](x[i]) * g[1](x[i]);
        g1_fx = g[0](x[i]) * fx[i];
        g2_fx = g[1](x[i]) * fx[i];
    }

    //Crammer Rule,
    numA1 = (g1_fx * g2_g2) - (g1_g2 * g2_fx);
    numA2 = (g1_g1 * g2_fx) - (g1_fx * g2_g1);
    denom = (g1_g1 * g2_g2) - (g1_g2 * g2_g1);

    a1 = numA1/denom;
    a2 = numA2/denom;

    printf("a: %d, b: %d", a1, a2);
};

int main(){

}