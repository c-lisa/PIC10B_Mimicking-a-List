/** @file Iterator.h
@brief Contains the class declarations for Iterator class.
@author Lisa Chiang
@date March 7, 2017

Iterator allows you to traverse through the List class to access nodes via node pointers. 
*/

#ifndef Iterator_h
#define Iterator_h

class List; 
class Node; 

class Iterator {
public:
	friend class List;

	//Constructor
	Iterator(Node* temp, List* I);

	//Operators
	Iterator& operator ++ ();
	Iterator operator++(int unused);
	Iterator& operator --();
	Iterator operator--(int unused);
	int operator* ();

	//Comparisons
	bool operator == (const Iterator& B); 
	bool operator != (const Iterator& B); 

private:
	Node* position; //points to current node object 
	List* lst; //which list it is
};

#endif