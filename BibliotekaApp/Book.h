#pragma once
#include "Item.h"

using namespace std;

class Author;
class Book
{
	friend class Library;

private:
	string title;
	Author* author;
	string type;
	string language;
	
	typedef int publicationYear;
	publicationYear year;

	bool borrow;


public:
	Book(string , Author*, string, string , int);
	string getFullName();
	Author* getAuthor();

	~Book();
};

