#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <list>

using namespace std;

// Task: model a selection of life forms for simulation of their behavior in a small  environment
// https://manoa.hawaii.edu/exploringourfluidearth/biological/what-alive/classification-life


// our environment consists of lifeforms and substances
// let's assume no space

// forward declarations
class Lifeform;
class Substance;

// A container describing the environment
class Environment{
public:
  map<string, double> substances; // we have a substances and an amount
  list<Lifeform*> lifeforms; // and several lifeforms
};

/*
 Modelling substances
class Substance{
public:
  Substance(string const & type, double amount) : type(type), amount(amount){}

  string type;
  double amount;

  string to_string(){
    stringstream s;
    s << "Substance[" << type << ": " << amount << "kg]";
    return s.str();
  }
};
*/

class Lifeform{
protected:
  int health = 0;
  int growth = 0;
  int creation_time = 0; // in days
  bool wants_to_reproduce = false;
public:
  virtual ~Lifeform(){} // virtual destructor

  Lifeform(int creation_time) : creation_time(creation_time) {}

  // reproduce this life form by generating a new list of lifeforms
  virtual list<Lifeform*> reproduce(int creation_time) = 0; // we create an abstract interface using = 0

  // take whatever you need from the environment and put back whatever you produce
  virtual void metabolize_tick(Environment & environment) = 0;

  // convert the specific lifeform to a user-readable string
  virtual string to_string(){
    stringstream s;
    s << "[created:"<< creation_time << ",health:" << health << ",growth:" << growth << ",reproduce:" << wants_to_reproduce << "]";
    return s.str();
  }

  // if the lifeform is attacked
  void attacked(int damage){
    this->health -= damage;
  }

  int get_health(){
    return health;
  }

  int get_growth(){
    return growth;
  }

  bool is_alive(){
    return health > 0;
  }

  bool can_reproduce(){
    return wants_to_reproduce;
  }
};

class LifeSimulator{
private:
  Environment env;
  int model_time = 0;
public:
  LifeSimulator(Environment const & initialConditions): env(initialConditions){
  }

  // simulate one timestep (1 hour)
  void tick(){
    for(auto it = env.lifeforms.begin(); it != env.lifeforms.end();){
      auto lifeform = *it;
      if(! lifeform->is_alive()){
        // changing the list while iterating is tricky
        it = env.lifeforms.erase(it);
        delete lifeform;
        continue;
      }

      lifeform->metabolize_tick(env);

      if(lifeform->can_reproduce()){
        list<Lifeform*> offspring = lifeform->reproduce(model_time);
        for(auto of : offspring){
          env.lifeforms.push_front(of);
        }
      }
      // update iterator, cannot do this inline
      it++;
    }
    model_time++;
  }

  int get_model_time() {
    return model_time;
  }

  void print(){
    cout << "Tick " << model_time << endl;
    for(auto l: env.lifeforms){
      cout << l->to_string() << endl;
    }
    cout << endl;
    for(auto & s : env.substances){ // the map stores pairs
      cout << s.first << ":" << s.second << "kg" << endl;
    }
  }
};

// single cell lifeform
class Bacteria : public Lifeform{

};

// single cell lifeform
class Archaea : public Lifeform{
public:
  // not considered for now
};

class Eukarya : public Lifeform{
public:
  Eukarya(int creation_time) : Lifeform(creation_time) {}
};


class Plantae : public Eukarya {
// a plant takes CO2 and H2O and converts it to O2 and sugar (stored in the plant)
public:
  Plantae(int creation_time, int health=10, int growth=5) : Eukarya(creation_time){
    this->health = health;
    this->growth = growth;
  }

  virtual list<Lifeform*> reproduce(int creation_time){
    this->wants_to_reproduce = false;
    if(this->growth < 10){
      throw "cannot reproduce";
    }
    list<Lifeform*> list;
    // generate 10 offsprings
    for(int i=0; i<10; i++){
      Plantae * p = new Plantae(creation_time, 1, 1);
      list.push_back(p);
    }
    // shrink
    this->growth -= 3;

    return list;
  }

