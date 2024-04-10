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

ll P(int n, int m) {
    m = min(n, m);
    ll ans = 1;
    forn(i, m) {
        ans *= (n - i);
    }
    return ans;
}

ll C(int n, int m) {
    m = min(n, m);
    ll ans = 1;
    forn(i, m) {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    ll ans = C(n, 5) * P(n, 5);
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
