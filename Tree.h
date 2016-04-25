#include <iostream>

using namespace std;

struct node {
	int value;
	node *left;
	node *right;

	node(int value) {
		this->value = value;
	}

	node(int value, node *left, node *right) {
		this->value = value;
		this->left = left;
		this->right = right;
	}
};

class bTree {
private:
	node *root;
public:
	bTree() {
		root=NULL;
	}
	
	~bTree() {
		delete[] root;
	}

	void insertNode(node *root, int value) {
		if(root->value > value) {
			if(!root->left) {
				root->left = new node(value);
			}
			else {	
				insertNode(root->left, value);
			}
		}
		else {
			if (!root->right) {
				root->right = new node(value);
			}
			else {
				insertNode(root->right, value);
			}
		}
	}

	void insert(int value) {
		if (root) {
			this->insertNode(root,value);
		}
		else {
			root = new node(value);
		}
	}

	void printTree(node *root) {
		if(!root) return;
		printTree(root->left);
		cout<<root->value<<' ';
		printTree(root->right);
	}

	void print() {
		printTree(this->root);
	}

	void SRD(node *root) { //inorder
		if(root) {
			SRD(root->left);
			cout<<root->value<<" ";
			SRD(root->right);
		}
	}

	void RSD( node *root) { //preorder
		if(root) {
			cout<<root->value<<" ";
			RSD(root->left);
			RSD(root->right);
		}
	}
	void SDR(node *root) { //postorder
		if(root) {
			SDR(root->left);
			SDR(root->right);
			cout<<root->value<<" ";
		}
	}
	void order() {
		cout<<"RSD"<< endl;
		RSD(this->root);
		cout<<endl<<"SRD"<< endl;
		SRD(this->root);
		cout<<endl<<"SDR"<< endl;
		SDR(this->root);
		cout<< endl;
	}
	void find(node *root, int value) {
		if (!root) {
			return;
		}
		if (value == root->value) {
			cout<< "S-a gasit";
			return;
		}
		else {
			if (value < root->value) {
				find(root->left, value);
			}
			else {
				if ( value > root->value) {
					find(root->right, value);
				}
			}
		}
	}

	void search(int value) {
		find(this->root, value);
	}
};