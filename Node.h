/** @file Node.h
@brief Contains the class declarations for Node class. 
@author Lisa Chiang
@date March 7, 2017

Node creates different nodes that contain integer data that have an iterator pointing to the node. 
There is a special node at the end of every list that is just a nullptr. Nodes are linked to one 
another and these links can be traversed using iterators. 
*/

#ifndef Node_h
#define Node_h

#include"List.h"
class List; 
#include"Iterator.h"

class Node {
	friend class List; //contains 2 private variables: first and last element
	friend class Iterator; //contains 2 private variables: node* to currentnode, list* to container of nodes that iterator is pointing to 

public:
	//Constructors
	Node();
	Node(int data_input);
	
	//Operators
	int operator* ();

private:
	int data;
	Node* next; //nullptr if node is last element
	Node* previous; //nullptr if node is first element 
};

#endif