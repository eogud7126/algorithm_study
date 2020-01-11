#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int N;
	int cnt_word = 0;
	vector<string> words;
	
	cin >> N;
	for (int i = 0;i < N;i++) {
		string word;
		cin >> word;
		words.push_back(word);
	}
	for (int i = 0;i < N;i++) {
		string alpha = "";
		bool isgroup = true;
		for (int j = 0;j < words[i].size();j++) {
			if (alpha == "") {
				alpha += words[i][j];
			}
			else {
				if (words[i][j - 1] != words[i][j]) {
					//없다면
					if (alpha.find(words[i][j]) == std::string::npos) {
						alpha += words[i][j];
					}
					else {
						isgroup = false;
						break;
					}
				}
			}
		}
		if (isgroup) cnt_word++;
	}
	cout << cnt_word << endl;
	return 0;
}
/*주요 문장
if (alpha.find(words[i][j]) == std::string::npos) {
*/