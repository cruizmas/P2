#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pav_analysis.h"
#define signo(x) (x>0 ? 1 : x<0 ? -1:0)
float compute_power(const float *x, unsigned int N) {
    float pot = 1e-12;
    for(unsigned int n=0; n<N; n++){
        pot += x[n]*x[n];
    }
    return 10*log10(pot/N);
}
float compute_am(const float *x, unsigned int N) {
    float am = 0;
    for(unsigned int n=0; n<N; n++){
        am += fabs(x[n]);
    }
    return am/N;
}
float compute_zcr(const float *x, unsigned int N, float fm){
    float zcr = 0;
    for(unsigned int n=1; n<N; n++){
        if(signo(x[n])!=signo(x[n-1])){
            zcr ++;
        }
    }
    return fm/(2*(N-1))*zcr; 
}

float hamming(unsigned int i, unsigned int N){
    float w = 1e-12;
        w = 0.54-0.46*cos((2*M_PI*i)/(N-1));
    return w;
}
float compute_power_window(const float *x, unsigned int N, const float *w){
    float pot_num = 1e-12;
    float pot_den = 1e-12;
    for(unsigned int n=0; n<N; n++){
        pot_num += (x[n]*w[n])*(x[n]*w[n]);
        pot_den += w[n]*w[n];
    }
    return 10*log10(pot_num/pot_den);
}
