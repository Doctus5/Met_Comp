#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415
#define L 5.0
#define l 2.0
#define d 1.0
#define h 0.02
#define Vo 100.0
#define N 2*pow((L/h),2.0)

void main(){

  int lar = (L/h)+1;
  int alt = lar;
  float V[alt][lar];
  
  int i;
  int j;
  for(i=0;i<alt;i++){
    V[0][i] = 0.0;
    V[alt-1][i] = 0.0;
    V[i][0] = 0.0;
    V[i][lar-1] = 0.0;
    if(i*h >= 1.5 && i*h <=3.5){
      V[76][i] = Vo/2.0;
      V[176][i] = -Vo/2.0;
    }
  }

  for(i=1;i<lar-1;i++){
    for(j=1;j<alt-1;i++){
      if((j*h<1.5 || j*h>3.5) && (i!=76 || i!=176)){
	V[i][j]=(V[i+1][j]+V[i-1][j]+V[i][j+11]+V[i][j-1])/4;
      }
    }
  }

  for(i=0;i<lar;i++){
    for(j=0;j<alt;i++){
      printf("%f ",V[i][j]);
    }
    printf("\n");
  }
  
}
