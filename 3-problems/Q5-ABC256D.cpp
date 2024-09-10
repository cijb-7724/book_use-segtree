#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

using S = long long;
using F = long long;
S INF = 1e18;
S op(S a, S b){ return min(a, b); }
S e(){ return INF; }
S mapping(F f, S s){ return (f == INF ? s : f); }
F composition(F f, F g){ return (f == INF ? g : f); }
F id(){ return INF; }

int main() {
    int n;
    cin >> n;
    int mx = 2e5+10;

    //全要素が0の遅延セグ木
    vector<ll> v(mx, 0);
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

    for (int i=0; i<n; ++i) {
        int l, r;
        cin >> l >> r;
        //[l, r)が集合に含まれていることを
        //1があることで表現する
        seg.apply(l, r, 1);
    }

    vector<pair<int, int>> ans;
    int l = 0;
    //今いる座標が集合に含まれるかを管理するフラグ
    bool in = false;
    for (int i=0; i<mx; ++i) {//座標iを走査
        //今まで集合の外だったけど，座標iの時点で集合の内側に入った
        if (!in && seg.get(i) == 1) {
            in = true;
            l = i;
        }
        //今まで集合の中だったけど，座標iの時点で集合の外側に出た
        if (in && seg.get(i) == 0) {
            ans.push_back({l, i});
            in = false;
        }
    }
    //答えを出力
    for (auto [x, y]: ans) {
        cout << x << ' ' << y << endl;
    }
}
