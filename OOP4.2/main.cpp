#include <iostream>

using namespace std;

#include "kolos.h"

#define SUCCESS 0
#define FAILURE -1

void assertEquals(int expected, int actual) {
    if (actual != expected) {
        cerr << "Assertion failed. Expected is " << expected << ", actual is "
             << actual << "." << endl;
        exit(FAILURE);
    }
}

int main() {
    Container* container = new ArrayContainer();

    assertEquals(0, container->getSize());
    container->insertAtBeginning(3);
    assertEquals(1, container->getSize());


    container->insertAtBeginning(2);
	container->insertAtBeginning(1);

	container->addAtEnd(4);
	container->addAtEnd(5);

	assertEquals(5, container->getSize());

	for (int i = 0; i < 5; ++i) {
		assertEquals(i + 1, container->getElement(i));
	}


	container->insertAtBeginning(6);

	container->sortAscending();
	for (int i = 0; i < 6; ++i) {
		assertEquals(i + 1, container->getElement(i));
	}

	container->sortDescending();
	for (int i = 0; i < 6; ++i) {
		assertEquals(6 - i, container->getElement(i));
	}



    delete container;

    return SUCCESS;
}