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

const int maxn = 1e5 + 10;

bool switched[maxn];

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    int ans = 0;
    forn(i, n) {
        switched[i] = false;
        bool need_switch = false;
        if (i > 0 and s[i] == s[i - 1] and !switched[i - 1])
            need_switch = true;

        if (i > 1 and s[i] == s[i - 2] and !switched[i - 2])
            need_switch = true;

        switched[i] = need_switch;
        ans += switched[i];
    }

    cout << ans << newl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // t=1;
    while (t--) {
        solve();
    }

    return 0;
}
