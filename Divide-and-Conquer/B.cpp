#include <bits/stdc++.h>
using namespace std;

#define newl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;

const int INF = 1e9;
const ll LLINF = 1e18;

void solve()
{
    int n, m;
    cin >> n;

    int prev = 0;
    unordered_map<int, int> idxs;
    for (size_t i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        int l = prev + 1;
        int r = prev + a;
        // cout << l << " " << r << newl;
        prev += a;

        for (size_t j = l; j <= r; j++)
        {
            idxs[j] = i;
        }
    }

    cin >> m;
    for (size_t i = 0; i < m; i++)
    {
        int q;
        cin >> q;
        cout << idxs[q] << newl;
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
