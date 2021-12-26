#pragma once

#include <iostream>
#include "DequeItem.h"

using namespace std;

template <typename T>
class MyDeque
{
private:
	DequeItem<T>* HEAD;
	DequeItem<T>* TAIL;
	int size;

	DequeItem<T>* CreateNode(T _value)
	{
		DequeItem<T>* newItem = new DequeItem<T>(_value);
		size++;
		newItem->setNextItem(NULL);
		newItem->setPrevItem(NULL);
		return newItem;
	}

	void clearDeque()
	{
		DequeItem<T>* cursor = HEAD;
		DequeItem<T>* temp;
		while (cursor != NULL)
		{
			temp = cursor;
			cursor = cursor->getNextItem();
			delete temp;
		}
		HEAD = TAIL = NULL;
		size = 0;
	}
public:
	MyDeque()
	{
		HEAD = NULL;
		TAIL = NULL;
		size = 0;
	}
	MyDeque(const MyDeque<T>& obj)
	{
		clearDeque();
		DequeItem<T>* cursor = obj.HEAD;
		while (cursor != NULL)
		{
			pushBack(cursor->getValue());
			cursor = cursor->getNextItem();
		}
	}

	MyDeque<T>& operator = (const MyDeque<T>& _deque)
	{
		// Проверка на самоприсваивание
		if (this == &_deque)
			return *this;
		clearDeque();
		DequeItem<T>* cursor = _deque.HEAD;
		while (cursor != NULL)
		{
			pushBack(cursor->getValue());
			cursor = cursor->getNextItem();
		}
		return *this; // возвращает объект, который сгенерировал вызов
	}

	void pushBack(T _value)
	{
		if (HEAD == NULL)
			HEAD = TAIL = CreateNode(_value);
		else
		{
			TAIL->setNextItem(CreateNode(_value));
			TAIL->getNextItem()->setPrevItem(TAIL);
			TAIL = TAIL->getNextItem();
		}
	}

	void pushFront(T _value)
	{
		if (HEAD == NULL)
			HEAD = TAIL = CreateNode(_value);
		else
		{
			HEAD->setPrevItem(CreateNode(_value));
			HEAD->getPrevItem()->setNextItem(HEAD);
			HEAD = HEAD->getPrevItem();
		}
	}

	DequeItem<T>* popBack()
	{
		DequeItem<T>* tempItem = TAIL;
		TAIL = TAIL->getPrevItem();
		TAIL->setNextItem(NULL);
		size--;
		return tempItem;
	}

	DequeItem<T>* popFront()
	{
		DequeItem<T>* tempItem = HEAD;
		HEAD = HEAD->getNextItem();
		HEAD->setPrevItem(NULL);
		size--;
		return tempItem;
	}

	int getSize() const
	{
		return size; 
	}

	void printFrontToBack()
	{
		DequeItem<T>* cursor = HEAD;
		while (cursor != NULL)
		{
			cout << cursor->getValue() << endl;
			cursor = cursor->getNextItem();
		}
	}

	void printBackToFront()
	{
		DequeItem<T>* cursor = TAIL;
		while (cursor != NULL) {
			cout << cursor->getValue() << endl;
			cursor = cursor->getPrevItem();
		}
	}

	~MyDeque()
	{
		clearDeque();
	}
};