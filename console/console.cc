#include <linkedlist/linkedlist.h>
#include <iostream>

using namespace linkedlist;
using namespace std;

int main() {
	cout << "Lab 2 Tests" << endl << "----------------------" << endl;

	cout << "Linked List Tests" << endl << "----------------------" << endl << endl;
	LinkedList<int> list1(3);
	LinkedList<float> list2(3);
	LinkedList<double> list3(3);
	LinkedList<bool> list4(3);
	cout << "random int list: " << list1 << endl;
	cout << "random float list: " << list2 << endl;
	cout << "random double list: " << list3 << endl;
	cout << "random bool list: " << list4 << endl << "----------------------" << endl << endl;

	LinkedList<int> list5(list1);
	cout << "copy constructor: " << list5 << endl;

	LinkedList<int> list6;
	list6 = list1;
	cout << "equality operator: " << list5 << endl << "----------------------" << endl << endl;

	list1.push_tail(100000000);
	cout << "push_tail: " << list1 << endl;

	list1.pop_tail();
	cout << "pop_tail: " << list1 << endl;

	list1.push_head(100000000);
	cout << "push_head: " << list1 << endl;

	list1.pop_head();
	cout << "pop_head: " << list1 << endl;

	list6.push_tail(list1);
	cout << "push_tail list: " << list6 << endl;

	list6.push_tail(list1);
	cout << "push_tail list: " << list6 << endl;

	list6.push_head(list1);
	cout << "push_head list: " << list6 << endl << "----------------------" << endl << endl;

	LinkedList<bool> list7(10);
	cout << "list7: " << list7 << endl;
	list7.delete_node(true);
	cout << "delete_node in list7 for true: " << list7 << endl;

	cout << "operator [] read: " << list1[0] << endl;
	list1[0] = 100000000;
	cout << "operator [] write: " << list1[0] << endl;

	cout << "list1.size(): " << list1.size() << endl;

	cout << "----------------------" << endl << endl << "Test Hanoi Tower" << endl;
	LinkedList<int> list_A(10);
	LinkedList<int> list_B;
	
	cout <<"list_A: " << list_A << endl << "list_B: " << list_B << endl;
	solve(list_A, list_B);
	cout << "----------------" << endl;
	cout << "list_A: " << list_A << endl << "list_B: " << list_B << endl;
	
	return 0;
}

