#include <bits/stdc++.h>
using namespace std;

#define newl '\n'
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;

const int INF = 1e9;
const ll LLINF = 1e18;

void dfs(char v, map<char, vector<char>> &graph, unordered_set<char> &visited)
{
    visited.insert(v);
    for (char neighbor : graph[v])
    {
        if (visited.find(neighbor) == visited.end())
        {
            dfs(neighbor, graph, visited);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    map<char, vector<char>> graph;

    // build graph
    forn(i, n)
    {
        string s;
        cin >> s;
        set<char> charSet(s.begin(), s.end());
        for (auto it = charSet.begin(); it != charSet.end(); ++it)
        {
            for (auto it2 = charSet.begin(); it2 != charSet.end(); ++it2)
            {
                graph[*it].push_back(*it2);
            }
        }
    }
    // count connetced;
    unordered_set<char> visited;
    int count = 0;
    for (const auto &kv : graph)
    {
        char v = kv.first;
        if (visited.find(v) == visited.end())
        {
            dfs(v, graph, visited);
            count++;
        }
    }
    cout << count << newl;
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
