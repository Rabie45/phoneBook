
#include "Dairy.hpp"
#include <iostream>
#include <ostream>
#include <unistd.h>

int main() {
  int num;
  Person pers;
  while (1) {

    std::cout << "Choose between:" << std::endl;
    std::cout << "1- Find" << std::endl;
    std::cout << "2- ADD" << std::endl;
    std::cout << "4- Display All " << std::endl;
    std::cin >> num;
    Dairy dir;
    switch (num) {
    case 1:
      dir.searchAndDisplayLineNumbers();
      break;
    case 2:
      dir.add(pers);
      break;
    case 4:
      // delete_contact() defalt : std::cout << "Nothig called" << std::endl;
      dir.displayFileContent();
      break;
    default:
      std::cout << "Nohig  " << std::endl;
      break;
    }
    num = 0;
    sleep(3);
    system("clear");
  }
  return 0;
}
