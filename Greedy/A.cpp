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
    int n, B, x, y;
    cin >> n >> B >> x >> y;
    ll a = 0;
    ll s = 0;
    forn(i, n) {
        if (a + x <= B) {
            a += x;
        } else {
            a -= y;
        }
        s += a;
    }
    cout << s << newl;
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
