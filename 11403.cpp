#include <iostream>
#include <vector>

using namespace std;

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();

	int n;
	cin >> n;
	
	vector<vector<int>> arr;
	for (int i = 0; i < n; i++)
	{
		vector<int> element(n);
		arr.push_back(element);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			arr[i][j] = a;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][k] == 1 && arr[k][j] == 1)
					arr[i][j] = 1;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j]<<" ";
		}
		cout << endl;
	}
}