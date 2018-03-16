#include "Item.h"



Item::Item(string title, Author* author)
{
	this->title = title;
	this->author = author;
}


Item::~Item()
{
}
