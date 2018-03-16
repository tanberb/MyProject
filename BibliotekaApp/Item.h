#pragma once
#include "Author.h"

using namespace std;

class Author;
class Item
{
protected:
	string title;
	Author* author;
public:
	Item(string, Author*);
	~Item();
};

