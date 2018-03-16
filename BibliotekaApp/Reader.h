#pragma once

#include <vector>
#include "Book.h"

using namespace std;
class Reader
{
protected:
	string name;
	string lastName;
	string adress;
	vector<Book*> listBooks;
public:
	Reader(string, string, string);
	bool checkBooks();
	int getSizelostBooks();
	void addBook(Book *book);
	void delBook(Book *book);
	string getFullName();


	Book* getBookByIndex(int);
	void printListBooks();

	void setName(string);
	void setLastName(string);
	void setAdress(string);
	

	~Reader();
};

