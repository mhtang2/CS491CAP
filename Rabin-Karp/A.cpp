#include <bits/stdc++.h>
using namespace std;

#define newl '\n'
#define forn(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvi;
typedef vector<pii> vpii;

const ll INF = 1e9;
const ll LLINF = 1e18;

void solve() {
    string s, d;
    cin >> s >> d;
    if (d.length() > s.length()) {
        cout << 0 << newl;
        return;
    }

    ll a = 256;
    ll a2 = 512;

    ll b = 300007;

    ll pow = 1, pow2 = 1;
    for (ll i = 1; i < d.length(); ++i) {
        pow = (pow * a) % b;
        pow2 = (pow2 * a2) % b;
    }

    ll hash_s = 0;
    ll hash_d = 0;

    ll hash_s2 = 0;
    ll hash_d2 = 0;

    for (ll i = 0; i < d.length(); ++i) {
        hash_s = (hash_s * a + s[i]) % b;
        hash_d = (hash_d * a + d[i]) % b;

        hash_s2 = (hash_s2 * a2 + s[i]) % b;
        hash_d2 = (hash_d2 * a2 + d[i]) % b;
    }

    ll ans = 0;
    for (ll i = 0; i <= s.length() - d.length(); ++i) {
        if (hash_s == hash_d && hash_s2 == hash_d2)
            ans++;
        hash_s = ((b + hash_s) - (s[i] * pow % b)) * a % b;
        hash_s += s[i + d.length()];
        hash_s = hash_s % b;

        hash_s2 = ((b + hash_s2) - (s[i] * pow2 % b)) * a2 % b;
        hash_s2 += s[i + d.length()];
        hash_s2 = hash_s2 % b;
    }
    cout << ans << newl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
