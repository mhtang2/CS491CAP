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
typedef vector<vi> vvi;
typedef vector<pii> vpii;

const int INF = 1e9;
const ll LLINF = 1e18;

const int maxn = 1e5 + 10;
const int mod = 1000000007ll;

int lowidx[maxn], idx[maxn], timer, comps[maxn], compcnt, minnode[maxn], cnt[maxn], cost[maxn];
bool instack[maxn];
stack<int> S;
vi graph[maxn];

void dfs(int u) {
    lowidx[u] = idx[u] = ++timer;
    S.push(u);
    instack[u] = true;

    for (int v : graph[u]) {
        if (idx[v] == 0) {
            dfs(v);
            lowidx[u] = min(lowidx[u], lowidx[v]);
        } else if (instack[v]) {
            lowidx[u] = min(lowidx[u], idx[v]);
        }
    }

    if (idx[u] == lowidx[u]) {
        compcnt++;
        int v = -1;
        do {
            v = S.top();
            S.pop();
            instack[v] = false;
            comps[v] = compcnt;
        } while (u != v);
    }
}

void scc(int n) {
    forn(i, n) if (idx[i] == 0) dfs(i);
}

void solve() {
    int n, m, u, v;
    cin >> n;
    forn(i, n) {
        cin >> cost[i];
    }
    cin >> m;
    forn(i, m) {
        cin >> u >> v;
        graph[u - 1].pb(v - 1);
    }
    scc(n);
    for (int i = 1; i <= compcnt; i++) minnode[i] = 1e9 + 10;
    forn(i, n) {
        int c = comps[i];
        int w = cost[i];
        if (minnode[c] > w)
            minnode[c] = w, cnt[c] = 1;
        else if (minnode[c] == w)
            cnt[c]++;
    }
    ll a = 0, b = 1;
    for (int i = 1; i <= compcnt; i++) {
        a += minnode[i];
        b *= cnt[i];
        b %= mod;
    }
    cout << a << " " << b << endl;
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
