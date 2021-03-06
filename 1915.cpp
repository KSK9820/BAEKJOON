#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;

	int **arr = new int*[n + 1];
	int **cnt = new int*[n + 1];

	for (int i = 0; i < n + 1; ++i) {
		arr[i] = new int[m+1];
		memset(arr[i], 0, sizeof(int)*(m + 1));
		cnt[i] = new int[m+1];
		memset(cnt[i], 0, sizeof(int)*(m + 1));
	}

	for (int i = 1; i < n + 1; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++) {
			arr[i][j+1] = s[j] - '0';
		}
	}

	int square = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (arr[i][j] == 1) {
				cnt[i][j] = min(arr[i - 1][j - 1], min(arr[i][j - 1], arr[i - 1][j])) + 1;
				if (cnt[i][j] > square)
					square = cnt[i][j];
			}
			
		}
	}


	cout << square * square << endl;

	for (int i = 0; i < n+1; ++i) {
		delete[] arr[i], cnt[i];
	}
	delete[] arr, cnt;

	return 0;
}