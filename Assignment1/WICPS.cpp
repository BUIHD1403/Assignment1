#include <iostream>
#include <string>
#include <cctype>
#include "Patient.h"
#include "List.h"

using namespace std;

void join(List & theMembers) {
	string care_card = "";
	// Create a new member profile
	cout << "Please, enter patient careCard number: ";
	// Remove all leading whitespace -> ws

	getline(cin >> ws, care_card);
	
	Patient theMember(care_card);

	int position = 0;
	// Figure out the position of new element
	position = theMembers.getElementCount();

	// Add new member profile to the end of list
	if (theMembers.insert(theMember))
		// Report to user
	{
		cout << "Patient: ";
		theMember.printPatient();
		cout << " has successfully added." << endl;
	}
	else
	{
		cout << "Patient: ";
		theMember.printPatient();
		cout << " cannot be added." << endl;
	}
	return;
}


void leave(List & theMembers) {
	string care_card = "0000000000";

	if (theMembers.getElementCount() != 0)
	{
		// Get the member's position in the list
		theMembers.printList();
		cout << "Please, enter the careCard of patient u wanna remove :";
		cin >> care_card;

		Patient theMember(care_card);
		// Remove member profile from list
		if (theMembers.remove(theMember))
			cout << "Member has now remove." << endl;
		else
			cout << "Member was unable to leave FriendsBook!" << endl;
	}
	else
		cout << "There are no members in FriendsBook yet!" << endl;

	return;
}

void _print(List & theMembers)
{
	theMembers.printList();
	return;
}

int main() {

	// Variables declaration
	List members;
	bool done = false;
	char input = 0;

	// Keep doing what the user selects until the user exits
	while (done!=true) {
		// Print menu to user
		cout << "\n----Welcome to WICPS!\n" << endl;
		cout << "To insert patient enter: j" << endl;
		cout << "To remove patient enter: l" << endl;
		cout << "To print patient enter: p" << endl;

		//  cout << "To search a patient  enter: m" << endl;
		// cout << "To modify a patient record  enter: s" << endl;
		//   cout << "To print all patient  enter: x\n" << endl;

		cout << "Your choice: ";
		cin >> input;
    	input = tolower(input);
		switch (input) {
		case 'j': join(members); break;
		case 'l': leave(members); break;
		case 'p': _print(members); break;
			// case 'm': modify(members); break;
			//  case 's': search(members); break;
		case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
		default: cout << "Not sure what you mean! Please, try again!" << endl;
		}
		cout << "There are now " << members.getElementCount() << " members in FriendsBook." << endl;
		members.printList();
	}

	return 0;
}
