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

		if(elementCount==0)
            elements[0]= newElement;
         else
                {
                    for(int position=0; position < elementCount; position++)
                        {
                           if(( elements[position].getCareCard() < newElement.getCareCard() ) && ( elements[position+1].getCareCard()== "0000000000") )
                              {
                                elements[position+1]= newElement;
                              }

                           else if ( ( elements[position].getCareCard() < newElement.getCareCard() ) && (elements[position+1].getCareCard() > newElement.getCareCard()) )
                           {
                                int difference;
                                difference = MAX_ELEMENTS - elementCount;

                                for (int j=difference; j> position; j-- )
                                {
                                    elements[j+1]= elements[j];
                                }
                           }

                        }
                }
            elementCount++;
		}
	return true;
	}

  // end insert


bool List::remove(const Patient& toBeRemoved)
 {
	if (elementCount==0)
        return false;
    else
        { for (int position=0; position < MAX_ELEMENTS; position++)
            {
                int _count= position;
                if(toBeRemoved.getCareCard()==elements[_count].getCareCard())
                    {
                        for (int Index = _count; Index < elementCount; Index++)
                            {
                                elements[Index]= elements[Index+1];
                            }
                        elementCount--;
                    }
                else
                    return false;
            }
        }
}  // end remove


   // Description: Removes all elements from the List.
   // Postconditions: List contains no elements and the element count is 0.
void List::removeAll()
{
	elementCount = 0;
}  // end clear

/*Patient Patient::search(const Patient& target)
{
    for
}*/

void List::printList()
{
  for(int i=0; i< elementCount; i++)
        {
            elements[i].printPatient();
        }
    return;
}



  //  End of implementation file
