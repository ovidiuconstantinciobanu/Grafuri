#include <iostream>
#include "Tree.h"

using namespace std;

int main(){
	bTree t;
	t.insert(11);
	t.insert(1);
	t.insert(6);
	t.insert(-1);
	t.insert(-10);
	t.insert(100);
	t.print();
	cout<<endl;
	t.order();
	t.search(7);
	return 0;
}
