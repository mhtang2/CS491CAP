#include <bits/stdc++.h>
using namespace std;

#define newl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;

const int INF = 1e9;

void solve()
{
    ll l = 1;
    ll r = 1e18;
    string out = "";
    while (1)
    {
        ll guess = l + ((r - l) / 2);
        cout << guess << endl;
        cin >> out;
        if (out == "LOWER")
            r = guess-1;
        else if (out == "HIGHER")
            l = guess+1;
        else
            break;
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
