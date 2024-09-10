#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

//以下14行はまるまるコピペで良い
struct S{
    long long value;
    int size;
};
using F = long long;
long long INF = 1e18;
S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S s) {
    if (f != INF) s.value = f*s.size;
    return s;
}
F composition(F f, F g){ return (f == INF ? g : f); }
F id(){ return INF; }

void print_seg(lazy_segtree<S, op, e, F, mapping, composition, id> &seg, int n) {
    for (int i=0; i<n; ++i) {
        //0-indexでi番目の要素を取得する
        cout << seg.get(i).value << ' ';//書き方が違うことに注意
    }
    cout << endl;
}

int main() {
    //初期状態のリストvを用意する
    vector<ll> v = {3, 1, 4, 1, 5, 9, 2, 6};
    //このように書くと遅延セグ木が使える　これもコピペする
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v.size());
    for (int i=0; i<v.size(); ++i) {
        seg.set(i, {v[i], 1});
    }
    //[0, 4)の総和 区間は半開区間で指定する
    cout << seg.prod(0, 4).value << endl;//9
    //全区間の総和
    cout << seg.all_prod().value << endl;//31
    //[0, 8)を100で上書きする
    seg.apply(0, 8, 100);
    print_seg(seg, v.size());//seg木の各要素を見てみる
    //全区間の総和
    cout << seg.all_prod().value << endl;//800
}
