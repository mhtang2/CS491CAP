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
    set<int> notifications[300000 + 10];
    set<pii> applications;
    int n, q;
    cin >> n >> q;
    int position = 0;
    for (int i = 0; i < q; ++i)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            notifications[x].insert(position);
            applications.insert({position++, x});
        }
        else if (type == 2)
        {
            int x;
            cin >> x;
            for (auto &i : notifications[x])
                applications.erase({i, x});
            notifications[x].clear();
        }
        else
        {
            int t;
            cin >> t;
            while (!applications.empty() && applications.begin()->first < t)
            {
                pii p = *applications.begin();
                applications.erase(p);
                notifications[p.second].erase(p.first);
            }
        }
        cout << applications.size() << newl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
