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
ll catalans[] = {1,
                 1,
                 2,
                 5,
                 14,
                 42,
                 132,
                 429,
                 1430,
                 4862,
                 16796,
                 58786,
                 208012,
                 742900,
                 2674440,
                 9694845,
                 35357670,
                 129644790,
                 477638700,
                 1767263190,
                 6564120420,
                 24466267020,
                 91482563640,
                 343059613650,
                 1289904147324};
void solve() {
    int n;
    cin >> n;

    cout << catalans[n] << newl;
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
