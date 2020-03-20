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

struct SimulationConfiguration{
  float x=10;
  float y=10;
  float alpha = 1.1;
  float beta = 0.4;
  float delta = 0.1;
  float gamma = 0.4;
};

CycleOutput simulateOneStep(SimulationConfiguration const & c){
  // changes performed in a single timestep
  float x = c.alpha * c.x - c.beta * c.x * c.y;
  float y = c.delta * c.x * c.y - c.gamma * c.y;
  if(x < 0) x = 0;
  if(y < 0) y = 0;
  return CycleOutput(x, y);
}

vector<CycleOutput> simulate(int cycles, SimulationConfiguration const & c){
  vector<CycleOutput> output;
  // simulate 10 cycles
  for(int i=0; i < cycles; i++){
    CycleOutput o = simulateOneStep(c);
    output.push_back(o);
  }
  return output;
}

void printSimOutput(vector<CycleOutput> const & result){
  for(auto & o : result){
    cout << o.prey << " " << o.predator << endl;
  }
}

void testCase1(){
  SimulationConfiguration c;
  c.x = 10;
  c.alpha = 1.2;
  c.y = 0;
  auto result = simulate(1, c);
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
  SimulationConfiguration c;
  auto result = simulate(10, c);
  printSimOutput(result);
  return 0;
}
