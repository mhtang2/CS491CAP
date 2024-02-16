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

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void solve() {
    int r, c;
    pii source;
    char x;
    cin >> r >> c;
    vector<vector<char>> X(r, vector<char>(c));
    forn(i, r) {
        forn(j, c) {
            cin >> x;
            X[i][j] = x;
            if (x == 'E') {
                source = {i, j};
            }
        }
    }
    // for (auto v : X) {
    //     for (auto x : v) {
    //         cout << x;
    //     }
    //     cout << newl;
    // }

    int comp;

    vvi distance(r, vector<int>(c, INF));
    queue<pii> q;
    distance[source.first][source.second] = 0;
    q.push(source);
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        if (X[cur.first][cur.second] == 'S') comp = distance[cur.first][cur.second];
        forn(i, 4) {
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || X[ny][nx] == 'T' || distance[ny][nx] != INF) continue;
            distance[ny][nx] = distance[cur.first][cur.second] + 1;
            q.push(pii(ny, nx));
        }
    }

    int total = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if ('0' <= X[i][j] && X[i][j] <= '9' && distance[i][j] <= comp) {
                total += X[i][j] - '0';
            }
        }
    }
    cout << total << newl;
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
