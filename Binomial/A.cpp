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

ll C(int n, int m) {
    ll ans = 1;
    forn(i, m) {
        ans *= (n - i);
        ans /= (i + 1);
    }
    return ans;
}

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    ll ans = 0;
    for (int i = 4; i < t; ++i) {
        ans += C(n, i) * C(m, t - i);
    }
    cout << ans << endl;
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
