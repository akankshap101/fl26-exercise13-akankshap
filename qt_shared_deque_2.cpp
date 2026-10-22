// qt_shared_deque_2.cpp
#include <iostream>
#include <cassert>
#include <limits>

#include "shared_ring_buffer.h"

int main(int argc, char *argv[])
{
  SharedRingBuffer<int> buffer;
  const int capacity = 100;

  if(!buffer.create(capacity)){
    std::cerr << "Unable to open shared buffer" << std::endl;
    return 1;
  }

  while(true){
    if(buffer.getCount() < capacity){
      //int value = 3;
      int value;

      std::cout << "enter integer:" << std::flush;

      if(!(std::cin >> value)){
        if(std::cin.eof()){
          break;
        }
      
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter valid int " << std::endl;
      continue;
    }

    if(buffer.enqueue(value)){
      std::cout << "enqueued: " << value << std::endl;
    }else{
      std::cout << "buffer full " << value << std::endl;
    }
  }

}
return 0;
}


