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

int gcd(int a, int b) {
    if (a < 1) return b;
    return gcd(b % a, a);
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    forn(i, n) cin >> a[i];

    vi ans;
    forn(i, n) {
        ans.pb(a[i]);
        if (i + 1 < n && gcd(a[i], a[i + 1]) > 1)
            ans.pb(1);
    }

    cout << (ans.size() - n) << newl;
    forn(i, ans.size()) {
        cout << ans[i] << " ";
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
