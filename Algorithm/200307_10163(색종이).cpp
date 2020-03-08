#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int paper[101][101] = { 0, };
int paperwidth[101] = { 0, };
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int papercnt;
	cin >> papercnt;
	int maxwidth = 0, maxheight = 0;
	for (int i = 1;i <= papercnt;i++) {
		int a, b, width, height;
		cin >> a >> b >> width >> height;
		maxwidth = max(maxwidth, a + width);
		maxheight = max(maxheight, b + height);

		for (int x = a;x < a+width;x++) {
			for (int y = b;y < b+height;y++) {
				paper[x][y] = i;
			}
		}
	}
	for (int i = 0;i < maxwidth;i++) {
		for (int j = 0;j < maxheight;j++) {
			cout << paper[i][j] << " ";
			paperwidth[paper[i][j]]++;
		}
		cout << "\n";
	}
	for(int i=1;i<=papercnt;i++)
		cout << paperwidth[i] << endl;
	return 0;
}