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
    ll N, S;
    cin >> N >> S;
    vll w(N), c(N);
    ll maxw = 0;
    forn(i, N) {
        cin >> w[i] >> c[i];
        maxw = max(maxw, w[i]);
    }

    for (long long i = 0; i < N; i++) {
        cin >> w[i] >> c[i];
    }

    vll dp(3 * maxw + 2);

    for (long long i = 0; i < N; i++)
        for (long long j = w[i]; j <= 3 * maxw; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);

    ll e = 0;
    ll S1 = S;
    ll S2 = S;
    vll l(3 * maxw + 2), r(3 * maxw + 2);

    ll maxdiff = -1;
    while (S1 > 0) {
        l[e] = S1;
        r[e] = S2;
        maxdiff = max(maxdiff, r[e] - l[e]);
        S1 = (S1 - maxw) / 2 + (S1 - maxw) % 2;
        S2 = (S2 + maxw) / 2;
        e++;
    }

    vector<vector<ll>> ans(e + 2, vll(maxdiff + 2));
    ll ret = -1;
    for (long long i = e - 1; i >= 0; i--) {
        for (long long j = l[i]; j <= r[i]; j++) {
            if (j <= 3 * maxw) {
                ans[i][j - l[i]] = dp[j];
            } else {
                for (long long k = (j - maxw) / 2 + (j - maxw) % 2; k * 2LL <= j; k++) {
                    ans[i][j - l[i]] = max(ans[i][j - l[i]], ans[i + 1][k - l[i + 1]] + ans[i + 1][j - k - l[i + 1]]);
                }
            }
            // ret = max(ret, ans[i][j - l[i]]);
        }
    }
    cout << ans[0][0] << newl;
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
