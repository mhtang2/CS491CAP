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
const int maxn = 2e5 + 10;
int x[maxn];
map<int, int> dp;
void solve() {
    int n;
    cin >> n;
    forn(i, n) cin >> x[i];

    int ans = 0, lower = 0;

    forn(i, n) {
        int a = x[i];
        dp[a] = dp[a - 1] + 1;
        if (ans < dp[a]) {
            ans = dp[a];
            lower = a;
        }
    }

    vi backtrack;
    for (int i = n - 1; i >= 0; i--) {
        if (x[i] == lower) {
            lower--;
            backtrack.pb(i);
        }
    }
    cout << ans << newl;
    for (int i = backtrack.size() - 1; i >= 0; i--) {
        cout << (1 + backtrack[i]) << " ";
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
