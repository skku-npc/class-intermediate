#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int v, e, src;
vector<pii> adj[20005];  // <v, w>
int dist[20005];
bool visit[20005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> v >> e >> src;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    memset(dist, 0x3f, sizeof(dist));
    dist[src] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, src);
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visit[u]) continue;
        visit[u] = true;

        for (auto &nxt : adj[u]) {
            int v = nxt.first;
            int w = nxt.second;
            if (!visit[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (visit[i]) {
            cout << dist[i] << '\n';
        } else {
            cout << "INF\n";
        }
    }
}