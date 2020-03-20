#include <iostream>
#include <string>
#include <vector>

using namespace std;

// this is a taxonomy of life forms with information about their occurance and living on the world
// https://manoa.hawaii.edu/exploringourfluidearth/biological/what-alive/classification-life
// Other characteristics of a life form:
// https://study.com/academy/lesson/8-characteristics-of-life-in-biology.html

// one type of creating a taxonomy using data members to store information
// drawbacks:
// * users can manipulate data in the taxonomy
// * use the constructor to propagate/replace information in the parent class
// benefit:
// * simple mapping, store all information as data
//
// remember: the purpose of the class hierarchy is determining how to organize the classes

class Lifeform{
public:
  string species_name;
  bool offspring_by_cloning;
  bool has_genders;

  vector<string> habitat;
  vector<string> climate;
  vector<string> foods;

  string dna_genome; // this is the typical genome of an individuum of this species
  int number_of_chromosomes;

  // some general information about the lifeform
  int   population; // how many individuals of this life form exist on the world
  float typical_lifespan; // in years
};

class Plant : public Lifeform{
public:
  bool deciduous; // their leafs fall in autumn
  bool evergreen;

  Plant(bool evergreen) : evergreen(evergreen) {}
};

class Fruit : public Plant {
public:
  string fruit_color;

  Fruit(string fruit_color, bool evergreen): fruit_color(fruit_color), Plant(evergreen) {}
};

class Banana : public Fruit{
public:
  float typical_banana_weight;

  Banana() : typical_banana_weight(10), Fruit("yellow", true) {
    offspring_by_cloning = true;
    climate = {"hot", "hummid"};
    species_name = "genericum musa";
    dna_genome = "AGCAGC... long string of DNA";
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
  auto * l1 = create_lifeform({"flies", "swims", "eats gras", "lays eggs", "climate hot"});

  Banana b;
  Duck   d;

  // create a specific instance of a Duck
  d.dna_genome = "AAAACCCGTT";
  cout << b.dna_genome << endl;
  cout << d.dna_genome << endl;

  return 0;
}
