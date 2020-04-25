#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


string ReplaceAll(string& str, const string &from, const string& to) {
	size_t start_pos = 0; //stringó������ �˻�
	while ((start_pos = str.find(from, start_pos)) != std::string::npos)  //from�� ã�� �� ���� ������
	{
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // �ߺ��˻縦 ���ϰ� from.length() > to.length()�� ��츦 ���ؼ�
	}
	return str;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string input_str;
	cin >> input_str;
	string sample[8] = { "dz=","c=","c-","d-","lj","nj","s=","z=" };
	for (int i = 0;i < 9;i++) {
		ReplaceAll(input_str, sample[i], "1");
	}
	cout << input_str.length()<<endl;
	return 0;
}
