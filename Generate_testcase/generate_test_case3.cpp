//#include <iostream>
//#include "GeneralTree.h"
//using namespace std;
//
//int main() {
//	freopen("input-2-3.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	
//	int n, m;
//	cin >> n >> m;
//		
//	GeneralTree<int> T(1);
//	
//	int parent, child;
//	for(int i = 0; i < n; i++){
//		cin >> parent;
//		for (int j = 0; j < 10; j++) {
//			cin >> child;
//			if (child == 0) break;
//			else {
//				T.insertNode(parent, child);
//			}
//		}
//	}
//	
//	int query;
//	int answer;
//	for (int i = 0; i < m; i++) {
//		cin >> query;
//		answer = T.countdepth(query);
//		cout << answer << endl;
//	}
//
//	return 0;
//}