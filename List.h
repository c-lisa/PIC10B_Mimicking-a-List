/** @file List.h
@brief Contains the class declarations for List class.
@author Lisa Chiang
@date March 7, 2017

List allows the user to store ints as nodes that are accessed by iterating through the list. The list
can be manipulated by the user. 
*/

#ifndef List_h
#define List_h

#include "Node.h"
class Node; 
#include"Iterator.h"
class Iterator; 
#include<algorithm>
#include<vector>

class List {
friend class Iterator;
public:
	//Contructor
	List();
	//Destructor
	~List();

	//Iterator Functions 
	Iterator insert(Iterator pos, int x_input);
	Iterator erase(Iterator &pos);
	Iterator begin(); 
	Iterator end();

	//Non-Iterator Functions
	void push_back(int x_input); 
	void reverse();
	void push_front(int data_input);
	void swap(List& other);
	size_t get_size();
	int maximum();
	void sort();
	void merge(List& other);

private:
	size_t size;
	Node* first;
	Node* last;
};

#endif
