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

ll mod, n;

array<ll, 4> multiply(array<ll, 4> a, array<ll, 4> b) {
    array<ll, 4> c;
    c[0] = (a[0] * b[0] + a[1] * b[2]) % mod;
    c[1] = (a[0] * b[1] + a[1] * b[3]) % mod;
    c[2] = (a[2] * b[0] + a[3] * b[2]) % mod;
    c[3] = (a[2] * b[1] + a[3] * b[3]) % mod;
    return c;
}

ll solve() {
    cin >> n;
    if (n < 2)
        return 1;

    array<ll, 4> a = {1, 1, 1, 0};

    array<ll, 4> result = {1, 0, 0, 1};

    while (n > 0) {
        if (n & 1) {
            result = multiply(result, a);
        }
        n = n >> 1;
        a = multiply(a, a);
    }
    return (result[2] + result[3]) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    cin >> t >> mod;
    while (t--) {
        cout << solve() << newl;
    }

    return 0;
}
