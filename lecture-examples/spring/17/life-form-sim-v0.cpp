#include <iostream>
#include <string>

using namespace std;

/*
 This is a little simulator for the predator and prey relationship
 using the Lotka–Volterra model

 https://en.wikipedia.org/wiki/Lotka%E2%80%93Volterra_equations
 */
int main(){
  float x = 10; // prey population
  float y = 10; // predator population

  float alpha = 1.2; // growth rate of the prey
  float beta = 0.1;
  float delta = 0.05;
  float gamma = 0.4;

  // simulate 10 cycles
  for(int i=0; i < 20; i++){
    // change in a timestep
    float dx = alpha * x - beta * x * y;
    float dy = delta * x * y - gamma * y;
    x = x + dx;
    y = y + dy;
    if(x < 0) x = 0;
    if(y < 0) y = 0;

    cout << i << " " << (int) x << " " << (int) y << endl;
  }

  return 0;
}
