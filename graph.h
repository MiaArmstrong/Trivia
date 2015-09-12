//Mia Armstrong
//CS 163 Assignment 5
//File: graph.h
/* This is the header file for the table class*/

#include "trivia.h"

struct vertex
{
   trivia * word;  //pointer to a trivia object
   struct node * head; //edge list
};

struct node
{
   vertex * adjacent; //pointer to adjacent vertex;
   node * next;
};

class table
{
   public: 
          table(int size=10);
          ~table();
          int insert_vertex(const trivia & to_add);
          int find_location(char * key_value);
          int insert_edge(char * current_vertex, char * to_attach);
          int display_adjacent(char * key_value);
          int display_all() const;
          int remove_all();
   private:
          int display_adjacent(node * head);
          vertex * adjacency_list;
          int list_size;
};
