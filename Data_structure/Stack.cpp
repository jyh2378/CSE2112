#include <iostream>
template <typename T>
class Node {
private:
	T data;
	Node* prev;
	Node* next;
public:
	Node() {
		this->data = NULL;
	}
	Node(T data) {
		this->data = data;
	}
	~Node() {
	}
	T getData() {
		return data;
	}
	void setData(T data) {
		this.data = data;
		return;
	}
	Node* getPrev() {
		return prev;
	}
	void setPrev(Node* prev) {
		this->prev = prev;
		return;
	}
	Node* getNext() {
		return next;
	}
	void setNext(Node* next) {
		this->next = next;
		return;
	}
};

template <typename T>
class Stack {
private:
	Node<T>* Top;
	int stack_size = 0;

public:
	Stack() {
		Top = NULL;
	}
	~Stack() {
	}
	int size() {
		return stack_size;
	}
	T top() {
		if (Top == NULL) {
			std::cout << "Error: Stack is empty";
			return nullptr;
		}
		else {
			return Top->getData();
		}
	}
	void push(T data) {
		Node<T>* newnode = new Node<T>(data);
		if (Top == NULL) {
			Top = newnode;
		}
		else {
			Top->setNext(newnode);
			newnode->setPrev(Top);
			Top = newnode;
		}
		stack_size++;
	}
	T pop() {
		Node<T>* temp;
		T data;
		if (Top == NULL) {
			std::cout << "Error: Stack is empty";
		}
		else {
			data = Top->getData();
			temp = Top;
			Top = Top->getPrev();
			delete temp;
			stack_size--;
			return data;
		}
	}
};