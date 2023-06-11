#include "LinkedList.h"

int main() {
    LinkedList<int> a = LinkedList<int>{5};
    a.add_end(14);
    a.add_end(15);
  //  a.add_beg(40);
 //   a.add_beg(45);
   a.delete_end();
   a.delete_begin();
   a.delete_begin();
   a.delete_begin();
    std::cout << a;
}