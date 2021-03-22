#include <iostream>
#include <vector>
#include<math.h>

using namespace std;
int n[10000];

int isPrime(int n) {
	if (n <= 1)
		return 0; //1은 소수가 아님.

	// 짝수는 소수에서 제외
	// 단, 2는 유일하게 짝수 중에서 소수
	if (n % 2 == 0)
		return n == 2 ? 1 : 0;

	// n이 홀수인 경우 sqrt(n)까지 나눠서 나눠떨어지는지 여부 체크
	for (int i = 3; i <= sqrt(n); i += 2) {
		// 나눠 떨어진다면 약수에 해당하므로 소수가 아님.
		if (n % i == 0)
			return 0;
	}
	// 위에서 걸러지지 않은 나머지 경우는 소수에 해당됨
	return 1;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n[i];
	}

	
	for (int i = 0; i < t; i++) {
		int a, b;
		a = b = n[i] / 2;
		
		while (a != 0) {
			if (isPrime(a)==1 && isPrime(b)==1) {
				cout << a << " " << b << endl;
				break;
			}
			else {
				a--; b++;
				continue;
			}
		}
	}
	
	return 0;
	
	

}