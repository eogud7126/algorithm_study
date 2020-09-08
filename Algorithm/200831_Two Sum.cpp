#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<functional>
#include<sstream>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")

using namespace std;


vector<int> solution(vector<int>& nums, int target) {
	vector<int> answer;
	for (int i=0;i<nums.size(); i++) {
		for (int j = i + 1;j < nums.size();j++) {
			if (nums[i] + nums[j] == target) {
				answer.push_back(i);
				answer.push_back(j);
			}
		}
	}
	return answer;
}

vector<int> nums = { 2,7,11,15 };
int target = 9;

int main() {
	cout << solution(nums, target)[0];
	cout << solution(nums, target)[1];
	
	return 0;
}