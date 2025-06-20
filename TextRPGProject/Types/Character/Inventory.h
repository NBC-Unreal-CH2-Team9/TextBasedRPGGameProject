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
	Item* Get(unsigned int index);

	// Get all items
	std::vector<Item*> GetItems() {
		return items;
	}
	
	// Get item count
	size_t Count() {
		return items.size();
	}

private:
	std::vector<Item*> items;
};
