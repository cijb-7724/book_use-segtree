#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

//以下9行はまるまるコピペで良い
using S = long long;
using F = long long;
S INF = 1e18;
S op(S a, S b){ return max(a, b); }
S e(){ return -INF; }
S mapping(F f, S s){ return f+s; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

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
    //[0, 4)の最大値 区間は半開区間で指定する
    cout << seg.prod(0, 4) << endl;//4
    //全区間の最大値
    cout << seg.all_prod() << endl;//9
    //[1, 4)に2を加算する
    seg.apply(1, 4, 2);
    //5番目の要素を3で上書きする
    seg.set(5, 3);
    print_seg(seg, v.size());//seg木の各要素を見てみる
    //全区間の最大値
    cout << seg.all_prod() << endl;//6
}
