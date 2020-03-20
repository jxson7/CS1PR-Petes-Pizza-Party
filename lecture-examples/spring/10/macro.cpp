#include <string>
#include <iostream>

#define ITEMS \
TYPE(Computers), \
TYPE(Scientists), \
TYPE(Routers), \
TYPE(Monitors),


#define TYPE(e) e
enum class item {
ITEMS
};
#undef TYPE

#define TYPE(e) #e
const std::string item_strings[] = {
ITEMS
};
#undef TYPE

int main(){
  std::cout << item_strings[(int) item::Routers] << std::endl;
}
