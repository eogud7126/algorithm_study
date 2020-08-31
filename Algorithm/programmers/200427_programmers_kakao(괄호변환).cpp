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

//u,v 분리 함수
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
//u 완벽한 괄호 판단 함수
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
	//1단계
	if (p == "") return "";
	//2단계
	uv = make_uv(p);

	/*cout << "u:" << uv.first << endl;
	cout << "v:" << uv.second << endl;
	cout << "tmp:" << tmp<< endl;
	cout << "=======================" << endl;*/

	//3단계
	if (checkIsPerfect(uv.first)) {
		string tmpanswer = uv.first; //uv.first를 변수에 저장시켜놓는다(recur 하면 값 사라지므로)
		//3-1단계
		tmpanswer += recur(uv.second);		
		return tmpanswer;
	}
	//4단계
	else {
		//4-1
		tmp += "(";
		string tmpu = uv.first;	//uv.first를 변수에 저장시켜놓는다(recur 하면 값 사라지므로) 이거때매 애먹음
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



