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
    int n, m;
    cin >> n >> m;
    vi degrees(n);

    forn(i, m)
    {
        int a;
        cin >> a;
        degrees[a - 1]++;
        cin >> a;
        degrees[a - 1]++;
    }

    int ones = 0;
    int twos = 0;
    int threes = 0;

    for (int x : degrees)
    {
        if (x == 1)
            ones++;
        else if (x == 2)
            twos++;
        else
            threes++;
    }

    if (ones == 2 && threes == 0 && twos > 0)
    {
        cout << "bus topology" << newl;
    }

    else if (ones == 0 && threes == 0 && twos > 0)
    {
        cout << "ring topology" << newl;
    }

    else if (threes == 1 && twos == 0 && ones > 0)
    {
        cout << "star topology" << newl;
    }
    else
    {
        cout << "unknown topology" << newl;
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
