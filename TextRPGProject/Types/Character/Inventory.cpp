#include "Inventory.h"
#include "../Item/Item.h"

void Inventory::Insert(Item* newItem)
{
	items.push_back(newItem);
}

Item* Inventory::Remove(unsigned int index)
{
	Item* item = items[index];
	for (int n = index; n < items.size() - 1; n++) {
		items[n] = items[n + 1];
	}
	items.pop_back();
	return nullptr;
}

Item* Inventory::operator[](unsigned int index)
{
	return items[index];
}

Item* Inventory::Get(unsigned int index)
{
	return items[index];
}
