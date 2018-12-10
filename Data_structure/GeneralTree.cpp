#include <iostream>
#include <vector>

template <typename T>
class GeneralTree;

template <typename T>
class Node {
private:
	T data;
	Node* par;	// parent node
	std::vector<Node*> chi;	// children node list
public:
	Node() {
		this->data = NULL;
		this->par = NULL;
	}
	Node(T data) {
		this->data = data;
		this->par = NULL;
	}
	~Node() {
	}
	void setParent(Node* par) { // set parent node
		this->par = par;
		return;
	}
	void insertChild(Node* chi) {	// add child node to this node
		this->chi.push_back(chi);
		return;
	}
	void delChild(Node* chi) {	// delete child node of this node
		for (int i = 0; i < this->chi.size(); i++) {
			if (this->chi[i] == chi) {
				this->chi.erase(this->chi.begin() + i);
			}
		}
		return;
	}
	friend GeneralTree<T>;
};

template <typename T>
class GeneralTree {
private:
	Node<T>* root;
	std::vector<Node<T>*> node_list; // list saving all node pointer in Tree
public:
	GeneralTree() {
		root = NULL;
	}
	GeneralTree(T data) {
		root = new Node<T>(data);
		node_list.push_back(root);
	}
	~GeneralTree() {
	}
	void setRoot(T data) {
		root = new Node<T>(data);
		node_list.push_back(root);
	}
	Node<T>* getRoot() {
		return root;
	}
	void insertNode(T parent_data, T data) { // insert child node to node having parent_data
		Node<T>* par;
		if (root == NULL) {
			std::cout << "Tree is null" << std::endl;
			return;	// if root is null, exit
		}
		for (auto &i : this->node_list) {
			if (i->data == parent_data) {
				par = i;
				Node<T>* newnode = new Node<T>(data);
				par->insertChild(newnode);
				newnode->setParent(par);
				node_list.push_back(newnode);
				return;
			}
		}
		return;
	}
	void delNode(T data) { // delete node
		Node<T>* nownode;
		Node<T>* par;
		for (int i = 0; i < this->node_list.size(); i++) {
			if (this->node_list[i]->data == data) {
				nownode = node_list[i];
				if (nownode == root) { // if delete node when tree have another node except root, print error
					std::cout << "Root that has children can't be deleted" << std::endl;
					return;
				}
				par = nownode->par;
				for (auto &child : nownode->chi) {
					par->insertChild(child);
					child->setParent(par);
				}
				par->delChild(nownode);
				this->node_list.erase(this->node_list.begin() + i);
				delete nownode;
			}
		}
		return;
	}
	void printChild(T data) { // print all children of this node
		for (auto &i : this->node_list) {
			if (i->data == data) {
				if (i->chi.size() == 0) std::cout << "0";
				for (auto &child : i->chi) {
					std::cout << child->data << " ";
				}
				std::cout << std::endl;
				return;
			}
		}
		std::cout << "Node can't be found" << std::endl;
		return;
	}
	int countdepth(T data) { // print depth of this node
		Node<T>* nownode;
		int depth = 0;
		for (auto &i : this->node_list) {
			if (i->data == data) {
				nownode = i;
				while (true) {
					if (nownode == root) return depth;
					nownode = nownode->par;
					depth++;
				}
			}
		}
		return NULL;
	}
	void preorder(Node<T>* node) { // preorder
		std::cout << node->data << " ";
		for (auto &v : node->chi) {
			preorder(v);
		}
		return;
	}
	void postorder(Node<T>* node) { // postorder
		for (auto &v : node->chi) {
			postorder(v);
		}
		std::cout << node->data << " ";
		return;
	}
};