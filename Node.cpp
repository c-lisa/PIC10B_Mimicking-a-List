/** @file Node.cpp
@brief Contains the class definitions for Node class.
@author Lisa Chiang
@date March 7, 2017

Node creates different nodes that contain integer data that have an iterator pointing to the node.
There is a special node at the end of every list that is just a nullptr. Nodes are linked to one
another and these links can be traversed using iterators.
*/

#include "Node.h"
#include <iostream>
#include "List.h"
#include"Iterator.h"

//Constructors
/**@brief Node Default Constructor

Default constructor creates a node and initializes variables by default. 

@param No parameters.
@return No Returns.
*/
Node::Node()
{
	data = 0; 
}
/**@brief Node Constructor

Constructs a node with initial value given by the input argument.

@param data_input is user given data to create a node.
@return No Returns.
*/
Node::Node(int data_input)
{
	data = data_input; 
}

//Operators
/**@brief Node * operator

Returns the value of the node.

@param No parameters.
@return data is an integer that the node contains. 
*/
int Node::operator* ()
{
	return data; 
}