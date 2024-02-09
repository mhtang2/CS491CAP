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

void dfs(int v, map<int, vector<int>> &graph, unordered_set<int> &visited, int &size)
{
    visited.insert(v);
    size++;
    for (int neighbor : graph[v])
    {
        if (visited.find(neighbor) == visited.end())
        {
            dfs(neighbor, graph, visited, size);
        }
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> graph;
    forn(i, k)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    unordered_set<int> visited;
    int count = 0;
    for (int v = 1; v <= n; ++v)
    {
        if (visited.find(v) == visited.end())
        {
            int size = 0;
            dfs(v, graph, visited, size);
            count += size - 1;
        }
    }
    cout << (k - count) << newl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
