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

ll a[510][510];
int vis[510];

void solve() {
    int n;
    cin >> n;
    forn(i, n) {
        forn(j, n) {
            cin >> a[i][j];
        }
    }

    vi x(n);
    forn(i, n) {
        int temp;
        cin >> temp;
        x[i] = temp - 1;
    }

    vll ret(n);
    for (int ki = n - 1; ki >= 0; ki--) {
        int k = x[ki];
        ll sum = 0;
        vis[k] = 1;
        forn(i, n) {
            forn(j, n) {
                a[i][j] = min(a[i][k] + a[k][j], a[i][j]);
            }
        }

        forn(i, n) {
            forn(j, n) {
                if (vis[i] && vis[j]) {
                    sum += a[i][j];
                }
            }
        }

        ret[ki] = sum;
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i] << " ";
    }
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
