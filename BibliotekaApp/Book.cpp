#include "Book.h"
#include "Item.h"
#include <iostream>
#include "Reader.h"


using namespace std;

Book::Book(string title, Author* author, string type, string language, int year)
	//:Item(title, author)
{
	this->title = title;
	this->author = author;
	this->type = type;
	this->language = language;
	this->year = year;

	this->borrow = false;

	author->addBook(this);
}

string Book::getFullName()
{
	if (this->borrow) {
		return this->title + " wpozyczona ";
	}
	return  this->title + " " + this->type + " " + this->language;

}

Author * Book::getAuthor()
{
	return this->author;
}


Book::~Book()
{
	cout << "Book delete" << endl;
	this->author->delBook(this);
}
