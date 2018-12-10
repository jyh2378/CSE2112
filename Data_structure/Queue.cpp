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
class Queue {
private:
	Node<T>* Front;
	Node<T>* Back;
	int queue_size = 0;
public:
	Queue() {
		Front = NULL;
		Back = NULL;
	}
	~Queue() {
	}
	int size() {
		return queue_size;
	}
	bool isEmpty() {
		return queue_size == 0;
	}
	T front() {
		if (Front == NULL) {
			return NULL;
		}
		else {
			return Front->getData();
		}
	}
	T back() {
		if (Back == NULL) {
			return NULL;
		}
		else {
			return Back->getData();
		}
	}
	void enQueue(T data) {
		Node<T>* newnode = new Node<T>(data);
		if (Front == NULL) {
			Front = newnode;
			Back = Front;
		}
		else {
			Back->setNext(newnode);
			Back = newnode;
		}
		queue_size++;
	}
	T deQueue() {
		Node<T>* temp;
		T data;
		if (Front == NULL) {
			return NULL;
		}
		else {
			data = Front->getData();
			temp = Front;
			Front = Front->getNext();
			delete temp;
			queue_size--;
			return data;
		}
	}
};
