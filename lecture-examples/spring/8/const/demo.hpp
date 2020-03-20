#ifndef DEMO_H
#define DEMO_H

using namespace std;

class demo{
 public:
  demo(int a, int b, int c);  // constructor

  // set function - non const, prototypes do not need to specify var names
  void set_demo(int, int, int);

  // get function for m const
  int get_abc() const;

 private:
  int const m; // constant
  int a, b, c;
};

#endif
