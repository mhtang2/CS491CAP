#include <bits/stdc++.h>
using namespace std;

#define newl '\n'
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<pii> vpii;

const int INF = 1e9;
const ll LLINF = 1e18;

/*
  An example problem is "Given two permutations of numbers from 1 to N, find their LCS". This one can be solved in O(N*logN).
  Let the sequences be A and B.
  Define a sequence C. C[i] is the index of B[i] in A. (A[C[i]] = B[i])
  LCS of A and B is the longest increasing subsequence of C.
*/
int n;
int LIS(vi& nums) {
    vi ans;
    ans.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        } else {
            int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans.size();
}

void solve() {
    cin >> n;

    vector<int> a(n + 1), b(n + 1), aidx(n + 1), c(n + 1);
    forn(i, n) {
        cin >> a[i];
        aidx[a[i]] = i;
    }
    forn(i, n) {
        cin >> b[i];
        c[i] = aidx[b[i]];
    }
    int ans = 2 * (n - LIS(c));
    cout << ans << newl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
