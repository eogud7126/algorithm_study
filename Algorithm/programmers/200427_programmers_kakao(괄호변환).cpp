#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;

string p = "(()))(";

string u, v, tmp = "";
string setU = "";
pair<string, string> uv;

//u,v �и� �Լ�
pair<string, string> make_uv(string p) {
	int left = 0, right = 0;
	string u = "", v = "";
	for (int i = 0;i < p.size();i++) {
		if (p[i] == '(') left++;
		else right++;
		if (left == right) {
			u = p.substr(0, i + 1);
			v = p.substr(i + 1);
			break;
		}
	}
	return make_pair(u, v);
}
//u �Ϻ��� ��ȣ �Ǵ� �Լ�
bool checkIsPerfect(string u) {
	stack<char> st;
	if(u[0] =='(')
		st.push(u[0]);
	else return false;

	for (int i = 1;i < u.size();i++) {
		if (u[i] == '(')
			st.push(u[i]);
		if (u[i] == ')') {
			if (!st.empty()) {
				st.pop();
			}
			else return false;
		}
	}
	if (!st.empty()) return false;
	return true;
}

string recur(string p) {
	string tmp = "";
	string setU = "";
	//1�ܰ�
	if (p == "") return "";
	//2�ܰ�
	uv = make_uv(p);

	/*cout << "u:" << uv.first << endl;
	cout << "v:" << uv.second << endl;
	cout << "tmp:" << tmp<< endl;
	cout << "=======================" << endl;*/

	//3�ܰ�
	if (checkIsPerfect(uv.first)) {
		string tmpanswer = uv.first; //uv.first�� ������ ������ѳ��´�(recur �ϸ� �� ������Ƿ�)
		//3-1�ܰ�
		tmpanswer += recur(uv.second);		
		return tmpanswer;
	}
	//4�ܰ�
	else {
		//4-1
		tmp += "(";
		string tmpu = uv.first;	//uv.first�� ������ ������ѳ��´�(recur �ϸ� �� ������Ƿ�) �̰Ŷ��� �ָ���
		//4-2
		tmp+=recur(uv.second);
		//4-3
		tmp.append(")");
		//4-4
		for (int i = 1;i < tmpu.size() - 1;i++) {
			setU += tmpu[i];
		}
		
		for (int i = 0;i < setU.size();i++) {
			if (setU[i] == '(') {
				setU[i] = ')';
			}
			else {
				setU[i] = '(';
			}
		}
		tmp.append(setU);
		//cout << tmp << endl;
		//4-5
		return tmp;
	}
}

string solution(string p) {
	if (checkIsPerfect(p))
		return p;
	else
		return recur(p);
}

int main(void) {
	cout << solution(p) << endl;
	return 0;
}



