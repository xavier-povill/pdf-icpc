/**
 * Author:
 * Date:
 * License:
 * Source:
 * Time: 
 * Description:
 * Status: 
 */
struct Node {
	int val;
	int weight, size;
	Node *left, *right;
	Node(int c) : val(c), weight(rand()), size(1), left(NULL), right(NULL) {}
} *root;

int size(Node *treap) { return treap ? treap->size : 0; }

void split(Node *treap, Node *&left, Node *&right, int val) {
	if (!treap) {
		left = right = NULL;
		return;
	}
	if (size(treap->left) < val) {
		split(treap->right, treap->right, right, val - size(treap->left) - 1);
		left = treap;
	} else {
		split(treap->left, left, treap->left, val);
		right = treap;
	}
	treap->size = 1 + size(treap->left) + size(treap->right);
}

void merge(Node *&treap, Node *left, Node *right) {
	if (left == NULL) {
		treap = right;
		return;
	}
	if (right == NULL) {
		treap = left;
		return;
	}
	if (left->weight < right->weight) {
		merge(left->right, left->right, right);
		treap = left;
	} else {
		merge(right->left, left, right->left);
		treap = right;
	}
	treap->size = 1 + size(treap->left) + size(treap->right);
}

