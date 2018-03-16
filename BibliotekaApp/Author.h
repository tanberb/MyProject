#pragma once
#include <string>
#include <vector>
#include "Book.h"


using namespace std;
class Book;

class Author
{
private:
	string name;
	string lastName;
	vector<Book*> listBooks;
	friend class Library;
public:
	Author();
	Author(string name, string lastName);
	void addBook(Book* book);
	void delBook(Book* book);
	void printListBooks();
	string getFullName();

	void setName(string);
	void setLastName(string);
	
	friend void przyklad(Author listAuthors, int i);

	~Author();
};

