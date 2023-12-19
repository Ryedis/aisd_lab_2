#include <linkedlist/linkedlist.h>
#include <iostream>

using namespace linkedlist;
using namespace std;

int main() {
	LinkedList<int> listA(10);
	LinkedList<int> listC;
	
	cout <<"listA: " << listA << endl;
	cout << "listC: " << listC << endl;
	solve(listA, listC);

	cout << "listA: " << listA << endl;
	cout << "listC: " << listC << endl;
	
	return 0;
}

