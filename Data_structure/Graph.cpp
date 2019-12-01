#include <iostream>
#include <vector>
#define NOT_EXPLORED 0
#define DISCOVERY 1
#define BACK 2

using namespace std;

class vertex {
public:
	int data;
	int degree;
	bool visited; // check vertex is visited or not by DFS
	vector<vertex*> adj_list;

	vertex(int data) {
		this->data = data;
		this->degree = 0;
		this->visited = false;
	}
};

class edge {
public:
	vertex* src;
	vertex* dst;
	int data;
	bool edge_stat; // edge status

	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
		this->edge_stat = NOT_EXPLORED;
	}
};

class graph {
private:
	vector<vertex*> vertex_list;
	vector<edge*> edge_list;
	int v_sz;
public:
	graph() {
		this->v_sz = 0;
	}

	vertex* findvertex(int data) {
		vertex* v = NULL;
		for (int i = 0; i < vertex_list.size(); i++) {
			if (vertex_list[i]->data == data) {
				v = vertex_list[i];
				break;
			}
		}
		return v;
	}

	edge* findedge(vertex* src, vertex* dst) {
		edge* e = NULL;
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
			vertex* new_v = new vertex(data);
			vertex_list.push_back(new_v);
		}
	}

	void insert_edge(int src_data, int dst_data) {
		vertex* src = findvertex(src_data);
		vertex* dst = findvertex(dst_data);
		if (findedge(src, dst) == NULL) {
			edge* new_e = new edge(src, dst);	// generate edge 
			edge_list.push_back(new_e);
		}

		src->adj_list.push_back(dst);			// insert vertex to their adj list
		dst->adj_list.push_back(src);
	}

	void dfs(vertex* v) {
		if (v->visited) return;
		v->visited = true;
		for (int i = 0; i < v->adj_list.size(); i++) { // check adjacency list
			vertex* next_v = v->adj_list[i];
			edge* e = findedge(v, next_v);
			if (next_v->visited == false) { // if next vertex isn't visited
				e->edge_stat = DISCOVERY;
				dfs(next_v);
			}
			else { // if next vertex is visited
				e->edge_stat = BACK;
			}
		}
		return;
	}
};
