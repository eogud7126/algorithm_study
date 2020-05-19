#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<functional>
#include<sstream>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")

using namespace std;

struct Node {
	int x;
	int y;
	int num;
	Node* left;
	Node* right;
};

vector<Node*> nodes;
vector<vector<int>> answer(2);

bool cmp(Node* u, Node* v) {
	if (u->y < v->y) return false;
	else if (u->y == v->y) {
		if (u->x < v->x) return true;
		else return false;
	}
	else return true;
}

void addChild(Node* N1, Node* N2) {
	if (N1->x > N2->x) {
		if (N1->left == NULL) {
			N1->left = N2;
		}
		else {
			addChild(N1->left, N2);
		}
	}
	if (N1->x < N2->x) {
		if (N1->right == NULL) {
			N1->right = N2;
		}
		else {
			addChild(N1->right, N2);
		}
	}
}
void preOrder(Node* N) {
	if (N == NULL) return;
	answer[0].push_back(N->num);
	preOrder(N->left);
	preOrder(N->right);
}

void postOrder(Node* N) {
	if (N == NULL) return;
	postOrder(N->left);
	postOrder(N->right);
	answer[1].push_back(N->num);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	
	for (int i = 0;i < nodeinfo.size();i++) {
		Node* N = (Node*)malloc(sizeof(*N));
		N->x = nodeinfo[i][0];
		N->y = nodeinfo[i][1];
		N->num = i+1 ;
		N->left = NULL;
		N->right = NULL;
		nodes.push_back(N);
	}
	for (int i = 0;i < nodes.size();i++) {
		cout << nodes[i]->num << endl;
	}
	sort(nodes.begin(), nodes.end(),cmp);

	for (int i = 1;i < nodes.size();i++) {
		addChild(nodes[0], nodes[i]);
	}

	preOrder(nodes[0]);
	postOrder(nodes[0]);
	return answer;
}

int main() {

	vector<vector<int>> nodeinfo = { {5,3},{11,5}, {13, 3},{3, 5},{6, 1},{1, 3},{8, 6},{7, 2},{2, 2} };
	solution(nodeinfo);
	for (int i = 0;i < 2;i++) {
		for (int j = 0;j < answer[i].size();j++) {
			cout << answer[i][j];
		}
		cout << endl;
	}
	//cout << solution(nodeinfo) << endl;

	return 0;
}