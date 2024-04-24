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

int solve() {
    int a, b, c, d, e, f;
    int ans = 0;

    cin >> b >> a >> d >> c >> f >> e;
    if (a == c && e < a) {
        return abs(b - d);
    } else if (c == e && a < c) {
        return abs(d - f);
    } else if (a == e && c < a) {
        return abs(b - f);
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    cin >> t;
    while (t--) {
        cout << solve() << newl;
    }

    return 0;
}
