#include <iostream>
#include <vector>
#define NOT_EXPLORED 0
#define DISCOVERY 1
#define BACK 2

using namespace std;

class Vertex {
public:
	int data;
	int degree;
	bool visited; // check vertex is visited or not by DFS
	vector<Vertex*> adj_list;

	Vertex(int data) {
		this->data = data;
		this->degree = 0;
		this->visited = false;
	}
};

class Edge {
public:
	Vertex* src;
	Vertex* dst;
	int data;
	bool edge_stat; // edge status

	Edge(Vertex* src, Vertex* dst) {
		this->src = src;
		this->dst = dst;
		this->edge_stat = NOT_EXPLORED;
	}
};

class Graph {
private:
	vector<Vertex*> vertex_list;
	vector<Edge*> edge_list;
	int v_sz;
public:
	Graph() {
		this->v_sz = 0;
	}

	Vertex* findvertex(int data) {
		Vertex* v = NULL;
		for (int i = 0; i < vertex_list.size(); i++) {
			if (vertex_list[i]->data == data) {
				v = vertex_list[i];
				break;
			}
		}
		return v;
	}

	Edge* findedge(Vertex* src, Vertex* dst) {
		Edge* e = NULL;
		for (int i = 0; i < edge_list.size(); i++) {
			if (edge_list[i]->src == src && edge_list[i]->dst == dst) {
				e = edge_list[i];
				break;
			}
		}
		return e;
	}

	void insert_vertex(int data) {
		if (findvertex(data) == NULL) {
			Vertex* new_v = new Vertex(data);
			vertex_list.push_back(new_v);
		}
	}

	void insert_edge(int src_data, int dst_data) {
		Vertex* src = findvertex(src_data);
		Vertex* dst = findvertex(dst_data);
		if (findedge(src, dst) == NULL) {
			Edge* new_e = new Edge(src, dst);	// generate edge 
			edge_list.push_back(new_e);
		}

		src->adj_list.push_back(dst);			// insert vertex to their adj list
	}

	void dfs(Vertex* v) {
		if (v->visited) return;
		v->visited = true;
		cout << v->data << " ";
		for (int i = 0; i < v->adj_list.size(); i++) { // check adjacency list
			Vertex* next_v = v->adj_list[i];
			Edge* e1 = findedge(v, next_v);
			Edge* e2 = findedge(next_v, v);
			if (next_v->visited == false) { // if next vertex isn't visited
				e1->edge_stat = DISCOVERY;
				e2->edge_stat = DISCOVERY;
				dfs(next_v);
			}
			else { // if next vertex is visited
				e1->edge_stat = BACK;
				e2->edge_stat = BACK;
			}
		}
		return;
	}
};
