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

ll m;

void solve() {
    ll a, b;
    cin >> a >> b;
    ll result = 1;
    a = a % m;

    if (a == 0) {
        cout << 0 << newl;
        return;
    }

    while (b > 0) {
        if (b & 1) {
            result = (result * a) % m;
        }
        b = b >> 1;
        a = (a * a) % m;
    }

    cout << result << newl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    cin >> t >> m;
    while (t--) {
        solve();
    }

    return 0;
}
