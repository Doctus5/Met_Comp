#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define PI 3.141592653589793
#define v 5.0;

float time(float d);
float dist(float xi, float yi, float sx, float sy);
float min(float a, float b);
 
void main(){

  float st[6][2] =
    {
      {3,15},
      {4,15},
      {5,15},
      {3,16},
      {4,16},
      {5,16}
    };
  
  float t[6] = {3.12, 2.98, 2.84, 3.26, 3.12, 2.98};
  float dt = 0.10;
  float dx = 0.10;
  float dy = 0.10;
  float xi = -2.0;
  float yi = 2.0;

  int N = 10000;
  float pasos[N][2];
  
  pasos[0][0] = xi;
  pasos[0][1] = yi;

  for(int i=1;i<N;i++){

    float R = 0.0;
    float x;
    float y;
    float ranx = rand() % 2;
    float rany = rand() % 2;
    
    if(ranx == 0){
      ranx = -1.0;
    }
    else{
      ranx = 1.0;
    }
    if(rany == 0){
      rany = -1.0;
    }
    else{
      rany = 1.0;
    }

    x = xi + dx*ranx;
    y = yi + dy*rany;
    
    for(int j=0;j<6;j++){

      float sx = st[j][0];
      float sy = st[j][1];
      
      float t_prima = time(dist(x, y, sx, sy));
      R = R + pow((t_prima - t[j]),2.0);
      
    }

    float num = exp(-R/(2*dt));
    
    float alpha = min(1.0,num); 
    float u = rand()/((double)(RAND_MAX));

    if(alpha <= u){
      xi = x;
      yi = y;

      pasos[i][0] = xi;
      pasos[i][1] = yi;
    }
    else{
      pasos[i][0] = xi;
      pasos[i][1] = yi;
    }
  }

  for(int i=0;i<N;i++){
    printf("%f %f\n", pasos[i][0], pasos[i][1]);
  }
  
}





float time(float d){
  
  return d/v;
}

float dist(float xi, float yi, float sx, float sy){
  
  return sqrt(pow((xi-sx),2.0)+pow((yi-sy),2.0));
}

float min(float a, float b){

  if((a-b) > 0.0){
    return b;
  }
  else{
    return a;
  }
  
}
