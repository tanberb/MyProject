#pragma once
#include <string>
#include <vector>
#include "Book.h"
#include "Author.h"
#include "Reader.h"

using namespace std;

class Library
{

private:
	vector<Author*> listAuthors;
	vector<Book*> listBooks;
	vector<Reader*> listReaders;

public:
	Library();
	void run();

	void addAuthor(Author*);
	void addAuthor(string name, string lastName);

	void addBook(Book*);
	void addBook(string, Author*, string, string, int);

	void addReader(string, string, string);
	
	void printAuthors();
	void printBooks();
	void printReaders();

	int chooseAuthor();
	int chooseBook();
	int chooseReader();
	friend void przyklad(Author listAuthors , int i);
	

	~Library();
};

