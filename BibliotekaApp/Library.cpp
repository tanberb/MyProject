#include "Library.h"
#include "Author.h"
#include "Book.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;


Library::Library()
{
}

void Library::run()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	cout << "\t\tBIBLIOTEKA" << endl;
	cout << endl;
	cout << "\ta - dodaj Autora" << endl;
	cout << "\tb - dodaj Ksiazke" << endl;
	cout << endl;
	cout << "\tc - wyswietl Autorow" << endl;
	cout << "\td - wyswietl Ksiazki" << endl;
	cout << endl;
	cout << "\te - usun Autora" << endl;
	cout << "\tf - usun Ksiazke" << endl;
	cout << endl;
	cout << "\tg - edytuj Autora" << endl;
	cout << "\th - edytuj Ksiazke" << endl;
	cout << endl;
	cout << "\ti - dodaj Czytelnika" << endl;
	cout << "\tj - wyswietl Czytelnikow" << endl;
	cout << endl;
	cout << "\tk - wyswietl ksiazki Czytelnika" << endl;
	cout << "\tl-  edytuj Czytelnika" << endl;
	cout << "\tx - usun Czytelnika" << endl;
	cout << endl;
	cout << "\tm - wypozycz" << endl;
	cout << "\tn - oddaj" << endl;
	cout<< " \to - zmien imie autora" << endl;
	cout << endl;
	cout << "\tq - Wyjscie" << endl;
	cout << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	char key = 'q';

	cin >> key;

	switch (key)
	{
	case 'a': { //dodaj autora

		cout << "\nPodaj imie i naziwsko autora\n" << endl;

		string name = "";
		string lastName = "";

		cin >> name >> lastName;

		this->addAuthor(name, lastName);

		this->run();
		break;
	}
	case 'b': { //dodaj ksiazke

		if (this->listAuthors.size() == 0) {
			cout << "Brak autorow";
			this->run();
			break;
		}

		int author = this->chooseAuthor();

		cout << "\nPodaj: tytul, gatunek, jezyk, rok wydania\n" << endl;

		string title = "";
		string type = "";
		string language = "";
		int year = 0;

		cin >> title >> type >> language >> year;

		this->listAuthors[author];
		this->addBook(title, this->listAuthors[author], type, language, year);

		this->run();
		break;
	}
	case 'c': { //wyswietl autorow
		this->printAuthors();
		this->run();
		break;
	}
	case 'd': { //wyswietl ksiazki
		this->printBooks();
		this->run();
		break;
	}
	case 'e': { //usun autora

		int authorIndex = this->chooseAuthor();

		Author *author = this->listAuthors[authorIndex];
		
		for (int i = 0; i < this->listBooks.size(); i++)
		{
			Author *a = (this->listBooks[i])->getAuthor();
			if (author == a) {
				this->listBooks.erase(this->listBooks.begin() + i);
				i--;
			}
		}

		this->listAuthors.erase(this->listAuthors.begin() + authorIndex);
		//usowa autora i jego ksiazki
		delete author;

		this->run();
		break;
	}
	case 'f': { //usun ksiazki
		
		int bookIndex = this->chooseBook();

		Book *book = this->listBooks[bookIndex];

		for each(Reader* reader in this->listReaders) 
		{
			reader->delBook(book);

		}


		this->listBooks.erase(this->listBooks.begin() + bookIndex);

		delete book;

		this->run();
		break;
	}
	case 'g': { //edytuj autora
		int authorIndex = this->chooseAuthor();

		Author *author = this->listAuthors[authorIndex];

		cout << "\nPodaj nowe imie i naziwsko autora\n" << endl;

		string name = "";
		string lastName = "";

		cin >> name >> lastName;

		author->setName(name);
		author->setLastName(lastName);

		this->run();
		break;
	}
	
	case 'i': { //dodaj  czytelnika
		cout << "\nPodaj imie, naziwsko, adres czytelnika\n" << endl;

		string name = "";
		string lastName = "";
		string adress = "";

		cin >> name >> lastName >> adress;

		this->addReader(name, lastName, adress);

		this->run();
		break;
	}
	case 'j': { //wyswietl czytelnikow
		
		this->printReaders();

		this->run();
		break;
	}
	case 'k'://wyswietl ksiazki danego  czytelnika
		{
			int readerIndex = this->chooseReader();

			Reader* reader = this->listReaders[readerIndex];

			if (reader->getSizelostBooks() > 0) {

				cout <<"Ksiazki czytelnika: "<< endl;
				reader->printListBooks();
			}
	
		else {
		cout << "\n Czytelniek nie ma wypozyczonych ksizek " << endl;
		}

		this->run();
		break;
	}
	
	case 'l': {//edytuj czytelnika

		int readerIndex = this->chooseReader();

		Reader *reader = this->listReaders[readerIndex];
		cout << "Podaj nowe imie, nazwisko adres czytelnika" << endl;

		string name = "";
		string lastName = "";
		string adress = "";

		cin >> name >> lastName >> adress;

		reader->setName(name);
		reader->setLastName(lastName);
		reader->setAdress(adress);

		this->run();
		break;
	}
	case 'x': {  //usun czytelnika
		int readerIndex = this->chooseReader();

	//	Reader* reader = this->listReaders[readerIndex];
		
				int bookIndex = 0;
				Book* book = this->listBooks[bookIndex];

				if (book->borrow) {

					book->borrow = true;
					cout << "\nNie mozesz skasowac czytelnika bo ma wypozyczone ksiazki" << endl;
					this->run();
				}
			
				else{
					
					this->listReaders.erase(this->listReaders.begin() + readerIndex);

					cout << "Skasowales wybranego czytelnika";
					}

			this->run();
			break;
			
			}
	case 'm': { //wypzycz

		int readerIndex = this->chooseReader();

		Reader* reader = this->listReaders[readerIndex];

		if (reader->checkBooks()) {

			int bookIndex = this->chooseBook();

			Book* book = this->listBooks[bookIndex];

			if (!book->borrow) {

				book->borrow = true;

				reader->addBook(book);
			}
			else {
				cout << "\nKsiazka jest wypozyczona" << endl;
			}
		}
		else {
			cout << "\nMasz za duzo ksiazek" << endl;
		}
		 
		this->run();
		break;
	}
	case 'n': { //oddaj

		int readerIndex = this->chooseReader();

		Reader* reader = this->listReaders[readerIndex];

		if (reader->getSizelostBooks() > 0) {

			cout << "\nWybierz ksiazke" << endl;
			reader->printListBooks();

			int bookIndex = 0;

			cin >> bookIndex;

			bookIndex = bookIndex - 1;

			Book* book = reader->getBookByIndex(bookIndex);

			book->borrow = false;
			 
			reader->delBook(book);
		}
		else {
			cout << "\nBrak ksiazek do oddania" << endl;
		}

		this->run();
		break;
	}
	case 'o': { // zmien imie  i nazwisko autora 

		int authorIndex = this->chooseAuthor();

		Author *author = this->listAuthors[authorIndex];
		string name = "";
		string lastName = "";
		//int i=0;
		void przyklad(Author auth);
		
		author->setName(name);
		author->setLastName(lastName);

		this->run();
		break;
	}
	case 'q': {
		// mo¿na czyœciæ elementy
		system("exit");
		break;
	}
	default:
		break;
	}
}

