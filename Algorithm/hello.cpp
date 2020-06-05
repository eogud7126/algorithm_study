//#include<iostream>
//
//using namespace std;
//
//int main() {
//	cout << "hello world";
//	return 0;
//}
//void quickSort(int arr[], int size) { 
//	int pivot = arr[0] 
//	int cursor = 0; 
//	for (int i = 1; i < size; i++) {
//		if (pivot > arr[i]) {
//			cursor++; swap(arr[cursor], arr[i]); 
//		}
//	} 
//	swap(arr[0], arr[cursor]);
//	if (cursor > 0) {
//		quickSort(arr, cursor);
//	}
//	if (cursor + 1 < size - 1) {
//		quickSort(arr + cursor + 1, size - cursor - 1); 
//	}
//}
//
//void bubbleSort(int arr[], int size) {
//	bool isSwap;
//	do { 
//		isSwap = false; 
//		for (int i = 1; i < size; i++) { 
//			if (arr[i - 1] > arr[i]) { 
//				swap(arr[i - 1], arr[i]); 
//				isSwap = true; } 
//		} 
//	} while (isSwap); 
//}
//
//void selectionSort(int arr[], int size) { 
//	for (int i = 0; i < size - 1; i++) {
//		for (int j = i + 1; j < size; j++) { 
//			if (arr[i] > arr[j]) {
//				swap(arr[i], arr[j]); 
//			} 
//		} 
//	} 
//}
//
//
//void insertionSort(int arr[], int size) {
//	for (int i = 0; i < size - 1; i++) { 
//		for (int j = i + 1; j >= 0; j--) { 
//			if (arr[j - 1] > arr[j]) { 
//				swap(arr[j - 1], arr[j]); 
//			} 
//			else { 
//				continue; 
//			} 
//		} 
//	} 
//}
//
//void mergeSort(int arr[], int size) {
//	if (size > 2) {
//		mergeSort(arr, size / 2);
//		mergeSort(arr + size / 2, size - size / 2); 
//		int leftCursor = 0; 
//		int rightCursor = size / 2; 
//		int buff[50]; 
//		int buffCursor = 0;
//		while (leftCursor < size / 2 && rightCursor < size) {
//			if (arr[leftCursor] < arr[rightCursor]) { 
//				buff[buffCursor++] = arr[leftCursor++]; 
//			}
//			else { 
//				buff[buffCursor++] = arr[rightCursor++]; 
//			} 
//		} 
//		for (int i = leftCursor; i < size / 2; i++) {
//			buff[buffCursor++] = arr[i];
//		} 
//		for (int j = rightCursor; j < size; j++) { 
//			buff[buffCursor++] = arr[j]; 
//		} 
//		memcpy(arr, buff, size * sizeof(int)); 
//	} 
//	else { 
//		if (arr[0] > arr[1]) { 
//			swap(arr[0], arr[1]); 
//		} 
//	} 
//}



#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<string>
#include<algorithm>
using namespace std;

vector<int> a = { 9,4,1,23,5,2,2,34,2,1,2,3,1,5,45,6,457,5,8,6,96,6,3 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sort(a.begin(), a.end());
	for (int i = 0;i < a.size();i++)
		cout<< a[i] << " ";
	unique(a.begin(), a.end()-2);
	//a.erase(a.begin()+4,a.end());
	cout << endl;
	for (int i = 0;i < a.size();i++)
		cout << a[i] << " ";
	cout << endl;
	bool n = binary_search(a.begin(), a.end(), 4);
	cout << n << endl;
}
