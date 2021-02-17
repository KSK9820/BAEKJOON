#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	
	int n;
	cin >> n;
	
	vector<vector<int>>arr(n, vector<int>(n,n+1));

	int a = 0, b = 0;
	while (1) {
		cin >> a >> b;
		if (a == -1) break;
		arr[a-1][b-1] = 1;
		arr[b-1][a-1] = 1;
	}
	
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				arr[i][i] = 0;
			}
		}
	}

	vector<int> score(n,0);
	
	for (int i = 0; i < n; i++) {
		score[i] = *max_element(arr[i].begin(), arr[i].end());
	}

	int min = *min_element(score.begin(), score.end());
	
	vector <int> print;

	for (int i = 0; i < n; i++) {
		if (score[i] == min) {
			print.push_back(i + 1);
		}
	}
	
	cout << min << " " << print.size() << endl;
	for (int i = 0; i < print.size(); i++) {
		cout << print[i] << " ";
	}

	return 0;
}