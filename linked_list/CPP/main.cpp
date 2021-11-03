#include "LinkedList.h"

int main(int argc, char const *argv[]) {
  LinkedList<> list{0,1,2,3,4,5,6};
  LinkedList<> copied(list);

  std::cout << 
    "Length: " << list.length() << '\n' <<
    "Index 6: " << list.get(6) << '\n';

  list.remove(60);
  list.remove(0);
  list.remove(2);
  list.remove(5);

  list.print();

  copied.remove(5);
  copied.reverse();
  copied.print();

  return 0;
}
