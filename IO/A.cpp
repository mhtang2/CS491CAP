#include <bits/stdc++.h>
using namespace std;

#define newl '\n'


typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int INF = 1e9;

void solve() {
    int na,nb;
    int count = 0;
    cin >> na >>nb;
    int tmp;
    for (size_t i = 0; i < na; i++)
    {
        cin >> tmp;
        count += tmp;
    }
    for (size_t i = 0; i < nb; i++)
    {
        cin >> tmp;
        count -= tmp;
    }
    cout << count << newl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
