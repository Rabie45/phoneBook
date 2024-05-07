
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
#include "Dairy.hpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <vector>

void Dairy::displayFileContent() {
  std::ifstream file("file.txt"); // Open file with given filename for reading
  std::string line;               // Declare a string to store each line of text

  if (file.is_open()) { // Check if the file was successfully opened
    std::cout << "File content:"
              << std::endl; // Displaying a message indicating file content
    while (std::getline(file, line)) { // Read each line from the file
      std::cout << line << std::endl;  // Display each line of the file
    }
    file.close(); // Close the file
  } else {
    std::cout << "Failed to open the file."
              << std::endl; // Display an error message if file opening failed
  }
}

void Dairy::add(Person pers) {
  std::cout << "Enter the contact name" << std::endl;
  std::cin >> pers.name;
  pers.number = setNumber(pers);
  std::cout << "Enter the contact Email" << std::endl;
  std::cin >> pers.Email;
  std::ofstream file;
  file.open("file.txt", std::ios::app);
  if (!file.is_open())
    std::cerr << "Error opening the file" << std::endl;

  file << "Name: " << pers.name << std::endl;
  file << "Number: " << pers.number << std::endl;
  file << "Name: " << pers.Email << std::endl;
  std::cout << "Adding.... " << std::endl;
  file.close();
}
void Dairy::delete_contact() {}

std::string Dairy::setNumber(Person pers) {
  bool flag = true;
  while (flag) {
    std::cout << "Enter the contact number" << std::endl;
    std::cin >> pers.number;
    if (pers.number.length() < 11 || pers.number.length() > 11) {
      std::cout << "wrong number (11) digit" << std::endl;
      flag = true;
    } else {
      flag = false;
    }
  }
  return pers.number;
}

void Dairy::searchAndDisplayLineNumbers() {
  std::ifstream file("file.txt"); // Open file with given filename for reading
  std::string line;               // Declare a string to store each line of text
  std::vector<int> lineNumbers; // Vector to store line numbers where the search
                                // string is found
  int lineNumber = 1;           // Variable to track the current line number
  std::cout << "Enter the contact name" << std::endl;
  std::string searchStr;
  std::cin >> searchStr;

  while (std::getline(file, line)) { // Read each line from the file
    if (line.find(searchStr) !=
        std::string::npos) { // Check if the search string is found in the line
      lineNumbers.push_back(
          lineNumber); // Store the line number where the search string is found
    }
    lineNumber++; // Increment the line number counter
  }

  file.close(); // Close the file after reading

  if (!lineNumbers.empty()) { // Check if any line numbers were stored
    std::cout << "String \"" << searchStr
              << "\" found at line number(s): "; // Display a message indicating
                                                 // the search string was found

    for (int i = 0; i < lineNumbers.size();
         ++i) {                    // Loop through the stored line numbers
      std::cout << lineNumbers[i]; // Display each line number

      if (i != lineNumbers.size() - 1) {
        std::cout << ", "; // Display a comma between line numbers, except for
                           // the last one
      }
    }

    std::cout
        << std::endl; // Move to the next line after displaying line numbers
  } else {
    std::cout << "String \"" << searchStr << "\" not found in the file."
              << std::endl; // Display a message indicating the search string
                            // was not found
  }
}
