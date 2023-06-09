#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef float (*callbacks[])(float x);

float g1(float x)
{
    return (0.2* x);
}

float g2(float x)
{
    return (0.03* x);
}

callbacks funcoesParametros =
{
    g1,
    g2
};

void sistemaNormal(float fx[], float x[], callbacks g, int n)
{
    // Elementos do sistema normal (discreto)
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


    //Sistema Normal
    // Calculando elementos do sistema normal
    printf("\n1. Calculado produtos escalares\n");
    for (int i = 0; i < n; i++)
    {
        g1_g1 += g[0](x[i]) * g[0](x[i]); g1_g2 += g[0](x[i]) * g[1](x[i]);
        g2_g1 += g[1](x[i]) * g[0](x[i]); g2_g2 += g[1](x[i]) * g[1](x[i]);

        g1_fx += g[0](x[i]) * fx[i];
        g2_fx += g[1](x[i]) * fx[i];
    }
    printf("g1_g1: %f\ng1_g2: %f\ng2_g1: %f\ng2_g2: %f\ng1_fx: %f\ng2_fx: %f\n", g1_g1, g1_g2, g2_g1, g2_g2, g1_fx, g2_fx);

    // Regra de Crammer
    printf("\n2. Regra de Crammer\n");
    numA1 = (g1_fx * g2_g2) - (g1_g2 * g2_fx);
    numA2 = (g1_g1 * g2_fx) - (g1_fx * g2_g1);
    denom = (g1_g1 * g2_g2) - (g1_g2 * g2_g1);
    printf("numA1: %f\nnumA2: %f\ndenom: %f\n", numA1, numA2, denom);

    printf("\n3. Resultado\n");
    a1 = numA1 / denom;
    a2 = numA2 / denom; 
    printf("a1: %f, a2: %f", a1, a2);

    //Medição de erro
    printf("\n\n--------------- Medicao de erro ---------------------\n\n");

    float SQres = 0;
    float ymed = 0;
    float SQtotal = 0;
    float R2 = 0;
    for (int i = 0; i < n; i++)
    {
        SQres += pow(fx[i] - (a1*g[0](x[i]) + a2*g[1](x[i])), 2);
        ymed += fx[i];
    }
    ymed *= (1/ (float) n);
    for (int i = 0; i < n; i++)
    {
        SQtotal += pow(fx[i] - ymed, 2);
    }
    R2 = 1 - (SQres/SQtotal);

    printf("SQres: %f\n", SQres);
    printf("Ymed: %f\n", ymed);
    printf("R2: %f", R2);

};

int main()
{
    printf("\n---------- Programa Iniciado -------------\n");
    char path[] = "../dados_tratados.txt";

    FILE *stream;
    stream = fopen(path, "r");
    if (NULL == stream)
    {
        printf("Arquivo nao pode ser aberto\n");
        return -1;
    }

    int n = 101;
    int i[n];
    float t_i[n];
    float y_i[n];

    printf("\ni, t_i, y_i\n\n");
    int MAX_CARACTERES = 50;
    char linha[MAX_CARACTERES];
    int k = 0;
    while (fgets(linha, MAX_CARACTERES, stream))
    {
        sscanf(linha, "%d, %f, %f", &i[k], &t_i[k], &y_i[k]);
        k++;
        if (feof(stream))
            break;
    }
    fclose(stream);

    for (int k = 0; k < n; k++)
    {
        printf("%d %f %f\n", i[k], t_i[k], y_i[k]);
    }
    printf("\n--------------- Arquivo lido ---------------------\n\n");

    printf("\n--------------- Sistema normal ---------------------\n");

    sistemaNormal(y_i, t_i, funcoesParametros, n);

    return 0;
}