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
    int na, nb;
    cin >> na >> nb;
    map<string, string> servers;
    // map<string, string> names;
    for (size_t i = 0; i < na; i++)
    {
        string name, ip;
        cin >> name >> ip;
        servers[ip] = name;
    }
    for (size_t i = 0; i < nb; i++)
    {
        string command,ip,name;
        cin >> command >> ip;
        ip.pop_back();
        name = servers[ip];
        cout << command << " "<<ip<<"; #"<<name<<newl;
    }
    
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
