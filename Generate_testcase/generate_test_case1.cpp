//#include <iostream>
//#include <cstdio>
//#include <queue>
//#include <ctime>
//#include <algorithm>
//#include "GeneralTree.h"
//
//using namespace std;
//
//int main() {
//
//
//	//// �׽�Ʈ ���̽� ���� �κ� (���� �׽�Ʈ ���̽��� ���� �ƿ�ǲ�� �����ϴ� �κ��� �ּ�ó�� �ؾߵ�)
//	//freopen("input.txt", "w", stdout);
//	//srand((unsigned)time(NULL));
//
//	//int N = rand() % 20 + 1;
//	//int M = rand() % N + 1;
//
//	//cout << N << " " << M << endl;
//
//	//queue<int> q;
//	//for (int i = 2; i <= N; i++) {
//	//	q.push(i);
//	//}
//
//	//int isPut;
//	//for (int i = 1; i <= N; i++) {
//	//	cout << i << " ";
//	//	if (i == 1) {
//	//		cout << q.front() << " ";
//	//		q.pop();
//	//	}
//	//	for (int n = 0; n < 5; n++) {
//	//		isPut = rand() % 2;
//	//		if (isPut && !q.empty()) {
//	//			cout << q.front() << " ";
//	//			q.pop();
//	//		}
//	//	}
//	//	
//	//	if (i == N && q.size() != 0) {
//	//		for (int j = 0; j < q.size(); j++) {
//	//			cout << q.front() << " ";
//	//			q.pop();
//	//		}
//	//	}
//	//	cout << "0" << endl;
//	//	
//	//}
//
//	//bool used[30] = {};
//	//int question = 0;
//	//int query;
//	//while (question < M) {
//	//	query = rand() % N + 1;
//	//	if (!used[query]) {
//	//		cout << query << endl;
//	//		used[query] = true;
//	//		question++;
//	//	}
//	//}
//	//return 0;
//	//// �׽�Ʈ ���̽� ���� �κ� end
//
//
//	// ������ �׽�Ʈ ���̽��� �ƿ�ǲ�� �����ϴ� �κ�(���� �׽�Ʈ ���̽� ���� �κ��� �ּ�ó�� �ؾߵ�)
//	freopen("input-1-3.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//
//	int N, M;
//
//	cin >> N >> M;
//	
//	GeneralTree<int> T(1);
//
//	int parent, child;
//	for(int i = 0; i < N; i++){
//		cin >> parent;
//		for (int j = 0; j < 5; j++) {
//			cin >> child;
//			if (child == 0) break;
//			else {
//				T.insertNode(parent, child);
//			}
//		}
//	}
//
//	int query;
//	for (int i = 0; i < M; i++) {
//		cin >> query;
//		T.printChild(query);
//	}
//
//	return 0;
//}