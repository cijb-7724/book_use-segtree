#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

using S = long long;
S INF = 1e18;
S op_max(S a, S b) { return max(a, b); }
S e_max() { return -INF; }
S op_min(S a, S b) { return min(a, b); }
S e_min() { return INF; }

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> p(n, 0);
    for (int i=0; i<n; ++i) {
        cin >> p[i], --p[i];
    }
    vector<ll> a(n);
    for (int i=0; i<n; ++i) {
        a[p[i]] = i;
    }

    //セグ木の宣言
    segtree<S, op_min, e_min> seg_min(a);
    segtree<S, op_max, e_max> seg_max(a);
    
    int ans = n;
    for (int i=0; i<n; ++i) {
        if (i+k > n) break;
        int mx = seg_max.prod(i, i+k);
        int mn = seg_min.prod(i, i+k);
        ans = min(ans, mx-mn);
    }
    cout << ans << endl;
}
