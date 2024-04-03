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
    int n, k;
    cin >> n >> k;
    map<int, int> ans;
    stack<int> candidates;
    forn(i, 31) {
        unsigned int mask = 1 << i;
        int ibit = n & mask;
        if (ibit) {
            if (i > 0) {
                candidates.push(mask);
            }
            ans[mask]++;
        }
    }
    if (ans.size() > k) {
        cout << "NO" << newl;
        return;
    }
    int len = ans.size();
    while (len < k && !candidates.empty()) {
        int next = candidates.top();
        candidates.pop();
        ans[next]--;
        ans[next / 2] += 2;
        if (next > 2) {
            candidates.push(next / 2);
            candidates.push(next / 2);
        }
        len++;
    }
    if (len < k) {
        cout << "NO" << newl;
        return;
    }
    cout << "YES" << newl;
    for (pii x : ans) {
        forn(i, x.second) {
            cout << x.first << " ";
        }
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
