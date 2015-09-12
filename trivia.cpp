//Mia Armstrong
//CS 163 Assignment 5
//File: trivia.cpp
/* This file contains the functions for the trivia class. */

#include "trivia.h"

//This function sets the title and notes to NULL          
trivia::trivia()
{
   title = NULL;
   notes = NULL;
}
          
//This function deallocates the title and notes if they are not NULL
trivia::~trivia()
{
   if(title)
      delete [] title;
   if(notes)
      delete [] notes;
}
          
//This function takes in a new title and new noteds and dynamicaly allocates
//them into new arrays in the data memebers.
//It returns an int, 0 for failure and 1 for success.
int trivia::create_entry(char * new_title, char * new_notes)
{
   if (title)
      delete [] title;
   if (notes)
      delete [] notes;

   if (new_title)
   {
      title = new char[strlen(new_title) +1];
      strcpy(title, new_title); //deep copy title
      

      notes = new char[strlen(new_notes) +1];
      strcpy(notes, new_notes); //deep copy notes
      return 1;
   }
   else
      return 0;
      
}
   
//This function takes the data object as an argument and copies it into the 
//trivia data members. It returns an int, 0 for failure and 1 for success.       
int trivia::copy_entry(const trivia & new_trivia)
{
   if (title)
      delete [] title;
   if (notes)
      delete [] notes; //deallocate memory owned by the current object

   if(!new_trivia.title || !new_trivia.notes)
      return 0; //check for trivia 

   if (new_trivia.title)
   {
      title = new char[strlen(new_trivia.title) +1];
      strcpy(title, new_trivia.title); //deep copy title
   }
   if (new_trivia.notes)
   {
      notes = new char[strlen(new_trivia.notes) +1];
      strcpy(notes, new_trivia.notes); //deep copy notes
   }

}
          
//This function takes an empty trivia object and deep copies the memebers of th
//current object into the found data members.
//It returns a 1 for success and a 0 if there is no data member.
int trivia::retrieve(trivia & found) const
{
   if (title)
   {
      found.title = new char[strlen(title) +1];
      strcpy(found.title, title);

      found.notes = new char[strlen(notes) +1];
      strcpy(found.notes, notes);
   
      return 1;
   }
   else
      return 0;
}
          
//This function takes in a key title as an argument and compares it to the data menber title. 
// It returns true if there is a match or flase if there is no match.
bool trivia::compare (char * key_title)
{
   if(!title || !key_title)
      return 0;
   
   if (strcmp(title, key_title) == 0)
      return true;
   else
      return false;

}
          
//This function displays one trivia object.
//it returns 1 for success and 0 for failure. 
int trivia::display() const
{
   if(title)
   {
      cout << endl;
      cout << "Trivia about:  " << title << endl;
      cout << " * " << notes << endl;
      return 1;
   }
   else
      return 0;
}

