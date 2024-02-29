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
    ll n, k;
    cin >> n >> k;

    vll x(k);
    for (int i = 0; i < k; ++i) {
        cin >> x[i];
    }
    if (k > 1 && x[0] > (n - k + 1) * (x[1] - x[0])) {
        cout << "NO" << newl;
        return;
    }

    bool good = true;
    for (int i = 2; i < k; ++i) {
        if (x[i - 1] * 2 > x[i] + x[i - 2]) {
            good = false;
            break;
        }
    }
    if (good)
        cout << "YES" << newl;
    else
        cout << "NO" << newl;
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
