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

void solve() {
    int n;
    cin >> n;

    vector<pll> city;
    ll ans = 0;
    ll a, c;
    forn(i, n) {
        cin >> a >> c;
        city.pb({a, c});
        ans += c;
    }
    sort(city.begin(), city.end());
    priority_queue<pll> Q;
    vi vis(n, false);
    Q.push({0, 0});
    while (!Q.empty()) {
        pll high = Q.top();
        ll d = high.first;
        int i = high.second;
        Q.pop();
        if (vis[i]) {
            continue;
        }
        vis[i] = true;
        if (i + 1 == n) {
            ans -= d;
            break;
        }
        if (i > 0) {
            Q.push({d, i - 1});
        }
        ll curd = city[i].first;
        ll curi = city[i].second;
        const pll bound = {curd + curi, LLINF};
        int j = lower_bound(city.begin(), city.end(), bound) - city.begin() - 1;
        Q.push({d, j});
        int next = j + 1;
        if (next < n) {
            Q.push({d - city[next].first + curd + curi, next});
        }
    }
    cout << ans << newl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
