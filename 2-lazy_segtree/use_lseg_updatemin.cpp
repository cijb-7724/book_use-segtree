#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

//以下9行はまるまるコピペで良い
using S = long long;
using F = long long;
S INF = 1e18;
S op(S a, S b){ return min(a, b); }
S e(){ return INF; }
S mapping(F f, S s){ return (f == INF ? s : f); }
F composition(F f, F g){ return (f == INF ? g : f); }
F id(){ return INF; }

void print_seg(lazy_segtree<S, op, e, F, mapping, composition, id> &seg, int n) {
    for (int i=0; i<n; ++i) {
        //0-indexでi番目の要素を取得する
        cout << seg.get(i) << ' ';
    }
    cout << endl;
}

int main() {
    //初期状態のリストvを用意する
    vector<S> v = {3, 1, 4, 1, 5, 9, 2, 6};
    //このように書くと遅延セグ木が使える　これもコピペする
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    //[0, 4)の最小値 区間は半開区間で指定する
    cout << seg.prod(0, 4) << endl;//1
    //全区間の最小値
    cout << seg.all_prod() << endl;//1
    //[1, 8)を7で上書きする
    seg.apply(1, 8, 7);
    print_seg(seg, v.size());//seg木の各要素を見てみる
    //全区間の最小値
    cout << seg.all_prod() << endl;//3
}
