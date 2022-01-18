#include <iostream>

using namespace std;

struct Node {
	int key;
};

Node node_pool[100000];
int last_alloc = 0;

int stack[100000];
int stack_size = 0;

void del(Node* node) {
	int idx = node - node_pool;
	stack[stack_size++] = idx;
}

Node* new_Node() {
	if (stack_size > 0)
		return &node_pool[stack[--stack_size]];
	return &node_pool[last_alloc++];
}


int main() {
	Node* node = new Node();
}


