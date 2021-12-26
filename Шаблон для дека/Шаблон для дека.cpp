#include <iostream>
#include "MyDeque.h"

using namespace std;

int main()
{
	MyDeque <int> intDeque;
	intDeque.pushBack(12);
	intDeque.pushBack(-4);
	intDeque.popFront();
	intDeque.pushBack(888);
	intDeque.pushFront(14);
	intDeque.printFrontToBack();
	cout << endl;

	MyDeque <double> doubleDeque;
	doubleDeque.pushBack(3.2);
	doubleDeque.pushBack(-3.9);
	doubleDeque.pushBack(0.1);
	doubleDeque.pushFront(7.5);
	doubleDeque.printBackToFront();
	cout << endl;

	MyDeque <const char*> de;
	de.pushBack("dom");
	de.pushBack("kot");
	de.pushBack("les");
	de.pushFront("derevo");

	MyDeque <const char*> de1;
	de1.pushBack("dom1");
	de1.pushBack("kot1");
	de1.pushBack("les1");
	de1.pushFront("derevo1");
	de = de1;
	de.printFrontToBack();
	cout << endl;
	de.popBack();
	de.printBackToFront();

	return 0;
}