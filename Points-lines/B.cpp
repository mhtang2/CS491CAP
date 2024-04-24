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
    ll r, d, n;
    cin >> r >> d >> n;
    ll x, y, r2;
    ll ans = 0;
    forn(i, n) {
        cin >> x >> y >> r2;
        bool c1 = x * x + y * y <= (r - r2) * (r - r2);
        bool c2 = x * x + y * y >= (r - d + r2) * (r - d + r2);

        ans += c1 && c2;
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
