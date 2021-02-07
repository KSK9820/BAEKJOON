#include <iostream>
#include <math.h>
using namespace std;

long long int num1, num2;
long long int result;



int binary_search(long long int* arr, long long int left, long long int right) {
	
	while (left != right) {
		if (arr[left] + arr[right] > 0) {
			if (abs(arr[left] + arr[right]) < abs(result)) {
				result = arr[left] + arr[right];
				num1 = arr[left];
				num2 = arr[right];
			}
			right--;
		}
		else if (arr[left] + arr[right] == 0) {
			result = arr[left] + arr[right];
			num1 = arr[left];
			num2 = arr[right];
			return 0;
		}
		else {
			if (abs(arr[left] + arr[right]) < abs(result)) {
				result = arr[left] + arr[right];
				num1 = arr[left];
				num2 = arr[right];
			}
			left++;
		}

	}
	return 0;
	
}

int main(void) {

	int length;
	cin >> length;
	long long int *arr = new long long int[length];
	for (long long int i = 0; i < length; i++) {
		cin >> arr[i];
	}

	result = arr[0] + arr[length - 1];
	num1 = arr[0];
	num2 = arr[length - 1];

	binary_search(arr, 0, length - 1);
	cout << num1 << " " << num2 << endl;

	//배열 메모리 해제
	delete[] arr;



	return 0;
}
