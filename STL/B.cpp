#include <bits/stdc++.h>
using namespace std;

#define newl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int INF = 1e9;

void solve() {
    int n;
    cin >>n; 
    vi x;
    for (size_t i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        x.push_back(y);
    }
    for(auto it = x.begin(); it!=x.end(); ++it){
        cout << *it << newl;
    }
    
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
