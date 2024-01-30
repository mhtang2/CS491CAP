#include <bits/stdc++.h>
using namespace std;

#define newl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int INF = 1e9;
const ll MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;

    vi v;
    for (size_t i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(all(v));
    cout << v[n-1] - v[0] + v[n-2] - v[1] <<newl;
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
