#include "Author.h"
#include <iostream>

using namespace std;

Author::Author()
{
}

Author::Author(string name, string lastName)
{
	this->name = name;
	this->lastName = lastName;
}

void Author::addBook(Book* book)
{
	this->listBooks.push_back(book);
}

void Author::delBook(Book* book)
{
	for (int i = 0; i < this->listBooks.size(); i++) {
		if (this->listBooks[i] == book) {
			this->listBooks.erase(this->listBooks.begin() + i);
			break;
		}
	}
}

void Author::printListBooks()
{
	for each (Book* book in this->listBooks)
	{
		cout << "Book: " << book->getFullName() << endl;
	}
}

string Author::getFullName()
{
	return this->name + " " + this->lastName;
}

void Author::setName(string name)
{
	this->name = name;
}

void Author::setLastName(string lastName)
{
	this->lastName = lastName;
}



Author::~Author()
{
	cout << "Author delete" << endl;
	for each (Book* book in this->listBooks)
	{
		delete book;
	}
}
