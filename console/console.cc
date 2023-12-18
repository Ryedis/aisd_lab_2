#include <linkedlist/linkedlist.h>
#include <iostream>

using namespace linkedlist;
using namespace std;

int main() {
	LinkedList<int> list(5);

	HanoiTowerSolver<int> Tower(list);
	Tower.printTowerA();
	Tower.solve();
	cout <<"Steps: " << Tower.getNumMoves() << endl;
	Tower.printTowerA();
	Tower.printTowerB();
	Tower.printTowerC();
	
	return 0;
}

