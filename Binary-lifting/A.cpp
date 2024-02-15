#include <bits/stdc++.h>
using namespace std;

#define newl '\n'
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;

const int INF = 1e9;
const ll LLINF = 1e18;

const int big = 2 * 1e5 + 10;
vi depth(big);
vi parent(big);
vi visited(big);
vvi graph(big);

int find_center() {
    int n = graph.size();
    if (n == 0)
        return -1;

    vector<int> dist(n, 0);

    // Perform BFS from any vertex
    queue<int> q;
    q.push(1);  // Start BFS from vertex 0
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int neighbor : graph[v]) {
            if (dist[neighbor] == 0) {
                dist[neighbor] = dist[v] + 1;
                q.push(neighbor);
            }
        }
    }

    // Find the farthest vertex from vertex 0
    int farthest_vertex = max_element(dist.begin(), dist.end()) - dist.begin();

    // Reset distances
    fill(dist.begin(), dist.end(), 0);

    // Perform BFS from the farthest vertex

    queue<int>().swap(q);
    q.push(farthest_vertex);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int neighbor : graph[v]) {
            if (dist[neighbor] == 0) {
                dist[neighbor] = dist[v] + 1;
                q.push(neighbor);
            }
        }
    }

    // Find the farthest vertex from the farthest vertex
    int diameter = *(max_element(dist.begin(), dist.end()));
    int radius = diameter / 2;
    int center = find(dist.begin(), dist.end(), radius) - dist.begin();
    return center;
}

void dfs(int u, int d) {
    visited[u] = true;

    for (int v : graph[u]) {
        if (!visited[v]) {
            depth[v] = d + 1;
            parent[v] = u;
            dfs(v, d + 1);
        }
    }
}
ll tout[big];
ll tin[big];
ll timer = 1;
void dfs_timer(int v, int p) {
    tin[v] = ++timer;
    for (int u : graph[v]) {
        if (u != p)
            dfs(u, v);

        tout[v] = ++timer;
    }
}

bool is_ancestor(int u, int v) {
    if (tin[u] == 0 || tin[v] == 0)
        return false;
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int find_lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    while (u != v) {
        if (depth[u] > depth[v])
            u = parent[u];
        else
            v = parent[v];
    }
    return u;
}
void solve() {
    int n, m, a, b, t;
    cin >> n >> m;

    forn(i, n - 1) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    int center = find_center();
    dfs(center, 0);
    dfs_timer(center, center);
    forn(i, m) {
        cin >> t >> a >> b;
        // cout << t << " " << a << " " << b << newl;
        if (t == 1) {
            depth[b] = depth[a] + 1;
            parent[b] = a;
        } else {
            int lca = find_lca(a, b);
            int d = depth[a] + depth[b] - 2 * depth[lca];
            cout << d << newl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
