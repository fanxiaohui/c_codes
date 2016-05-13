//main.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

#define PI 3.14159265
#define PI_2 6.28319

int flag_erro = TRUE;
double a1 = 0, b1 = 0, a2 = 0, b2 = 0; //dados na forma retangular
double modulo1 = 0, fase1 = 0, modulo2 = 0, fase2 = 0; //dados na forma fasorial

double adicao[2];
double subtracao[2];
double multiplicacao[2];
double divisao[2];
double divisao_invertida[2];

enum dados { polar, retangular };

enum dados tipoDados;

struct numPolar{
    double modulo;
    double fase;
};

struct numRet {
    double real;
    double imag;
};

//converte os numeros no formato retangular para polar
struct numPolar ret2pol(double a, double b);
struct numRet pol2ret(double modulo, double theta);

double rad2deg(double angle_rad);
double deg2rad(double angle_deg);

struct numPolar v1_polar;
struct numPolar v2_polar;
struct numPolar sum_polar;
struct numPolar sub_polar;
struct numRet v1_ret;
struct numRet v2_ret;
struct numRet mult_ret;
struct numRet div_ret;
struct numRet divinv_ret;

int main() {

    while(flag_erro == TRUE) {

        printf("Digite [0] para inserir os dados na forma polar (|Z| < ø °).\n");
        printf("Digite [1] para inserir os dados na forma retangular (A + Bi).\n");
        scanf("%d", &tipoDados);

        if (tipoDados !=polar && tipoDados !=retangular) {
            printf("Dados nao especificados da forma correta.\n");
        } else {
            flag_erro = FALSE;
        }
    }
    switch(tipoDados) {
        case retangular:
            printf("Digite os dados na forma M = a + bi:\n");
            printf("Vetor 1\n");
            printf("Valor de a:\n");
            scanf("%lf", &a1);
            printf("Valor de b:\n");
            scanf("%lf", &b1);
            printf("Vetor 2\n");
            printf("Valor de a:\n");
            scanf("%lf", &a2);
            printf("Valor de b:\n");
            scanf("%lf", &b2);

            if (b1>0)
                printf("Vetor digitado V1: %.2lf + %.2lfi\n", a1, b1);
            else
                printf("Vetor digitado V1: %.2lf  %.2lfi\n", a1, b1);
            if (b2>0)
                printf("Vetor digitado V1: %.2lf + %.2lfi\n", a2, b2);
            else
                printf("Vetor digitado V2: %.2lf  %.2lfi\n", a2, b2);
            adicao[0] = a1 + a2;
            adicao[1] = b1 + b2;
            subtracao[0] = a1 - a2;
            subtracao[1] = b1 - b2;

            v1_polar = ret2pol( a1,  b1);
            v2_polar = ret2pol( a2,  b2);
            //printf("v1_polar: a = v1_polar.modulo: %.2lf\tv1_polar.fase: %.2lf\n", v1_polar.modulo, rad2deg(v1_polar.fase)); 
            //printf("v2_polar: a = v2_polar.modulo: %.2lf\tv2_polar.fase: %.2lf\n", v2_polar.modulo, rad2deg(v2_polar.fase)); 
            multiplicacao[0] = v1_polar.modulo * v2_polar.modulo;
            multiplicacao[1] = rad2deg(v1_polar.fase) + rad2deg(v2_polar.fase);
            divisao[0] = v1_polar.modulo / v2_polar.modulo;
            divisao[1] = rad2deg(v1_polar.fase) - rad2deg(v2_polar.fase);
            divisao_invertida[0] = v2_polar.modulo / v1_polar.modulo;
            divisao_invertida[1] = rad2deg(v2_polar.fase) - rad2deg(v1_polar.fase);

            mult_ret = pol2ret( multiplicacao[0],  multiplicacao[1]);
            div_ret = pol2ret( divisao[0],  divisao[1]);
            divinv_ret = pol2ret( divisao_invertida[0],  divisao_invertida[1]);
            //printf("mult_ret: a = mult.modulo: %.2lf\tmult.fase: %.2lf\n", mult_ret.real, mult_ret.imag); 
            //printf("div_ret: a = div.modulo: %.2lf\tdiv.fase: %.2lf\n", div_ret.real, div_ret.imag); 
            //printf("divinv_ret: a = divinv.modulo: %.2lf\tdivinv.fase: %.2lf\n", divinv_ret.real, divinv_ret.imag); 
            printf("V1 + V2: a = %.2lf b = %.2lfi\n", adicao[0], adicao[1]);
            printf("V1 - V2: a = %.2lf b = %.2lfi\n", subtracao[0], subtracao[1]);
            printf("V1 * V2: a = %.2lf b = %.2lfi\n", mult_ret.real, mult_ret.imag);
            printf("V1/V2: a = %.2lf b = %.2lfi\n", div_ret.real, div_ret.imag);
            printf("V2/V1: a = %.2lf b = %.2lfi\n", divinv_ret.real, divinv_ret.imag);
            break;

        case polar:
            printf("Digite os dados na forma V = |Z| < ø\n");
            printf("Valor de ø (theta) em graus.\n");
            printf("Vetor 1\n");			   
            printf("Valor de |Z|:\n");
            scanf("%lf", &modulo1);
            printf("Valor de theta:\n");
            scanf("%lf", &fase1);
            printf("Vetor 2\n");			   
            printf("Valor de |Z|:\n");
            scanf("%lf", &modulo2);
            printf("Valor de theta:\n");
            scanf("%lf", &fase2);
            printf("Vetor digitado V1: |Z|:%.2lf < %.2lf° \n", modulo1, fase1);
            printf("Vetor digitado V2: |Z|:%.2lf < %.2lf° \n", modulo2, fase2);

            v1_ret = pol2ret( modulo1,  fase1 );
            v2_ret = pol2ret( modulo2,  fase2 );

            //printf("v1_ret: a: %.2lf\tbi: %.2lf\n", v1_ret.real,v1_ret.imag); 
            //printf("v2_ret: a: %.2lf\tbi: %.2lf\n", v2_ret.real,v2_ret.imag); 
            adicao[0] = v1_ret.real + v2_ret.real;
            adicao[1] = v1_ret.imag + v2_ret.imag;
            subtracao[0] = v1_ret.real - v2_ret.real;
            subtracao[1] = v1_ret.imag - v2_ret.imag;

            sum_polar = ret2pol(adicao[0], adicao[1]);
            sub_polar = ret2pol(subtracao[0], subtracao[1]);

            multiplicacao[0] = modulo1 * modulo2;
            multiplicacao[1] = fase1 + fase2;
            divisao[0] = modulo1 / modulo2;
            divisao[1] = fase1 - fase2;
            divisao_invertida[0] = modulo2 / modulo1;
            divisao_invertida[1] = fase2 - fase1;					
            printf("V1 + V2: |Z| = %.2lf ø = %.2lf °\n", sum_polar.modulo, rad2deg(sum_polar.fase));
            printf("V1 - V2: |Z| = %.2lf ø = %.2lf °\n", sub_polar.modulo, rad2deg(sub_polar.fase));
            printf("V1 * V2: |Z| = %.2lf ø = %.2lf °\n", multiplicacao[0], multiplicacao[1]);
            printf("V1 / V2: |Z| = %.2lf ø = %.2lf °\n", divisao[0], divisao[1]);
            printf("V2 / V1: |Z| = %.2lf ø = %.2lf °\n", divisao_invertida[0], divisao_invertida[1]);
            break;

        default: break;		
    }			

    return 0;
}

