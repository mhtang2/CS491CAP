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
    int n, k;
    cin >> n >> k;
    vll pos, neg;
    forn(i, n) {
        int x;
        cin >> x;
        if (x > 0) {
            pos.pb(x);
        } else {
            neg.pb(-x);
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    ll ans = 0;
    for (int i = pos.size() - 1; i >= 0; i -= k)
        ans += 2 * pos[i];

    for (int i = neg.size() - 1; i >= 0; i -= k)
        ans += 2 * neg[i];
    ll pmax = pos.empty() ? 0 : pos.back();
    ll nmax = neg.empty() ? 0 : neg.back();
    ans -= max(pmax, nmax);
    cout << ans << newl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
