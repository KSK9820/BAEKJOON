#include <iostream>
#include <vector>
#include<math.h>

using namespace std;
int n[10000];

int isPrime(int n) {
	if (n <= 1)
		return 0; //1�� �Ҽ��� �ƴ�.

	// ¦���� �Ҽ����� ����
	// ��, 2�� �����ϰ� ¦�� �߿��� �Ҽ�
	if (n % 2 == 0)
		return n == 2 ? 1 : 0;

	// n�� Ȧ���� ��� sqrt(n)���� ������ �������������� ���� üũ
	for (int i = 3; i <= sqrt(n); i += 2) {
		// ���� �������ٸ� ����� �ش��ϹǷ� �Ҽ��� �ƴ�.
		if (n % i == 0)
			return 0;
	}
	// ������ �ɷ����� ���� ������ ���� �Ҽ��� �ش��
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