//다익스트라 - 리스트

#include <iostream>
#include <algorithm>
#define MAX 1001
#define INF 999999999

using namespace std;

int d[MAX];
int graph[MAX][MAX];
bool visited[MAX];

void dijkstra(int n, int s, int e) {

	for (int i = 0; i <= n; i++) {
		d[i] = INF;
	}

	//fill_n(d,n,INF);안되는 이유

	d[s] = 0;

	for (int i = 1; i <= n; i++) {
		int min = INF;
		for (int j = 1; j <= n; j++) {
			if (!visited[j] && min > d[j]) {
				min = d[j];
				s = j;
			}
		}

		visited[s] = true;

		for (int k = 1; k <= n; k++) {
			if (graph[s][k] != INF && d[k] > d[s] + graph[s][k]) {
				d[k] = d[s] + graph[s][k];
			}
		}
	}

	cout << d[e] << endl;

}

void initMap() {
	for (int y = 0; y < MAX; y++) {
		for (int x = 0; x < MAX; x++) {
			graph[y][x] = INF;
		}
	}
}

int main(void) {
	int n, m, s, e;
	cin >> n >> m;

	initMap();

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}
	
	cin >> s >> e;

	dijkstra(n, s, e);

	return 0;
}
