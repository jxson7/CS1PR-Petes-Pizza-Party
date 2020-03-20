#include <iostream>
#include <thread>

// Compile with g++ threading.cpp  -lpthread

using namespace std;

void hello(int id){
  cout << "Hello, I am worker " << id << " with id" << this_thread::get_id() << endl;
}

int main(){

  thread threads[4];
  int i;
  // Spawn parallel threads
  for(i=0;i<4;i++){
    threads[i] = thread( hello, i);
  }

  // Join to synchronise
  for(i=0;i<4;i++){
    threads[i].join();
  }
  return 0;
}
