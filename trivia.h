//Mia Armstrong
//CS 163 Assignment 5
//File: trivia.h
/*This file is the header file for the trivia class*/

#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>

using namespace std;

class trivia
{
   public:
          trivia();
          ~trivia();
          int create_entry(char * new_title, char * new_notes);
          int copy_entry(const trivia & new_trivia);
          int retrieve(trivia & found) const;
          bool compare (char * key_title);
          int display() const;
   private:
          char * title;
          char * notes;
};
