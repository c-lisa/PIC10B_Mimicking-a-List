/** @file main.cpp
@brief Mimics the function of the List class. 
@author Lisa Chiang
@date March 7, 2017

Allows user to create a list that stores different nodes and manipulates the list in different ways such as reversing, downsizing, 
inserting, deleting, etc. These are done using iterators that traverse through the list class. 
*/

#include <list>
#include <iostream>
#include <string>
#include "List.h"

//Non-member function declariation for downsizing 
void downsize(List& names); 

int main()
{
	//inputting numbers for list
	std::cout << "Please input a set of nonnegative numbers for a List (Enter -1 when you are finished): " << std::endl;
	List integers; 
	int x; 
	
	do
	{
		std::cin >> x; 
		if (x >= 0)
		{
			integers.push_back(x); 
		}
	}
	while (x >= 0); 

	//printing the ORIGINAL list 
	std::cout << "Your list is" << std::endl << "("; 
	int size = 1; 
	for (const auto& x : integers)
	{
		std::cout << x; 
		
		if (size != integers.get_size())
		{
			std::cout << ",";
		}

		size++;
	}
	std::cout << ")" << std::endl << std::endl;

	//inputting indexes/values for insertion 
	int index; 
	int value; 
	do
	{
		std::cout << "Select an index for insertion(enter - 1 when finished) : ";
		std::cin >> index;

		if (index >= 0)
		{
			std::cout << "Select a value for insertion: ";
			std::cin >> value;

			Iterator A = integers.begin(); 
			for (int i = 1; i < (index + 1); i++)
			{
				++A; 
			}

			integers.insert(A, value); 
		}
	} while (index >= 0); 

	//printing the list WITH INSERTIONS
	std::cout << std::endl << "The augmented List is" << std::endl << "(";
	size = 1;
	for (const auto& x : integers)
	{
		std::cout << x;

		if (size != integers.get_size())
		{
			std::cout << ",";
		}

		size++;
	}
	std::cout << ")" << std::endl << std::endl;
		
	//getting maximum of list and printing MAXIMUM
	std::cout << "The maximum of the List is : ";  
	std::cout << integers.maximum() << std::endl; 

	//getting size of list and printing SIZE of list
	std::cout << "The size of the List is : " << integers.get_size() << std::endl;
	
	//downsizing the list 
	std::cout << "When we remove every second value from this list we are left with" << std::endl << "(";
	downsize(integers); 
	
	//printing the DOWNSIZED list 
	size = 1;
	for (const auto& x : integers)
	{
		std::cout << x;

		if (size != integers.get_size())
		{
			std::cout << ",";
		}

		size++;
	}
	std::cout << ")" << std::endl;

	//SORTING the list
	std::cout << "When we sort this downsized list we obtain" << std::endl << "(";
	integers.sort(); 
	
	//printing SORTED list 
	size = 1;
	for (const auto& x : integers)
	{
		std::cout << x;

		if (size != integers.get_size())
		{
			std::cout << ",";
		}

		size++;
	}
	std::cout << ")" << std::endl;
	
	//reversing the list
	std::cout << "And this sorted list in reverse order is" << std::endl << "(";
	integers.reverse(); 
	
	//printing REVERSED list 
	size = 1;
	for (const auto& x : integers)
	{
		std::cout << x;

		if (size != integers.get_size())
		{
			std::cout << ",";
		}

		size++;
	}
	std::cout << ")" << std::endl;

	//merging the list
	std::cout << "If we merge this list with the list (2, 3, 5, 7, 11) we obtain" << std::endl << "(";
	List other; other.push_back(2);	other.push_back(3);	other.push_back(5);	other.push_back(7);	other.push_back(11);
	integers.merge(other); 
	
	//printing MERGED list 
	size = 1;
	for (const auto& x : integers)
	{
		std::cout << x;

		if (size != integers.get_size())
		{
			std::cout << ",";
		}

		size++;
	}
	std::cout << ")" << std::endl;

	return 0; 
}

/**@brief Downsizing List

Removes every second value from a linked list. 

@param names is the List object that is being downsized. 
@return No returns. 
*/
void downsize(List& names)
{
	Iterator A = names.begin();
	int size = names.get_size();

	//if odd size 
	if ((size % 2) != 0)
	{
		for (int i = 1; i <= (size - 1); i++)
		{
			//if i is even 
			if ((i % 2) == 0)
			{
				//you want to erase that 
				A = names.erase(A);
				//should be automatically incremented
			}
			else
			{
				//increment A 
				++A;
			}
		}
	}
	//if even size 
	else if ((size % 2) == 0)
	{
		for (int i = 1; i <= (size); i++)
		{
			//if i is even 
			if ((i % 2) == 0)
			{
				//you want to erase that 
				A = names.erase(A);
				//should be automatically incremented
			}
			else
			{
				//increment A 
				++A;
			}
		}
	}
}