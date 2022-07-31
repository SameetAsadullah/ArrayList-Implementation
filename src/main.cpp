#include"ArrayList.h"

int main() {
	ArrayList<int> l1(4);

	l1.insertAtEnd(5);
	l1.insertAtEnd(6);
	l1.insertAtEnd(1);
	l1.insertAtGivenPosition(9, 2);
	l1.printTheList();
	l1.replace(7, 6);

	l1.printTheList();
	l1.sort();
	l1.printTheList();
}