void Library::addAuthor(Author *author)
{
	this->listAuthors.push_back(author);
}

void Library::addAuthor(string name, string lastName)
{
	Author* author = new Author(name, lastName);

	this->addAuthor(author);
}

void Library::addBook(Book *book)
{
	this->listBooks.push_back(book);
}

void Library::addBook(string title, Author *author, string type, string language, int year)
{
	Book *book = new Book(title, author, type, language, year);

	this->addBook(book);
}

void Library::addReader(string name, string lastName, string adress)
{
	Reader *reader = new Reader(name, lastName, adress);

	this->listReaders.push_back(reader);
}

void Library::printAuthors()
{
	for(int i = 0; i < this->listAuthors.size(); i++)
	{
		cout << i+1 << " " << this->listAuthors[i]->getFullName() << endl;
	}
}

void Library::printBooks()
{
	for (int i = 0; i < this->listBooks.size() ; i++)
	{
		cout << i + 1 << " " << this->listBooks[i]->getFullName()<< endl;
	}
}

void Library::printReaders()
{
	for (int i = 0; i < this->listReaders.size(); i++)
	{
		cout << i + 1 << " " << this->listReaders[i]->getFullName() << endl;
	}
}

int Library::chooseAuthor()
{
	cout << "\nWybierz autora\n" << endl;
	this->printAuthors();

	int author = 0;

	cin >> author;

	return author - 1;
}

int Library::chooseBook()
{
	cout << "\nWybierz ksiazke\n" << endl;
	this->printBooks();

	int book = 0;

	cin >> book;

	return book - 1;
}

int Library::chooseReader()
{
	cout << "\nWybierz czytelnika\n" << endl;
	this->printReaders();

	int readers = 0;

	cin >> readers;

	return readers - 1;
}


Library::~Library()
{
}
