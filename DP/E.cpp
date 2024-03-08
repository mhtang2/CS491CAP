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

const int maxn = 3000 + 10;
ll x[maxn], dp[maxn][maxn];

void solve() {
    int n;
    cin >> n;

    forn(i, n) {
        cin >> x[i];
        x[i]--;
    }
    memset(dp, 0, sizeof(dp));

    ll total = 0;

    for (int j = n - 1; j >= 0; j--) {
        int k = j + 1;

        for (int l = k + 1; l < n; l++) {
            dp[x[k]][x[l]]++;
        }

        for (int i = 0; i < j; i++) {
            total += dp[x[i]][x[j]];
        }
    }

    cout << total << newl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // t=1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
