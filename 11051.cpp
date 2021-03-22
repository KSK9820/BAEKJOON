#include <iostream>
using namespace std;

long comb[1001][1001];

int main()
{
	int n, k;
	cin >> n >> k;
	comb[0][0] = 1; comb[1][0] = 1; comb[1][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) comb[i][j] = 1;
			else if (j == i) comb[i][j] = 1;
			else comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 10007;
		}
	}
	
	cout << comb[n][k];
	return 0;
}