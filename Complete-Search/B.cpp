#include <bits/stdc++.h>
using namespace std;

#define newl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int INF = 1e9;

void solve()
{
    ll h1, a1, h2, a2, k, w, a;

    cin >> h1 >> a1 >> h2 >> a2 >> k >> w >> a;
    bool ans = false;
    for (size_t i = 0; i <= k; i++)
    {
        ll he = h1 + (i * a);
        ll ae = a1 + w * (k - i);
        ll x = h2 / ae;
        if (h2 % ae != 0)
            x++;
        ll y = he / a2;
        if (he % a2 != 0)
            ++y;
        if (x <= y)
        {
            ans = true;
            break;
        }
    }
    if (ans)
        cout << "YES" << newl;
    else
        cout << "NO" << newl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
