#include <iostream>
#include <vector>

class vertex {
private:
	int degree;
	bool visited; // check vertex is visited or not by DFS
public:
	vertex() {
		this->degree = 0;
		this->visited = false;
	}
	void increase_deg() {
		this->degree++;
	}
	void decrease_deg() {
		this->degree--;
	}

	void set_visited() {
		this->visited = true;
	}
	bool get_visited() {
		return this->visited;
	}
};

class edge {
private:
	vertex* src;
	vertex* dst;
	bool explore; // edge is explored?
	bool discovery; // discovery edge list
	bool back; // back edge list
public:
	edge(vertex* src, vertex* dst) {
		this->src = src;
		this->dst = dst;
		this->explore = false;
		this->discovery = false;
		this->back = false;
	}
	bool get_explore() {
		return this->explore;
	}
	void set_explore() {
		this->explore = true;
	}
	bool get_discovery() {
		return this->discovery;
	}
	void set_discovery() {
		this->discovery = true;
	}
	bool get_back() {
		return this->back;
	}
	void set_back() {
		this->back = true;
	}
};

class graph {
private:
	vertex** v;
	edge*** matrix;
	std::vector<edge*> e;
	int v_sz;
	int max_sz;
public:
	graph(int sz) {
		this->max_sz = sz;
		this->v_sz = 0;

		this->v = new vertex*[sz];
		for (int i = 0; i <= sz; i++) v[i] = NULL;

		this->matrix = new edge**[sz];
		for (int i = 0; i <= sz; i++) {
			matrix[i] = new edge*[sz];
			for (int j = 0; j <= sz; j++) matrix[i][j] = NULL;
		}
	}
	void insert_vertex(int n) {
		if (v_sz + 1 > max_sz) return; // if graph is full, exit
		if (v[n] == NULL) {
			vertex* new_v = new vertex();
			v[n] = new_v;
			this->v_sz++;
		}
		else {
			return; // if there is already vertex, exit
		}
	}

	void insert_edge(int src, int dst) {
		if (v[src] == NULL || v[dst] == NULL) return; // if there isn't source or destination, exit
		if (matrix[src][dst] != NULL || matrix[dst][src] != NULL) return; // if there is already edge, exit

		edge* new_e = new edge(v[src], v[dst]);
		matrix[src][dst] = new_e;
		matrix[dst][src] = new_e;

		v[src]->increase_deg();
		v[dst]->increase_deg();

		e.push_back(new_e);
	}

	void dfs(int start) {

		if (v[start]->get_visited()) return;
		v[start]->set_visited();
		for (int i = 0; i < max_sz; i++) { // adjacency matrix - check all rows
			if (matrix[start][i] != NULL) {
				if (v[i]->get_visited() == false) { // if next vertex isn't visited
					matrix[start][i]->set_explore();
					matrix[start][i]->set_discovery();
					dfs(i);
				}
				else { // if next vertex is visited
					if (matrix[start][i]->get_discovery()) continue; // if this edge is discovery, exit
					else {
						matrix[start][i]->set_explore();
						matrix[start][i]->set_back(); // because next vertex is visited, so this edge set to 'back'
					}
				}
			}
		}
	}
};