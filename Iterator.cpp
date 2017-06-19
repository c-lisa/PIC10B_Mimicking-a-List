/** @file Iterator.cpp
@brief Contains the class definitions for Iterator class.
@author Lisa Chiang
@date March 7, 2017

Iterator allows you to traverse through the List class to access nodes via node pointers.
*/
#include "Iterator.h"
#include "Node.h"
#include <iostream>
#include "List.h"

//Constructor
/**@brief Iterator Constructor

Creates an iterator pointing to the input node.

@param temp is a pointer to the user created node. 
@param I is the pointer to a specific list 
@return No returns. 
*/
Iterator::Iterator(Node* temp, List* I)
{
	position = temp; 
}

//Operators
/**@brief ++Prefix 

Increments the iterator to the next node. If the iterator is currently pointing to the
special end of list node, then do nothing

@param No parameters. 
@return Returns an Iterator pointing to next node.
*/
Iterator& Iterator::operator ++ ()
{
	if (position->next != NULL)
	{
		position = position->next;
	}
	return *this; 
}
/**@brief Postfix++

Increments the iterator to the next node. If the iterator is currently pointing to the
special end of list node, then do nothing. 

@param Unused integer that differentiates from prefix.
@return Returns an Iterator pointing to next node.
*/
Iterator Iterator::operator++(int unused)
{
	Iterator clone(*this); 
	++(*this); 
	return clone; 
}
/**@brief --Prefix

Decrements the iterator to the previous node. If the iterator is currently pointing to
the rst element, then do nothing.

@param No parameters.
@return Returns an Iterator pointing to previous node.
*/
Iterator& Iterator::operator --()
{
	if (position->previous != NULL)
	{
		position = position->previous;
	}
	return *this; 
}
/**@brief Postfix--

Increments the iterator to the next node. If the iterator is currently pointing to the
special end of list node, then do nothing.

@param Unused integer that differentiates from prefix.
@return Returns an Iterator pointing to previous node.
*/
Iterator Iterator::operator--(int unused)
{
	Iterator clone(*this);
	--(*this);
	return clone;
}
/**@brief Iterator * operator

Returns the value contained in the node currently pointed to by the Iterator.

@param No parameters. 
@return Returns the int of the node that the iterator is pointing to. 
*/
int Iterator::operator* () 
{
	if (position != nullptr)
	{
		return position->data; 
	}
}

//Comparisons
/**@brief Iterator == operator

Checks if two Iterators are pointing to the same element. 

@param B is the iterator that is being compared to the implict iterator. 
@return Returns true if they are equal and false otherwise. 
*/
bool Iterator::operator == (const Iterator& B)
{
	if (position == B.position)
	{
		return true;
	}
	else return false;
}
/**@brief Iterator != operator

Checks if two Iterators are not pointing to the same element.

@param B is the iterator that is being compared to the implict iterator.
@return Returns false if they are equal and true otherwise.
*/
bool Iterator::operator != (const Iterator& B)
{
	if (position == B.position)
	{
		return false;
	}
	else return true;
}
