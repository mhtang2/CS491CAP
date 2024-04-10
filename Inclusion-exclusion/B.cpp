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

const ll mod = 998244353;

ll binexp(ll a, ll b) {
    ll result = 1;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        b = b >> 1;
        a = (a * a) % mod;
    }
    return result;
}

ll add_mod(ll a, ll b) {
    return (a + b) % mod;
}

ll mul_mod(ll a, ll b) {
    return (a * b) % mod;
}

ll inv(ll x) {
    return binexp(x, mod - 2);
}

vll factorial;

ll C(ll n, ll i) {
    return mul_mod(factorial[n], inv(mul_mod(factorial[i], factorial[n - i])));
}

ll solve() {
    ll n, k;
    cin >> n >> k;

    if (k >= n) {
        return 0;
    }

    factorial = vll(n + 10);
    ll ans = 0;
    factorial[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        factorial[i] = mul_mod(i, factorial[i - 1]);
    }
    for (ll i = 0; i <= n - k; ++i) {
        ll temp = mul_mod(C(n - k, i), binexp(n - k - i, n));
        if (i & 1) {
            ans = add_mod(ans, temp);
        } else {
            ans = add_mod(ans, -temp);
        }
    }

    ans = mul_mod(ans, C(n, n - k));
    if (k > 0) {
        ans = mul_mod(ans, 2);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    // cin >> t;
    while (t--) {
        cout << solve() << newl;
    }

    return 0;
}
