#include <iostream>
#include "Patient.h""

Patient::Patient() : name("To be entered"), address("To be entered"), phone("To be entered"), email("To be entered"), careCard("0000000000") {
}

Patient::Patient(string aCareCard) {
	if (aCareCard.length()!=10)
	{
		careCard = "0000000000";
	}
	else
	{
		careCard = aCareCard;
	}
	name = "To be entered";
	address = "To be entered";
	phone = "To be entered";
	email = "To be entered";

}

string Patient::getName() const
{
	return name;
}

string Patient::getAddress() const
{
	return address;
}

string Patient::getEmail() const
{
	return email;
}

string Patient::getPhone() const
{
	return phone;
}

string Patient::getCareCard() const
{
	return careCard;
}

void Patient::setName(const string aName)
{
	name = aName;
	return;
}

void Patient::setAddress(const string anAddress)
{
	address = anAddress;
	return;
}

void Patient::setEmail(const string anEmail)
{
	email = anEmail;
	return;
}

void Patient::setPhone(const string aPhone)
{
	phone = aPhone;
	return;
}

bool Patient::operator==(const Patient & rhs)
{
	if (careCard.compare(rhs.careCard) == 0)
		return true;
	else
		return false;
}

bool Patient::operator > (const Patient & rhs)
{
	for (int i = 0; i < 10; i++)
	{
		if ((careCard[i] - '0') >(rhs.careCard[i] - '0'))
			return true;
		else
			return false;
	}

}

void Patient::printPatient()
{
	cout << getCareCard() << ", " << " Patient:";
	cout << getName() << ", " << getAddress() << ", " << getPhone() << ", " << getEmail();
	return;
}
