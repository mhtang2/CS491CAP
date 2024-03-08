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

    int n;
    cin >> n;
    vvi x(n, vi(5));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            cin >> x[i][j];
        }
    }

    // for (const auto &innerVec : x)
    // {
    //     for (const auto &element : innerVec)
    //     {
    //         std::cout << element << " ";
    //     }
    //     std::cout << std::endl;
    // }
    string ans = "NO";
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if (j != i)
            {
                int cnt1 = 0;
                int cnt2 = 0;
                int cntno = 0;
                for (size_t k = 0; k < n; k++)
                {
                    if (x[k][i] == 1)
                    {
                        cnt1 += 1;
                    }
                    if (x[k][j] == 1)
                    {
                        cnt2 += 1;
                    }
                    if (x[k][i] == 0 && x[k][j] == 0)
                    {
                        cntno += 1;
                    }
                }
                if ((cnt1 >= n / 2) && (cnt2 >= n / 2) && (cntno == 0))
                {
                    ans = "YES";
                }
            }
        }
    }

    cout << ans << newl;
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
