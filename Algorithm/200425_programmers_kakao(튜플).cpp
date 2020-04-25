#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>

#include<map>

using namespace std;
//��¥ �����ѹ���� �� �迭�� �ε��� ó��..
//�� �밡��

string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";

vector<int> solution(string s) {
	vector<int> answer;
	vector<pair<int, vector<int>>> part_size;	//�κ�����, ����
	vector<int> part_list[501];
	int idx = 0;
	string sample = "";
	for (int i = 1;i < s.size() - 1;i++) {
		//���ڿ��� ������ ���� ���� ���� ���ڵ��� part_list �� �ֱ� ����
		if (s[i] == '{' || s[i] == '}' || s[i] == ',') {
			if (s[i] == '}') {
				//���� part_list �ε����� �Ѿ��
				part_size.push_back(make_pair(part_list[idx].size(), part_list[idx]));
				idx++;
				
			}
			continue;
		}
		else {
			//���ڸ� �̻��ϼ��� ������ sample�� �����ߴٰ�
			sample += s[i];
			//part_list�� ����
			if (s[i + 1] == '}' || s[i + 1] == ',') {
				part_list[idx].push_back(stoi(sample));
				sample = "";
			}
		}
	}

	sort(part_size.begin(), part_size.end());
	//���� �� ����� Ȯ���ϴ� ����
	/*for (int i = 0;i < part_size.size();i++) {
		cout << part_size[i].first << endl;
	}*/
	//key: �켱���� value: ����
	map<int, int> for_seq;
	//map�� ���� �� ������ key���� ���� �ڵ����� �Ǳ� ������ vector<pair>�� �ϳ� �������
	vector<pair<int, int>> tmpvc;//first:�켱���� second:��
	for (int i = 0;i < part_size.size();i++) {
		for (int j = 0;j < part_size[i].second.size();j++) {
			//cout<< part_size[i].second.size()<<" part_size[i].second[j](key):"<< part_size[i].second[j] <<" i: "<<i<<" " << for_seq[part_size[i].second[j]] << endl;
			if (for_seq[part_size[i].second[j]] == 0) {//ó�� ���ϴ� Ű�ϰ��
				//key�� part_size[i].second[j]. ��, i��° �κ������� j��° ����.
				for_seq[part_size[i].second[j]] = part_size[i].second.size(); //ũ�� 1234-> = �켱����
				tmpvc.push_back(make_pair(part_size[i].second.size(), part_size[i].second[j]));
			}
		}
	}
	//���ҿ켱������� ����
	sort(tmpvc.begin(), tmpvc.end());
	//ũ�Ⱑ ���� ū �κ����ո�ŭ for�� ������ map Ű ������ answer�� ����. map�� �ڵ�����.
	for (int i = 0;i < tmpvc.size() ;i++) {
		answer.push_back(tmpvc[i].second);
		//cout << tmpvc[i].first<<" "<<tmpvc[i].second << endl;
	}
	return answer;
}
int main(void) {
	solution(s);
	return 0;
}



