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
    string s;
    cin >> s;
    vi ans(s.length());
    int len = 0;
    int i = 1;
    while (i < s.length()) {
        if (s[i] == s[len]) {
            len++;
            ans[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = ans[len - 1];
            } else {
                ans[i] = 0;
                i++;
            }
        }
    }
    for (auto x : ans) {
        cout << x << " ";
    }
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
