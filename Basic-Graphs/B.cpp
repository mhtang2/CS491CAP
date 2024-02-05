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

string solve()
{
    int n, s;
    cin >> n >> s;
    vi front(n), back(n);
    forn(i, n) { cin >> front[i]; }
    forn(i, n) { cin >> back[i]; }
    if (front[0] == 0)
        return "NO";
    if (front[s - 1] == 1)
        return "YES";
    if (back[s - 1] == 0)
        return "NO";
    for (int i = s - 1; i < n; ++i)
    {
        if (front[i] == 1 && back[i] == 1)
        {
            return "YES";
        }
    }
    return "NO";
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
        cout << solve() << newl;
    }

    return 0;
}
