#include "Reader.h"
#include <iostream>
using namespace std;

Reader::Reader(string name, string lastName, string adress)
{
	this->name = name;
	this->lastName = lastName;
	this->adress = adress;
}

bool Reader:: checkBooks()//warunek wypozyczenia co najwyzej 3 ksiazek
{
	return this->listBooks.size() < 3;
}
 
int Reader::getSizelostBooks()
{
	return this->listBooks.size();
}

void Reader::addBook(Book * book)
{ 
	this->listBooks.push_back(book);
}

void Reader::delBook(Book * book)
{
	for (int i = 0; i < this->listBooks.size(); i++) {
		if (this->listBooks[i] == book) {
			this->listBooks.erase(this->listBooks.begin() + i);
			break;
		}
	}
}

string Reader::getFullName()
{
	return this->name + " " + this->lastName +" "+ this->adress;
}

Book * Reader::getBookByIndex(int index)
{
	return this->listBooks[index];
}

void Reader::printListBooks()
{
	for (int i = 0; i < this->listBooks.size(); i++)
	{
		
		cout << i + 1 << " " << this->listBooks[i]->getFullName() << endl;
	}
}

void Reader::setName(string name)
{
	this->name = name;
}

void Reader::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Reader::setAdress(string adress)
{
	this->adress = adress;

}


Reader::~Reader()
{

}
