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
    ll n, d, m;
    cin >> n >> d >> m;
    forn(i, m) {
        ll x, y;
        cin >> x >> y;
        bool c1 = x + y >= d;
        bool c2 = x + y <= 2 * n - d;
        bool c3 = abs(x - y) <= d;
        string ans = (c1 && c2 && c3) ? "YES" : "NO";
        cout << ans << newl;
    }
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
