//���ͽ�Ʈ��-�켱����ť
//�ִܰŸ��� ���� ª�� ��带 ���� �ϴ� ���� -> �켱���� ť�� �̿��ϴ� ���

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 1001
#define INF 1e9

vector<pair<int, int>>graph[MAX];
int Route[MAX];
vector<int> printRoute;
int d[MAX];
int n, m, s, e;

void dijkstra() {
	priority_queue<pair<int, int>>pq;	//�Ÿ�, ��� �ε���
	pq.push(make_pair(0,s));
	d[s] = 0;

	while (!pq.empty()) {
		//priority_queue�� ū ���� �տ� ������ �ϴ� max heap
		int dist = -pq.top().first;	//����ġ�� ������ ������ ������
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;
		
		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				Route[graph[now][i].first] = now;
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
				//ť�� ������ �ִ� ������ ���� �������� ���� ���� �α� ���ؼ�
			}
		}
	}
	
	
}

void print() {
	cout << d[e] << endl;

	int tmp = e;
	while (tmp) {
		printRoute.push_back(tmp);
		tmp = Route[tmp];
	}
	cout << printRoute.size() << endl;

	for (int i = printRoute.size() - 1; i >= 0; i--)
		cout << printRoute[i] << " ";

}

int main(void) {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) d[i] = INF;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back(make_pair(b, c));
	}
	cin >> s >> e;

	fill(d, d + MAX, INF);

	dijkstra();

	print();

	return 0;
}