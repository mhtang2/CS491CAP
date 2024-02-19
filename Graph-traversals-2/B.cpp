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

const int maxn = 5e5 + 10;
vi graph[maxn];

int components[maxn], sizes[maxn], component, n;

int dfs(int x) {
    if (components[x])
        return 0;
    components[x] = component;
    int ans = x <= n ? 1 : 0;
    for (auto y : graph[x])
        ans += dfs(y);
    return ans;
}

void solve() {
    int m, c, x;
    cin >> n >> m;
    forn(i, m) {
        vi group;
        cin >> c;
        forn(j, c) {
            cin >> x;
            group.pb(x);
        }
        forn(j, c - 1) {
            graph[group[j]].pb(group[j + 1]);
            graph[group[j + 1]].pb(group[j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!components[i]) {
            component++;
            sizes[component] = dfs(i);
        }
        cout << sizes[components[i]] << " ";
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
