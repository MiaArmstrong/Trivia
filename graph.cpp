//Mia Armstrong
//CS 163 Assignment 5
//File: graph.cpp
/* this file contains the functions for the table class*/

#include "graph.h"

//This is the constructor for the table class 
//It takes in an int as an argument to set the list size and help create the 
//adjacency list.          
table::table(int size)
{
   list_size = size;

   adjacency_list = new vertex[list_size];

   for (int i = 0; i < list_size; ++i)
   {
      adjacency_list[i].word = NULL;
      adjacency_list[i].head = NULL;
   }
}
          
//This is the destructor for the table class. 
//It uses the remove_all function to deallocate the nodes in the list and 
//then deallocates the list. 
table::~table()
{
    remove_all();
    delete adjacency_list;
    adjacency_list = NULL;      
}
          
//This function inserts a new word into each index.
//It takes in a triva object to_add and returns a 1 for success or a 0
//if the list is full.
int table::insert_vertex(const trivia & to_add)
{
   for (int i = 0; i < list_size; ++i)
   {
      if (!adjacency_list[i].word)
      {
         adjacency_list[i].word = new trivia;
         adjacency_list[i].word->copy_entry(to_add);
         return 1;
      }
      else if (i == list_size - 1)
         return 0;
    }
}

//This funtion finds the index of the word on the list.
//It takes in a key_value and returns a -1 for not found or the index.          
int table::find_location(char * key_value)
{
   if (!adjacency_list)
      return -1;

   bool match = false;

   for (int i = 0; i < list_size; ++i)
   {
      match = adjacency_list[i].word->compare(key_value);
      if (match)
         return i;
   }
   return -1;
   //return the location of this particular key value or -1
}
          
//This function creates a pointer from the current vertex's adjacency list
//to a different vertex. 
//It takes in a char of the current vertex and one of the vertex to attach to.
//Returns 0 for failure and 1 for success.
int table::insert_edge(char * current_vertex, char * to_attach)
{
   int from = 0;
   int to = 0;

   from = find_location(current_vertex);
   to = find_location(to_attach);
   if (from < 0 || to < 0)
      return 0;
       
   node * temp = new node;
   temp->adjacent = & adjacency_list[to];
   temp->next = adjacency_list[from].head;;
   adjacency_list[from].head = temp; 

   return 1;  
}
          
//This function displays the adjacency list of the vertex.
//It takes in a key value and returns 0 for failure and 1 for success.
int table::display_adjacent(char * key_value)
{
   int key = 0;
 
   key = find_location(key_value);
   if (key < 0)
      return 0;

   display_adjacent(adjacency_list[key].head);
   return 1;

  
}
 
//This function takes in a node * from the wrapper function and traverses the adjacency list to display it.
//It takes in a node * and returns a -1 if the list is empty or a 1 if success.
int table::display_adjacent(node * head)
{
   if (!head)
      return -1;
   head->adjacent->word->display();
   display_adjacent(head->next);
}         

//This function displays the entier adjacency list.
//It returns a 0 for failure and a 1 for success.
int table::display_all() const
{
   for (int i = 0; i < list_size; ++i)
   {
      if (adjacency_list[i].word)
         adjacency_list[i].word->display();
      else
         return 0;
   }
   return 1;
}
          
//This function removes all data from the adjacency list.
//It returns 1 for success. 
int table::remove_all()
{
   
   for (int i = 0; i < list_size; ++i)
   {
      node * temp = adjacency_list[i].head;
      while (temp)
      {
         temp = adjacency_list[i].head->next;
         delete adjacency_list[i].head;
         adjacency_list[i].head = temp;
      }
      adjacency_list[i].head = NULL;
      delete adjacency_list[i].word;
      adjacency_list[i].word = NULL;
    }
    return 1;
}

