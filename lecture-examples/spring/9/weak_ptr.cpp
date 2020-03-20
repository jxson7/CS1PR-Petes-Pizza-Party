#include <iostream>
#include <memory>

using namespace std;

void access_weak(weak_ptr<int> wp){
    cout << "use_count == " << wp.use_count() << ": ";
    if (auto spt = wp.lock()) { // creates shared pointer
	     cout << *spt << "\n";
    }else {
        cout << "wp is expired\n";
    }
}

int main(){
  weak_ptr<int> wp;
  {
    auto sp = make_shared<int>(42);
  	wp = sp;
  	access_weak(wp);
  }
  access_weak(wp);
}
