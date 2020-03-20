#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

struct CycleOutput{
  float prey;
  float predator;

  CycleOutput(float prey, float predator) : prey(prey), predator(predator) {}
};

vector<CycleOutput> simulate(int cycles, float timestep = 0.1, float x=10, float y=10, float alpha = 1.1, float beta = 0.4, float delta = 0.1, float gamma = 0.4){
  vector<CycleOutput> output;
  output.push_back(CycleOutput(x, y));
  for(int i=0; i < cycles; i++){
    // change in a timestep
    float nx = timestep * (alpha * x - beta * x * y);
    float ny = timestep * (delta * x * y - gamma * y);
    x += nx;
    y += ny;
    if(x < 0) x = 0;
    if(y < 0) y = 0;

    output.push_back(CycleOutput(x, y));
  }
  return output;
}

void printSimOutput(vector<CycleOutput> const & result){
  for(auto & o : result){
    cout << o.prey << " " << o.predator << endl;
  }
}

void testCase1(){
  auto result = simulate(1, 1.0, 10, 0, 1.2);
  assert(result[0].prey == 12.0);
  assert(result[0].predator == 0);
}

/*
 This is a little simulator for the predator and prey relationship
 using the Lotka–Volterra model

 https://en.wikipedia.org/wiki/Lotka%E2%80%93Volterra_equations
 */
int main(int argc, char ** argv){
  //testCase1();

  auto result = simulate(400);
  printSimOutput(result);
  return 0;
}
