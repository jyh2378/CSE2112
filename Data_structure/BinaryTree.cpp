#include <iostream>
#include <vector>

template <typename T>
class BinaryTree;

template <typename T>
class Node {
private:
	T data;
	Node* par;	// parent
	Node* left;	// left node
	Node* right; // right node
public:
	Node() {
	}
	Node(T data) {
		this->data = data;
	}
	~Node() {
	}
	void setParent(Node* par) {
		this->par = par;
		return;
	}
	void setLeft(Node* chi) {
		this->left = chi;
		return;
	}
	void setRight(Node* chi) {
		this->right = chi;
		return;
	}
	Node* getLeft() {
		return this->left;
	}
	Node* getRight() {
		return this->right;
	}
	friend BinaryTree<T>;
};

template <typename T>
class BinaryTree {
private:
	Node<T>* root;
	int tree_size;
	int numNode = 0;
public:
	BinaryTree() {
		root = NULL;
		tree_size = 0;
	}
	BinaryTree(T data) {
		Node<T>* node_new = new Node<T>(data);
		root = node_new;
	}
	~BinaryTree() {
	}
	Node<T>* getRoot() const {
		return root;
	}
	void insertLeft(T par_data, T left_data) {
		Node<T>* par = findNode(root, par_data);
		Node<T>* left = new Node<T>(left_data);
		par->setLeft(left);
		left->setParent(par);
	}
	void insertRight(T par_data, T right_data) {
		Node<T>* par = findNode(root, par_data);
		Node<T>* right = new Node<T>(right_data);
		par->setRight(right);
		right->setParent(par);
	}
	Node<T>* findNode(Node<T>* start, T data) {
		Node<T>* finded = NULL;
		if (start->data == data) {
			return start;
		}
		else {
			if (start->left != NULL) finded = findNode(start->left, data);
			if (finded == NULL && start->right != NULL) finded = findNode(start->right, data);
		}
		return finded;
	}
	void preorder(Node<T>* node) {
		std::cout << node->data;
		if (node->left != NULL) preorder(node->left);
		if (node->right != NULL) preorder(node->right);
	}
	void inorder(Node<T>* node) {
		if (node->left != NULL) inorder(node->left);
		std::cout << node->data;
		if (node->right != NULL) inorder(node->right);
	}
	void postorder(Node<T>* node) {
		if (node->left != NULL) postorder(node->left);
		if (node->right != NULL) postorder(node->right);
		std::cout << node->data;
	}
	int countNode(Node<T>* node) { // count the number of descendant
		if (node->left == NULL && node->right == NULL) return 1;
		int leftcnt, rightcnt;
		if (node->left != NULL) leftcnt = countNode(node->left);
		else leftcnt = 0;
		if (node->right != NULL) rightcnt = countNode(node->right);
		else rightcnt = 0;
		return leftcnt + rightcnt + 1;
	}
	void compareSubtree(T data1, T data2) { // compare two node's the number of descendant node
		Node<T>* node1 = findNode(root, data1);
		Node<T>* node2 = findNode(root, data2);
		int subtree1 = countNode(node1);
		int subtree2 = countNode(node2);

		if (subtree1 > subtree2) std::cout << data1 << std::endl;
		else if (subtree1 < subtree2) std::cout << data2 << std::endl;
		else std::cout << "equal" << std::endl;
		return;
	}
	int countheight(Node<T>* node) { // print height of this node
		if (node->left == NULL && node->right == NULL) return 1;
		int leftheight, rightheight;
		if (node->left != NULL) leftheight = countheight(node->left);
		else leftheight = 0;
		if (node->right != NULL) rightheight = countheight(node->right);
		else rightheight = 0;
		return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
	}

};