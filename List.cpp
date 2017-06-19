#include "Node.h"
#include <iostream>
#include "List.h"
#include "Iterator.h"
#include <vector>
#include <algorithm>

//Constructor
/**@brief List Constructor

Constructor that creates the default special node.

@param No parameters.
@return No returns.
*/
List::List()
{
	Node* special = new Node(-1); 
	special -> next = NULL;  
	special->previous = NULL; 

	first = special; 
	last = special; 
}

//Destructor
/**@brief List Destructor

Destructor that deletes all memory created internally by the List class.

@param No parameters.
@return No returns.
*/
List::~List()
{
	Iterator first = begin();
	for (int i = 1; i <= get_size(); i++)
	{
		first = erase(first); 
	}
	erase(first); 
}

//Iterator Functions
/**@brief Insert

Inserts a node before the position of the rst parameter. The node should have
the value of the second input argument. Returns an iterator pointing to the newly
inserted node.

@param pos is the Iterator we want to insert the node before. 
@param x_input is the int of the node we want to create. 
@return Returns an Iterator pointing to newly inserted node. 
*/
Iterator List::insert(Iterator pos, int x_input)
{
	Node* insert_pos = pos.position; 

	Node* temp = new Node(x_input); 
	//setting temp's next to the given iterator pos 
	temp->next = insert_pos; 

	//accessing previous node 
	Node* previous_node; 
	previous_node = insert_pos->previous; 

	if (previous_node == nullptr)
	{
		//node is first node in list
		first = temp;
		//setting first's previous pointer to null 
		first->previous = nullptr;
	}
	else //there is some node before this inserted node
	{
		//setting previous node's next to temp
		previous_node->next = temp;
		//setting temp's previous to previous node 
		temp->previous = previous_node;
	}
	
	//setting given iterator pos's previous to temp 
	insert_pos->previous = temp; 

	return Iterator(temp, this); 
}
/**@brief Erase

Erases the node from the List pointed to by the input argument. Returns an Iterator
to the node after the erased node.

@param pos is the Iterator to the node we want to erase.
@return Returns an Iterator pointing to the node after the erased node. 
*/
Iterator List::erase(Iterator &pos)
{
	Node* erase_this = pos.position;

	//accessing previous node 
	Node* previous_node;
	previous_node = erase_this->previous;

	Node* next_node; 
	next_node = erase_this->next; 

	//checking if next is not equal to null ptr
	if (erase_this->next != nullptr)
	{
		//previous is a node 
		if (erase_this->previous != nullptr)
		{
			//setting previous node's next to next node
			previous_node->next = next_node; 
			//setting nextnode's previous to previous node 
			next_node->previous = previous_node; 
			delete erase_this;
		}
		//previous is nullptr
		else
		{
			first = next_node; 
			first->previous = nullptr; 
			delete erase_this;
		}
		return Iterator(next_node, this); 
	}
}
/**@brief Getting the beginning

Returns an iterator pointing to the first node. 

@param No parameters. 
@return Returns an Iterator pointing to the first node. 
*/
Iterator List::begin()
{
	return Iterator(first, this);
}
/**@brief Getting the end (special node) 

Returns an iterator pointing to one after the last node, i.e., the special node.

@param No parameters.
@return Returns an Iterator pointing to the last node (special node).
*/
Iterator List::end()
{
	return Iterator(last, this);
}

