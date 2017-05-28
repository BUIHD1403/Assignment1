/*
* *********ListADT.cpp****************
*
* Class Description: A List ADT - inspired from ListADT from our textbook.
* Class Invariant: List position of elements start at 1 (not 0).
*
* Inspired on: May 18, 2016
* Author: AL
*/

#include <iostream>
#include <string>
//#include "Profile.h"
#include "List.h"  // Header file


// Constructor
List::List() : elementCount(0), capacity(List::MAX_ELEMENTS) {
}


// Description: Returns the current number of elements in the List.
int  List::getElementCount() const
{
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement)
{
	if (elementCount < (MAX_ELEMENTS))
	{
		for (int _count = 0; _count < MAX_ELEMENTS; _count++)
		{
			if (newElement.getCareCard() == elements[_count].getCareCard())
			{
				return false;
			}
		}

		if (elementCount == 0)
		{
			elements[0] = newElement;
			elementCount++;
		}
		else if (elements[0].getCareCard() > newElement.getCareCard())
		{
			for (int place = elementCount ; place > (-1) ; place--)
			{	if(place==0)
				{
					elements[0] = newElement;
					elementCount++;
					return true;
				}
				elements[place] = elements[place-1];
			}
		}
		else
		{
			for (int position = 0; position < elementCount; position++)
			{   
				if ((elements[position].getCareCard() < newElement.getCareCard()) && (elements[position + 1].getCareCard() == "0000000000"))
				{
					elements[position + 1] = newElement;
					return true;
				}
				else if((elements[position].getCareCard() < newElement.getCareCard()) && (elements[position + 1].getCareCard() > newElement.getCareCard()))
				{
				//	int difference;
				//	difference = MAX_ELEMENTS - elementCount;

					for (int j= (elementCount-1); j> position; j--)
					{
						elements[j + 1] = elements[j];
						if (j == (position + 1))
						{
							elements[j] = newElement;
							return true;
						}
					}
				}
			}
			elementCount++;
		}
	}
	return true;
}

// end insert


bool List::remove(const Patient& toBeRemoved)
{   // Check wether the list is empty
	if (elementCount == 0)
		return false;
	else
	{   //Run through the array
		for (int position = 0; position < MAX_ELEMENTS; position++)
		{
			// Check the matching carCard between 2 input
			if (toBeRemoved.getCareCard() == elements[position].getCareCard())
			{   
				// When the removed element is the last of the array
				if (position == (MAX_ELEMENTS - 1))
				{
					elements[position] = Patient();
					return true;
				}
				//When the removed is in the middle of array
				for (int Index = position; Index < elementCount; Index++)
				{
					//When we meet last element of the array
					if(Index==(elementCount-1))
					{
						elements[Index] = Patient();
					}
					else
					{
						elements[Index] = elements[Index + 1];
					}
				}
				elementCount--;
				return true;
			}
		}
	}
	return false;
}  // end remove


   // Description: Removes all elements from the List.
   // Postconditions: List contains no elements and the element count is 0.
void List::removeAll()
{
	elementCount = 0;
}  // end clear

 Patient* List::search(const Patient& target)
 {	    
	 for (int i = 0; i < elementCount; i++)
	 {
		 if (elements[i].getCareCard() == target.getCareCard())
		 {
			 return &elements[i];
		 }
	 }
	 return NULL;
  }

void List::printList()
{
	for (int i = 0; i< elementCount; i++)
	{
		elements[i].printPatient();
		cout <<endl;
	}
	return;
}



//  End of implementation file
