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

const int maxn = 1e5 + 10;

int dp[maxn][2];
int x[maxn][2];
int n;

void solve() {
    cin >> n;
    forn(i, n) cin >> x[i][0];
    forn(i, n) cin >> x[i][1];

    ll dp1 = 0, dp2 = 0;
    forn(i, n) {
        ll dp1n = max(dp1, dp2 + x[i][0]);
        ll dp2n = max(dp2, dp1 + x[i][1]);
        dp1 = dp1n;
        dp2 = dp2n;
    }

    cout << max(dp1, dp2) << "\n";
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
