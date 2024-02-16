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
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int rdif = abs(r1 - r2);
    int cdif = abs(c1 - c2);

    int rook = 2 - (r1 == r2) - (c1 == c2);
    int bishop = 0;
    if (rdif == cdif)
        bishop = 1;
    else if ((r1 + c1) % 2 == (r2 + c2) % 2)
        bishop = 2;
    int king = max(rdif, cdif);

    cout << rook << " " << bishop << " " << king << newl;
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
