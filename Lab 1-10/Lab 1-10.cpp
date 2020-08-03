// Lab 1-10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
	//create mylist
	List mylist;
	//push to head 
	mylist.headPush(5);
	mylist.headPush(4);
	mylist.headPush(3);
	//display 
	mylist.display();
	//push tp tail 
	mylist.tailPush(6);
	mylist.tailPush(7);
	//display 
	mylist.display();
	//pop head
	cout << "This integer is pop: " << mylist.headPop() << endl;
	//mylist.headPop();

	mylist.display();
	//pop tail
	cout << "This integer is pop: " << mylist.tailPop() << endl;
	//mylist.tailPop();
	mylist.display();

	//delete element
	mylist.deleteNode(5);
	mylist.display();
	//check is in a list
	if (mylist.isInList(4) == true) {
		cout << "It is in a List" << endl;
	}
	else {
		cout << "It 's not in a List" << endl;
	}


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
