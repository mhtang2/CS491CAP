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

ll A, B;
void dfs(int v, vvi &graph, vi &visited, bool AB)
{
    visited[v] = 1;
    if (AB)
    {
        A++;
    }
    else
    {
        B++;
    }

    for (int neighbor : graph[v])
    {
        if (visited[neighbor] == 0)
        {
            dfs(neighbor, graph, visited, !AB);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    vvi graph(n + 1);
    vi visited(n + 1);
    forn(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    dfs(1, graph, visited, true);
    cout << (A * B - (n - 1)) << newl;
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
