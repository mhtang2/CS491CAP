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
    string a, b;
    int n;
    cin >> a >> b >> n;
    string ret = a;
    if (a.length() != b.length()) {
        cout << -1 << newl;
        return;
    }
    int arrsize = 'z' + 1;
    int dist['z' + 1]['z' + 1];
    std::fill_n(&dist[0][0], arrsize * arrsize, INF);
    for (int i = 'a'; i <= 'z'; ++i) {
        dist[i][i] = 0;
    }

    forn(i, n) {
        char A, B;
        int C;
        cin >> A >> B >> C;
        dist[A][B] = min(dist[A][B], C);
    }

    for (int k = 'a'; k <= 'z'; k++) {
        for (int i = 'a'; i <= 'z'; i++) {
            for (int j = 'a'; j <= 'z'; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // for (int i = 'a'; i <= 'z'; ++i) {
    //     for (int j = 'a'; j <= 'z'; ++j) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << newl;
    // }

    int cost = 0;
    forn(i, a.length()) {
        char ai = a[i];
        char bi = b[i];
        if (ai == bi)
            continue;
        int mn = INF;
        char c3 = '#';
        for (int j = 'a'; j <= 'z'; j++) {
            int k = dist[ai][j] + dist[bi][j];
            if (k <= mn)
                mn = k, c3 = j;
        }

        cost += mn;
        ret[i] = c3;
        if (mn >= INF) {
            cout << "-1";
            return;
        }
    }
    cout << cost << newl << ret << newl;
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
