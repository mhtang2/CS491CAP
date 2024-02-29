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

int fac2(int x) {
    int r = 0;
    while (x % 2 == 0) {
        r++;
        x /= 2;
    }
    return r;
}

void solve() {
    int n, x;
    cin >> n;
    vi v;
    int facs=0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        facs += fac2(x);
        v.pb(fac2(i));
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = n - 1; i >= 0 && facs < n; i--) {

        facs += v[i];
        ans++;
    }
    
    if (facs < n) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
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
