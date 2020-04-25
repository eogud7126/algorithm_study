#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;

string getbinary(int k, int n) {
	string binar = "";
	while (k != 0) {
		binar.append(to_string(k % 2));
		k /= 2;
	}
	int strsize = binar.size();
	while (strsize < n) {
		binar.append("0");
		strsize++;
	}
	reverse(binar.begin(), binar.end());
	return binar;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	vector<string> decodeArr1;
	vector<string> decodeArr2;
	//암호 해독
	for (int i = 0;i < arr1.size();i++) {
		decodeArr1.push_back(getbinary(arr1[i],n));
		decodeArr2.push_back(getbinary(arr2[i],n));
		string eachline = "";
		for (int j = 0;j < decodeArr1[i].size();j++) {
			//벽
			if (decodeArr1[i][j] == '1' || decodeArr2[i][j] == '1') {
				eachline.append("#");
			}
			else eachline.append(" ");
		}
		answer.push_back(eachline);
	}
	
	return answer;
}


int main(void) {
	//변수
	int n = 5;
	vector<int> arr1 = { 9, 20, 28, 18, 11 };
	vector<int> arr2 = { 30, 1, 21, 17, 28 };
	solution(n,arr1,arr2);

	return 0;
}



