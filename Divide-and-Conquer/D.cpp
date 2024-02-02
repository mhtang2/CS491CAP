#include <bits/stdc++.h>
using namespace std;

#define newl '\n'
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;

const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n;
    cin >> n;

    int L = 1, R = n;
    while (L < R)
    {
        int m = L + (R - L) / 2;
        int x, y;
        cout << "? " << m << endl;
        cin >> x;
        cout << "? " << (m + 1) << endl;
        cin >> y;
        if (x < y)
            R = m;
        else
            L = m + 1;
    }
    cout << "! " << L << endl;
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
