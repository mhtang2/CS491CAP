#include <bits/stdc++.h>
using namespace std;

#define newl '\n'
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;

const int INF = 1e9;
const ll LLINF = 1e18;

ll getDamage(const vll &a, ll k, int n)
{
    ll total = 0;
    forn(i, n - 1)
    {
        total += min(k, a[i + 1] - a[i]);
    }
    return total + k;
}

void solve()
{
    int n;
    ll h;
    cin >> n >> h;
    vll a(n);
    forn(i, n)
    {
        cin >> a[i];
    }

    ll low = 1;
    ll high = 1e18;
    while (low < high)
    {
        ll mid = low + (high - low) / 2;
        if (getDamage(a, mid, n) >= h)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << low << newl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // t=1;
    while (t--)
    {
        solve();
    }

    return 0;
}
