#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int t, n;
//int startx, starty;
//int endx, endy;
vector<pair<int, int>> cs;

bool BFS(int x, int y) {
	
	// (x,y) ť ����
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));

	//�湮 ���� üũ
	vector<bool> visited;
	visited = vector<bool>(n + 2, false);
	//�ʱ� �湮 üũ
	visited[0] = true;


	while (!q.empty()) {
		int point_x = q.front().first;
		int point_y = q.front().second;
		q.pop();

		for (int i = 1; i < n + 2; ++i) {
			int next_x = cs[i].first;
			int next_y = cs[i].second;

			if (visited[i] == false && ((next_x - point_x) + (next_y - point_y)) <= 1000) {
				q.push(make_pair(cs[i].first, cs[i].second));
				visited[i] = true;
				//true�� �ٽ� �� �ʿ䰡 �����ϱ�
			}
		}
	}
	return visited[n + 1];
}

int main(void) {
	cin >> t;

	while (t--) {
		cin >> n;
		cs.clear();
		
//		cin >> startx >> starty;
//		cs.push_back(make_pair(startx, starty));
		
		for (int i = 0; i < n+2; i++) {
			int x, y;
			cin >> x >> y;
			cs.push_back(make_pair(x, y));
		}

//		cin >> endx >> endy;
//		cs.push_back(make_pair(endx, endy));

//		bool result = BFS(startx, starty);
		bool result = BFS(cs[0].first, cs[0].second);
		
		if (result == true) {
			cout << "happy" << endl;
		}
		else {
			cout << "sad" << endl;
		}
	}
	//return 0;
}

