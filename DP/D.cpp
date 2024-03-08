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
const int maxn = 2000 + 100;
ll dp[maxn][maxn], t[maxn], c[maxn];
void solve() {
    ll n;
    cin >> n;
    forn(i, n) {
        cin >> t[i] >> c[i];
        t[i]++;
    }
    forn(i, n + 1) {
        forn(j, n + 1) {
            dp[i][j] = LLINF;
        }
    }
    dp[0][0] = 0;
    forn(i, n) {
        forn(j, n + 1) {
            if (dp[i][j] < LLINF) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                int nextj = min(j + t[i], n);
                dp[i + 1][nextj] = min(dp[i + 1][nextj], dp[i][j] + c[i]);
            }
        }
    }
    cout << dp[n][n] << newl;
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
