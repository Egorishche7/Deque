#pragma once

#include <iostream>

using namespace std;

template <typename T>
class DequeItem
{
private:
	T _value;
	DequeItem* next;
	DequeItem* prev;
public:
	DequeItem(T value)
	{
		_value = value;
	}

	T getValue() const
	{
		return _value;
	}

	DequeItem<T>* getNextItem() const
	{
		return next;
	}

	DequeItem<T>* getPrevItem() const
	{
		return prev; 
	}

	void setNextItem(DequeItem<T>* item) 
	{
		next = item; 
	}

	void setPrevItem(DequeItem<T>* item)
	{
		prev = item; 
	}
};