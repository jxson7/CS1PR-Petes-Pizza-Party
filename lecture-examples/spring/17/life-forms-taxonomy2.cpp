#include <iostream>
#include <string>
#include <vector>

using namespace std;

// create the taxonomy via overloading of methods

class Lifeform{
public:
  virtual string species_name() = 0;
  virtual bool offspring_by_cloning() = 0;
  virtual bool has_genders() = 0;

  virtual string dna_genome() = 0;
  virtual int number_of_chromosomes() = 0;

  virtual int   get_statistics_population() = 0;
  virtual float get_statistics_typical_lifespan() = 0;
};

class Plant : public Lifeform{
public:
  bool deciduous; // their leafs fall in autumn
  virtual bool is_evergreen() = 0;
};

class Fruit : public Plant {
public:
  string fruit_color;

  virtual bool is_evergreen(){
    return false;
  }
};

class Banana : public Fruit{
public:
  float typical_banana_weight;

  virtual bool is_evergreen(){
    return true;
  }

  virtual string species_name(){
    return "genericum musa";
  }

  virtual bool offspring_by_cloning(){
    return false;
  }

  virtual bool has_genders(){
    return false;
  }

  virtual string dna_genome(){
    return "AGCAGC... long string of DNA";
  }
};

class Bacteria : public Lifeform{

};

class Animal : public Lifeform {
public:
  bool is_vegetarian;
  bool is_omnivorous;
  bool has_vertibrae;
};

class Mammal : public Animal{
public:

};

class Reptile : public Animal{

};

class Fish : public Animal{

};

class Bird : public Animal{

};

class Duck : public Bird{

};

// one idea of usage would be a factory
Lifeform * create_lifeform(vector<string> const & properties){
  // make the decision of the life form to create based on the properties
  return new Duck();
}

int main(){
  Lifeform * l1 = create_lifeform({"flies", "swims", "eats gras", "lays eggs", "climate hot"});

  // create a specific instance of a Duck
  cout << l1->dna_genome() << endl;

  Plant * p = dynamic_cast<Plant*>(l1);
  if(p){
    cout << p->is_evergreen() << endl;
  }
  return 0;
}
