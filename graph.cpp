#include <iostream>
#include "Graph.h"

using namespace std;

int main() {

	Graph g(9);
	g.addEdge(0,1);
	g.addEdge(0,3);
	g.addEdge(0,8);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(3,4);
	g.addEdge(5,6);
	g.addEdge(4,7);
	g.displayMatr();
	g.DFS(3);
	cout << endl;
	Graph g1(6);
	g1.addEdge(0,1);
	g1.addEdge(0,3);
	g1.addEdge(1,2);
	g1.addEdge(2,3);
	g1.addEdge(3,4);
	g1.addEdge(2,5);
	g1.BFS(0);
	cout<< endl;
	return 0;
}