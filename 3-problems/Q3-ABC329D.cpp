#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

using S = long long;
S INF = 1e18;
S op(S a, S b) { return max(a, b); }
S e() { return -INF; }

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m, 0);
    for (int i=0; i<m; ++i) {
        cin >> a[i], --a[i];
    }

    //セグ木の宣言
    vector<ll> v(n, 0);
    segtree<S, op, e> seg(v);
    
    for (int i=0; i<m; ++i) {
        //a[i]番目の要素を1大きくする
        seg.set(a[i], seg.get(a[i])+1);
        //全体の最大値をmxとする
        int mx = seg.all_prod();
        
        int ng = 0;//条件を満たさない値
        int ok = n;//条件を満たす値
        auto f = [&](int mid)->bool{
            return seg.prod(0, mid) == mx;
        };
        while(abs(ok-ng) > 1){
            int mid = (ok + ng)/2;
            if(f(mid)) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }
}
