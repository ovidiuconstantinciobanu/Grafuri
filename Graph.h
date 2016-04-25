//#ifndef GRAPH_H
//#define GRAPH_H

#include <iostream>

using namespace std;

class Graph {
private:
	bool** adjMatr;
	int size;
public: 
	Graph(int size) {
		int i, j;
		this->size = size;
		adjMatr = new bool*[size];
		for (i = 0; i < size; i++){
			adjMatr[i] = new bool[size];
			for (j = 0; j < size; j++);
				adjMatr[i][j] = false;
		}
	}

	~Graph() {
		for (int i = 0; i < this->size; i++)
			delete[] adjMatr[i];
		delete[] adjMatr;
	}

	void addEdge(int i, int j) {
		if (i >= 0 && i < this->size && j > 0 && j < this->size) {
			adjMatr[i][j] = true;
			adjMatr[j][i] = true;
		}
	}
	
	void removeEdge(int i, int j) {
		if (i >= 0 && i < this->size && j > 0 && j < this->size) {
			adjMatr[i][j] = false;
			adjMatr[j][i] = false;
		}
	}

	bool isEdge(int i, int j) {
		if (i >= 0 && i < this->size && j > 0 && j < this->size)
			return adjMatr[i][j];
		else
			return false;
	}

	void BFS(int start) {
		bool *visited = new bool[this->size];
		int i, extracted = 0, added = 0, j, *queue;
		queue = new int[this->size];
		visited[start] = 1;
		queue[added] = start;
		while(extracted <= added) {
			int k = queue[extracted];
			for(j = 0; j < this->size; j++) {
				if(adjMatr[k][j] == 1 && visited[j] == 0) {
					added++;
					queue[added] = j;
					visited[j] = 1;
				}
			}
			extracted++;
		}
		for(i = 0; i < this->size; i++)
			cout<<queue[i]<<" ";
	}

	void DFS(int start) {
		int extracted = 1, k, j;
		bool ok;
		int *stack = new int[this->size];
		bool *visited = new bool[this->size];
		stack[extracted] = start;
		visited[start] = 1;
		cout << stack[extracted]<< " ";
		while (extracted >= 0) {
			k = stack[extracted];
			ok = 0;
			j = 0;
			while (j < this->size && ok == 0)
				if (adjMatr[k][j] == 1 && visited[j] == 0)
					ok = 1;
				else
					j++;
			if (ok == 1) {
				extracted++;
				stack[extracted] = j;
				visited[j] = 1;
				cout << stack[extracted] << " ";
			}
			else
				extracted--;
		}

	}
	void displayMatr(){
		int i,j;
		for (i = 0; i < this->size; i++){
			for (j = 0; j < this->size; j++)
			cout << adjMatr[i][j] << " ";
		cout << endl;
		}
	}
};