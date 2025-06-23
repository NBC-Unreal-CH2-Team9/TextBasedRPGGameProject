#pragma once

#include <vector>

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

	void Clear() {
		items.clear();
	}

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
