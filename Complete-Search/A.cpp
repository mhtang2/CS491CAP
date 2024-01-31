#include <bits/stdc++.h>
using namespace std;

#define newl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int INF = 1e9;

bool check(vector<pii> &prev, int row, int col)
{
    for (pii P : prev)
    {
        int prow = P.first;
        int pcol = P.second;
        if (row == prow || abs(prow - row) == abs(pcol - col))
        {
            return false;
        }
    }
    return true;
}

int recurse(vector<pii> &prev, int col, int K, int N, int M)
{
    int count = 0;

    if (K == 0)
    {
        return 1;
    }
    if (col >= M)
    {
        return 0;
    }

    for (int row = 0; row < N; ++row)
    {
        if (!check(prev, row, col))
        {
            continue;
        }
        prev.push_back({row, col});
        count += recurse(prev, col + 1, K - 1, N, M);
        prev.pop_back();
    }
    count += recurse(prev, col + 1, K, N, M);

    return count;
}

void solve()
{
    int K, N, M;
    cin >> K >> N >> M;
    vector<pii> prev;
    cout << recurse(prev, 0, K, N, M) << newl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
