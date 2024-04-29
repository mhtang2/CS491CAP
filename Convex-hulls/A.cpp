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

struct point {
    ll x = 0, y = 0;
    point() {}
    point(ll a, ll b) {
        x = a;
        y = b;
    }
};

point sub(point a, point b) {
    return point(a.x - b.x, a.y - b.y);
}
ll det(point a, point b) {
    return a.x * b.y - b.x * a.y;
}
bool dir(point p, point u, point v) {
    return det(sub(u, p), sub(v, p)) >= 0;
}
bool revdir(point p, point u, point v) {
    return det(sub(u, p), sub(v, p)) <= 0;
}

const int maxn = 1e5 + 10;
point points[maxn], pcurr;

bool inside(int n, point hull[], point p) {
    int l = 1, r = n - 1, m;
    while (l < r) {
        m = (l + r) >> 1;
        if (revdir(hull[0], hull[m], p)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (r == 1 || dir(hull[0], hull[n - 1], p) || dir(hull[r], hull[r - 1], p)) {
        return false;
    }
    return true;
}

void solve() {
    int i, j, k, n, m;
    cin >> n;
    for (i = n - 1; i >= 0; --i) {
        cin >> points[i].x;
        cin >> points[i].y;
    }
    cin >> m;
    for (i = 0; i < m; ++i) {
        cin >> pcurr.x;
        cin >> pcurr.y;
        if (!inside(n, points, pcurr)) {
            puts("NO");
            return;
        }
    }
    puts("YES");
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
