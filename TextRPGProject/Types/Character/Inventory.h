﻿#pragma once

#include <vector>
#include "../Item/Item.h"
#include "../Equipment/Equipment.h"

template<typename T>
class Inventory {
public:
	// Push new item
	void Insert(T* newItem);

	// Pop(Get and Remove) item using index
	T* Remove(unsigned int index);

	// Get item using index
	T* operator[](unsigned int index);
	T* Get(unsigned int index);

	// Get all items
	std::vector<T*> GetItems() {
		return items;
	}
	
	// Get item count
	size_t Count() {
		return items.size();
	}

	void Clear();

private:
	std::vector<T*> items;
};

template<typename T>
void Inventory<T>::Insert(T* newItem)
{
	items.push_back(newItem);
}

template<typename T>
T* Inventory<T>::Remove(unsigned int index)
{
	T* item = items[index];
	for (int n = index; n < items.size() - 1; n++) {
		items[n] = items[n + 1];
	}
	items.pop_back();
	return nullptr;
}

template<typename T>
T* Inventory<T>::operator[](unsigned int index)
{
	return items[index];
}

template<typename T>
T* Inventory<T>::Get(unsigned int index)
{
	return items[index];
}

template<typename T>
inline void Inventory<T>::Clear()
{
	for (int n = 0; n < items.size(); n++) {
		if (items[n] != nullptr) {
			delete items[n];
		}
	}
	items.clear();
}
