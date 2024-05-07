
/*********************************************************/
//
//                 Copyright Abdallah rabir
//
//
/**********************************************************/
/*
Author: Abdallah rabir
Date: 05 ماي, 2024 EEST 08:38:07 م
*/
#include <fstream>
#include <iostream>
class Person {
public:
  std::string name;
  std::string number;
  std::string Email;
};

#include <string>
class Dairy {
public:
  //   std::string find(std::string str);
  void add(Person pers);
  void delete_contact();
  std::string setNumber(Person pers);
  void displayFileContent();
  void searchAndDisplayLineNumbers();
};
