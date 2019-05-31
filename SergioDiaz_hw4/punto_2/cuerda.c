#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define T 40.0
#define p 10.0
#define L 100.0
#define c sqrt(T/p)
#define dt 10.0
#define dx 10.0
#define tf 200.0

float ini(float x);

void main(){

  int cx = ((L/dt)+1.0);
  int ct = ((tf/dt)+1.0);
  
  float pos [ct][cx];

  int i;
  int j;
  for(i=0;i<cx;i++){
    pos[0][i] = ini(i*dx);
  }
  for(i=1;i<ct;i++){
    pos[i][0] = 0.0;
    pos[i][cx-1] = 0.0;
  }

  for(i=0;i<(ct-2);i++){
    for(j=1;j<(cx-1);j++){
      if(i == 0){
	pos[i+1][j] = (pow(c,2.0)*pow(dt,2.0)*((pos[i][j-1]-2*pos[i][j]+pos[i][j+1])/pow(dx,2.0)))-pos[i][j]+2*pos[i][j];
      }
      else{
	pos[i+1][j] = (pow(c,2.0)*pow(dt,2.0)*((pos[i][j-1]-2*pos[i][j]+pos[i][j+1])/pow(dx,2.0)))-pos[i-1][j]+2*pos[i][j];
      }
    }
  }

  for(i=0;i<ct;i++){
    for(j=0;j<cx;j++){
      printf("%f ", pos[i][j]);
    }
    printf("\n");
  }

}



float ini(float x){ 
  if(x <= 0.8*L){
    return (1.25*x)/L;
  }
  else{
    return 5-((5*x)/L);
  } 
}