//Non-Iterator Functions
/**@brief Reverse

Reverses the order of the nodes in a list.

@param No parameters. 
@return Returns nothing. 
*/
void List::reverse()
{
	Node* x = first; 
	Node* y = first; 

	if (get_size() != 0)
	{
		if (get_size() != 1)
		{
			for (int i = 1; i <= get_size() / 2; i++)
			{
				y = first;
				for (int j = 1; j <= get_size(); j++)
				{
					if ((i + j) == (get_size() + 1))
					{
						int a = x->data;
						x->data = y->data;
						y->data = a;
					}
					y = y->next;
				}
				x = x->next;
			}
		}
	}
}
/**@brief Pushback

Adds a value to the end of the list before the special node. 

@param data_input is the int of the second to last node (last is special node). 
@return Returns nothing.
*/
void List::push_back(int data_input)
{
	//update prev, next, check if first
	//changed temp's current pointer to point to special node
	Node* temp = new Node(data_input);
	temp->next = last;

	//accessing previous node 
	Node* previous_node;
	previous_node = last->previous;

	if (previous_node != nullptr)
	{
		//setting previous node's next to temp
		previous_node->next = temp;
		//setting temp's previous to previous node
		temp->previous = previous_node;
	}
	else
	{
		//node is first node in list
		first = temp;
		//setting first's previous pointer to null 
		first->previous = nullptr;
	}
	//setting special node's previous to temp
	last->previous = temp;
}
/**@brief Pushfront

Adds a value to the beginning of the list.

@param data_input is the int of the first node. 
@return Returns nothing.
*/
void List::push_front(int x_input) 
{
	//changed temp's current pointer to point to special node
	Node* new_first = new Node(x_input);
	new_first->previous = nullptr;

	//accessing next node aka old first 
	Node* previous_first_node;
	previous_first_node = first; 

	//making the new first node's next the previous first node
	new_first->next = previous_first_node; 
	//making the previous first node's previous the new first node
	previous_first_node->previous = new_first; 
	
	//making the new first node the first node
	first = new_first;
}
/**@brief Swap

Swaps the elements on implicit list and other. This works in O(1) time. 

@param other is the List of whose elements is being swapped with the implicit list. 
@return Returns nothing.
*/
void List::swap(List& other)
{
	Node* temp = first; 
	Node* temp2 = other.first; 

	first = temp2; 
	other.first = temp; 

	Node* temp3 = last; 
	Node* temp4 = other.last; 

	last = temp4; 
	other.last = temp3; 
}
/**@brief Get Size

Returns the number of elements in the list.

@param No parameters. 
@return Returns a size_t that is the number of elements in the list. 
*/
size_t List::get_size()
{
	size_t size = 0; 
	for (Node* here = first; here != last; here = here->next)
	{
		size++; 
	}
	return size; 
}
/**@brief Maximum

Computes the largest element in a List.

@param No parameters.
@return Returns the int that is the largest int in the list. 
*/
int List::maximum()
{
	Iterator A = this->begin(); 
	int temp = *A; 

	for (int i = 1; i <= get_size(); i++)
	{
		if (temp < *A)
		{
			temp = *A; 
		}
		++A;
	}

	return temp; 
}
/**@brief Sort

Sorts the elements of a linked list (without copying them into a vector or another data type).

@param No parameters.
@return Returns nothing.
*/
void List::sort()
{	
	Node* y = first; 
	std::vector <int> theirnumbers; 
	theirnumbers.push_back(y->data); 

	//pushing back data of y 
	for (int i = 0; i < get_size()-1; i++)
	{
		y = y-> next; 
		theirnumbers.push_back(y->data);
	}
	std::sort(theirnumbers.begin(), theirnumbers.end()); 
		
	Iterator A = begin();
	for (int i = 0; i < get_size(); i++)
	{
		A.position->data = theirnumbers[i];
		++A; 
	}
}
/**@brief Merge

Merges the two lists into one, storing the merged list into the object that called the function. 
It alternates the elements from each list until the end of one of the lists has been reached and then appends the remaining elements of the other list.
For example, merging the lists containing 1 7 12 and 8 3 11 2 2 1 yields the list 1 8 7 3 12 11 2 2 1.

@param other is the list being merged with the implicit list that called the function.
@return Returns nothing.
*/
void List::merge(List& other)
{
	int one = get_size(); 
	int two = other.get_size(); 
	Iterator A = begin(); //for list A
	Iterator B = other.begin(); //for list B 
	++A; //A is now pointing to element two in calling list 

	if (one > two)
	{
		for (int i = 1; i <= two; i++)
		{
			A = insert(A, *B); 
			++A; ++A; ++B; 
		}
	}
	else if (two > one)
	{
		for (int i = 1; i <= (one-1); i++)
		{
			A = insert(A, *B);
			++A; ++A; ++B;
		}
		for (int j = 1; j <= (two - (one - 1)); j++)
		{
			push_back(*B); 
			++B; 
		}
	}
	else 
	{
		for (int i = 1; i <= two; i++)
		{
			A = insert(A, *B);
			++A; ++A; ++B;
		}
	}
}