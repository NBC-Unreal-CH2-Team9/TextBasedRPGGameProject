#pragma once

#include <vector>

class Item;

class Inventory {
public:
	// Push new item
	void Insert(Item* newItem);

	// Pop(Get and Remove) item using index
	Item* Remove(unsigned int index);

	// Get item using index
	Item* operator[](unsigned int index);

private:
	std::vector<Item*> items;
};
