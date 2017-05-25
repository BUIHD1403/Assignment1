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
int  List::getElementCount() const {
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement) {
	int flag=0;
	if (elementCount < (MAX_ELEMENTS - 1))
	{
		for (int count = 0; count < (MAX_ELEMENTS - 1); count++)
		{
			if (newElement.getCareCard == elements[count].getCareCard)
			{
				flag = 1;
			}
		}
		if (flag==1)
		{
			elements[elementCount] = newElement;
			elementCount++;
		}
	}
	return true;
}  // end insert


   // Description: Removes the element at position in the List 
   // Postcondition: If 1 <= position <= getElementCount() and the removal is successful,
   //                the element at position in the List is removed, and
   //                other elements "have moved" 1 position down, 
   //                and the returned value is true. Otherwise, false is returned.
bool ListADT::remove(int position) {
	bool ableToRemove = (position >= 1) && (position <= elementCount);
	if (ableToRemove)
	{
		// Remove Element by shifting all elements after the one at
		// position toward the beginning of the array
		// (no shift if position == elementCount)
		for (int fromIndex = position, toIndex = fromIndex - 1; fromIndex < elementCount;
			fromIndex++, toIndex++)
			elements[toIndex] = elements[fromIndex];

		elementCount--;  // Decrease count of elements
	}  // end if

	return ableToRemove;
}  // end remove


   // Description: Removes all elements from the List.
   // Postconditions: List contains no elements and the element count is 0.
void List::removeAll() {
	elementCount = 0;
	for (int count = 0; count < (MAX_ELEMENTS - 1); count++)
	{
		elements[count].getAddress = "To be entered";
		elements[count].getAddress = "0000000000";
	}

}  // end clear


   // Description: Returns the element at position in the List.
   // Precondition: 1 <= position <= getElementCount().
Profile ListADT::getElement(int position) const {
	Profile toBeReturned;

	// Enforce precondition
	bool ableToGet = (position >= 1) && (position <= elementCount);
	if (ableToGet)
		toBeReturned = elements[position - 1];
	else
	{
		string message = "getElement() called with an empty List or an invalid position.";
		cout << message;  // throw exception may be better
	}  // end if

	return toBeReturned;
}  // end getElement


   // Description: Replaces the element at position by newElement in the List.
   // Precondition: 1 <= position <= getElementCount().
void ListADT::setElement(int position, const Profile& newElement) {
	// Enforce precondition
	bool ableToSet = (position >= 1) && (position <= elementCount);
	if (ableToSet)
		elements[position - 1] = newElement;
	else
	{
		string message = "setElement() called with an empty List or an invalid position.";
		cout << message;  // throw exception may be better
	}  // end if
}  // end setElement

   // Description: Prints all elements in the List.
ostream & operator<<(ostream & os, const ListADT& rhs) {
	for (int index = 0; index < rhs.elementCount; index++)
		os << "Element " << index + 1 << " is " << rhs.elements[index].getName() << endl;

	return os;
} // end of operator << 

  //  End of implementation file