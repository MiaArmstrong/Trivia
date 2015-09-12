//Mia Armstrong
//CS 163 Assignment 5
//File: main.cpp
/* This file contains the test bed for the trivia and graph classes. 
   This program takes trivia titles and notes from an external data file, loads them into a graph, then allows the user to create edges to the different trivia titles, creating a connection. 
*/

#include "graph.h"

const int SIZE = 100;

bool again();

int main()
{
   char filename[SIZE] = "data.txt";
   trivia a_trivia;
   table my_words;

   char new_title[SIZE]; //temporary for trivia
   char new_notes[SIZE];
   char connected[SIZE];

   int success = 0;
   
//loads trivia from file into graph.
//returns false if file cannot open or does not work.
   ifstream file_in;
   file_in.open(filename); //reads in file.
   
   if(!file_in)
   {
      cout << "Could not open file " << filename << " for reading. " << endl;
      return 0;
   }

   //connect to the file and ready to read
   file_in.get(new_title, SIZE, ';'); file_in.ignore(SIZE, ';');
   while (!file_in.eof()) //previous read was successful
   {
      file_in.get(new_notes, SIZE, ';'); file_in.ignore(SIZE, ';');
      a_trivia.create_entry(new_title, new_notes);
      //now insert it into the graph
      
      my_words.insert_vertex(a_trivia);

      file_in.get(new_title, SIZE, ';'); file_in.ignore(SIZE, ';');
   }
   file_in.close();

   cout << "\n\nThis is the contents of the table: \n";
   my_words.display_all();

   do 
   {
      cout << "Enter two words that are related (connected): ";
      cin.get(new_title, SIZE); cin.ignore(SIZE, '\n');
      cin.get(connected, SIZE); cin.ignore(SIZE, '\n');
      success = my_words.insert_edge(new_title, connected);
      if (success == 0)
         cout << "Unable to create an edge." << endl;
      my_words.insert_edge(connected, new_title);
   }while (again());
   
   do
   {
      cout << "Enter a word to display the related words: ";
      cin.get(new_title, SIZE); cin.ignore(SIZE, '\n');
      cout << "Words related to " << new_title << ": " << endl;
      my_words.display_adjacent(new_title);
   }while (again());

   return 0;   
}

//Asks user if they would like to add another connection.
//Returns true for yes and false for everything else.
bool again()
{
   char response;
   cout << "\nAgain (y/n)? " << endl;
   cin >> response; cin.ignore(SIZE, '\n');

   if (response == 'y' || response == 'Y')
      return true;
   else
      return false;
}
