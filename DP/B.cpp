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

const int maxn = 3 * 1e5;
int x[maxn];
int dp[maxn];
void solve() {
    int n;
    cin >> n;
    forn(i, n) cin >> x[i];

    for (int i = n - 1; i >= 0; i--) {
        dp[i] = x[i];
        int j = i + x[i];
        if (j < n) {
            dp[i] += dp[j];
        }
    }
    cout << *max_element(dp, dp + n) << newl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // t=1;
    while (t--) {
        solve();
    }

    return 0;
}
