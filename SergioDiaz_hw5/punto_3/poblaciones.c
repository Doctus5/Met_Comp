#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void main(){

  float sigma1=0.001, sigma2=0.001;
  
  int n=96;
  float t[n];
  float x[n];
  float y[n];
  int N = 10000;
  
  FILE *fread = fopen("lotka_volterra_obs.csv","r");
  for(int i=0;i<n;i++){
    fscanf(fread, "%f, %f, %f\n", &t[i], &x[i], &y[i]);
  }
  fclose(fread);

  float ai=4.0, bi=3.0, gi=4.0, di=3.0;
  float da=0.01, db=0.01, dg=0.01, dd=0.01;
  float a[N], b[N], g[N], d[N];
  a[0]=ai, b[0]=bi, g[0]=gi, d[0]=di;

  for(int i=1;i<N;i++){

    float R1=0.0, R2=0.0;
    float af, bf, gf, df;
    float ranA=rand()%2, ranB=rand()%2, ranG=rand()%2, ranD=rand()%2;

    if(ranA == 0){
      ranA = -1.0;
    }
    else{
      ranA = 1.0;
    }
    
    if(ranB == 0){
      ranB = -1.0;
    }
    else{
      ranB = 1.0;
    }
    
    if(ranG == 0){
      ranG = -1.0;
    }
    else{
      ranG = 1.0;
    }
    
    if(ranD == 0){
      ranD = -1.0;
    }
    else{
      ranD = 1.0;
    }

    af=ai+da*ranA;
    bf=bi+db*ranB;
    gf=gi+dg*ranG;
    df=di+dd*ranD;

    for(int j=1;j<n;j++){

      float dxdtR = (x[j]-x[j-1])/(t[j]-t[j-1]);
      float dxdtC = x[j]*(af-bf*y[j]);
      float dydtR = (y[j]-y[j-1])/(t[j]-t[j-1]);
      float dydtC = -y[j]*(gf-df*x[j]);

      R1=R1+pow(dxdtC-dxdtR,2.0);
      R2=R2+pow(dydtC-dydtR,2.0);
      
    }

    float alpha1 = exp(-R1/(2*sigma1));
    float u1 = rand()/((double)(RAND_MAX));

    if(alpha1 <= u1){
      ai = af;
      bi = bf;

      a[i] = ai;
      b[i] = bi;
    }
    else{
      a[i] = ai;
      b[i] = bi;
    }

    float alpha2 = exp(-R2/(2*sigma2));
    float u2 = rand()/((double)(RAND_MAX));
    
    if(alpha2 <= u2){
      gi = gf;
      di = df;

      g[i] = gi;
      d[i] = di;
    }
    else{
      g[i] = gi;
      d[i] = di;
    }
    
  }

  for(int k=0;k<N;k++){
    printf("%f %f %f %f\n", a[k], b[k], g[k], d[k]);
  }

  
}

