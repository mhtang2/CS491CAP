#include <bits/stdc++.h>
using namespace std;

#define newl '\n'
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_bacn_second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;

const int INF = 1e9 + 10;
const ll LLINF = 1e18;

const ll mod = 998244353;

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    forn(i, n) cin >> a[i];
    ll largest = -1;
    for (ll x : a) {
        largest = max(largest, x);
    }
    ll n_largest = 0;
    ll n_second = 0;
    for (ll x : a) {
        if (x == largest) n_largest++;
        if (x == largest - 1) n_second++;
    }
    ll ans = 1;
    ll neg = 1;
    for (ll i = 1; i <= n; ++i) {
        ans = (ans * i) % mod;
        if (i - 1 != n_second) {
            neg = (neg * i) % mod;
        }
    }
    if (n_largest == 1) {
        ans = (ans - neg + mod) % mod;
    }
    cout << ans << newl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