double rad2deg(double angle_rad) {
    double angle_deg = 0;
    angle_deg = (angle_rad*180.0)/PI;
    if(angle_deg < 0) angle_deg = 360.0 - abs(angle_deg);
    return angle_deg;
}

double deg2rad(double angle_deg) {
    double angle_rad = 0;
    angle_rad = (angle_deg*PI)/180.0;
    return angle_rad;
}

struct numPolar ret2pol(double a, double b) {
    struct numPolar result;
    //Z^2 = X^2 + Y^2
    double x = 0, y = 0, z = 0, theta = 0;
    x = pow(a,2);
    y = pow(b,2);
    z = x + y;
    z = sqrt(z);
    theta = atan2(b,a); 
    result.modulo = z;
    result.fase = theta;
    return result;
}

struct numRet pol2ret(double modulo, double theta) {
    struct numRet result;
    double a = 0, b = 0;
    double rad_angle = deg2rad(theta);
    double cosine = 0, sine = 0;
    cosine = cos(rad_angle);
    sine = sin(rad_angle);
    //printf("cosine(%.2lf): %.2lf\tsine(%.2lf): %.2lf\n", theta, cosine, theta, sine);
    a = modulo * cos(rad_angle);
    b = modulo * sin(rad_angle);

    result.real = a;
    result.imag = b;
    return result;
}

