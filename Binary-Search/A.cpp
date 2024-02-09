#include <bits/stdc++.h>
using namespace std;

#define newl '\n'
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;

const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    set<int> V;
    map<int, int> L;
    map<int, int> R;

    int n, v;
    cin >> n >> v;
    V.insert(v);

    forn(i, n - 1)
    {
        cin >> v;
        int result;
        auto it = V.upper_bound(v);
        int val = *it;
        if (it != V.end() && L.find(val) == L.end())
        {
            L[val] = v;
            result = val;
        }
        else
        {
            it--;
            R[*it] = v;
            result = *it;
        }
        V.insert(v);
        cout << result << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
