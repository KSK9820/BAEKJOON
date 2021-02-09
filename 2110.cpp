#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int N, C;

	cin >> N;
	cin >> C;

	int *array = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> array[i];
	}

	sort(array, array + N);

	
	int left = 1;
	int right = array[N - 1] - array[0];
	
	int distance = 0;
	while (left <= right) {
		int start = array[0];
		
		int cnt = 1;
		int mid = (left + right) / 2;

		for (int i = 1; i < N; i++) {
			if (array[i] - start >= mid) {
				cnt++;
				start = array[i];
			}
		}

		if (cnt >= C) {
			distance = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << distance;
	
	return 0;
}