  virtual void metabolize_tick(Environment & env){
    // take CO2
    double co2 = env.substances["CO2"];
    if(co2 > 0){
      double produced = 0;
      if(co2 >= this->growth){
        // can grow and heal
        if(this->growth >= 10){
          // stop growing
          this->wants_to_reproduce = true;
        }else{
          this->growth++;
        }
        produced = this->growth;

        // heal three health per turn that you have proper nutrients
        this->health += 3;
        if(this->health > 2 * this->growth){
          this->health = 2 * this->growth;
        }
      }else{
        produced = co2;
      }
      env.substances["CO2"] -= produced;
      env.substances["H2O"] -= produced;
      env.substances["O2"] += produced;
    }else{
      this->health--;
    }
  }

  virtual string to_string(){
    stringstream s;
    s << "plantae";
    s << Eukarya::to_string();
    return s.str();
  }
};

// must consume other organisms
class Animalia : public Eukarya {
protected:
  bool female;
public:
  Animalia(int creation_time, bool female, int health=10, int growth=1) : Eukarya(creation_time){
    this->health = health;
    this->growth = growth;
  }

  virtual list<Lifeform*> reproduce(int creation_time){
    this->wants_to_reproduce = false;
    if(this->growth < 5){
      throw "cannot reproduce";
    }
    list<Lifeform*> list;
    // generate two offsprings, one male, one female
    Animalia * p = new Animalia(creation_time, 0, 1, 1);
    list.push_back(p);
    Animalia * p2 = new Animalia(creation_time, 1, 1, 1);
    list.push_back(p2);
    return list;
  }

  virtual void metabolize_tick(Environment & env){
    // take O2 and produce CO2
    double needed = this->growth;
    bool has_everything_to_live = true;
    if(env.substances["O2"] > needed){
      env.substances["O2"] -= needed;
      env.substances["CO2"] += needed;
    }else{
      this->health = 0;
      return;
    }

    // trink water
    if(env.substances["H2O"] > needed){
      env.substances["H2O"] -= needed;
    }else{
      this->health-= 2;
      has_everything_to_live = false;
    }

    // eat, must eat growth points to eat
    // find plants to eat using backwards iterator
    int needed_food = this->growth;
    for(auto it = env.lifeforms.rbegin(); it != env.lifeforms.rend() && needed_food > 0; it++){
      Plantae * p = dynamic_cast<Plantae*>(*it);
      if(! p){
        continue;
      }
      // eat up to health but not more than the "growth" of the plant
      int val = p->get_growth() > p->get_health() ? p->get_health() : p->get_growth();
      val = val > needed_food ? needed_food : val;
      p->attacked(val);
      needed_food -= val;
    }

    if(needed_food > 0){
      has_everything_to_live = false;
    }

    // grow
    if(has_everything_to_live && this->growth < 20){
      this->growth++;
      this->health += 10;
    }

    // heal
    if(has_everything_to_live && this->health < 10*this->growth){
      this->health += 1;
    }
    if(this->health > 10*this->growth){
      this->health = 10 * this->growth;
    }
  }

  virtual string to_string(){
    stringstream s;
    s << "animalia";
    s << Eukarya::to_string();
    return s.str();
  }
};

int main(){
  // initial conditions
  Environment env;
  env.substances = {
    {"CO2", 10000},
    {"H2O", 10000},
    {"O2", 10000}
    };
  for(int i=0; i < 3; i++){
    env.lifeforms.push_back(new Plantae(0));
  }
  env.lifeforms.push_back(new Animalia(0, true));

  // setup simulator
  LifeSimulator sim(env);
  sim.print();
  for(int i=0; i < 10; i++){
    sim.tick();
    sim.print();
  }

  return 0;
}
