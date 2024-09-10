#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

//以下の10行はまるまるコピペで良い
struct S{
    long long value;
    int size;
};
using F = long long;
S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S s){ return {s.value + f*s.size, s.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

void print_seg(lazy_segtree<S, op, e, F, mapping, composition, id> &seg, int n) {
    for (int i=0; i<n; ++i) {
        cout << seg.get(i).value << ' ';
    }
    cout << endl;
}

int main() {
    //初期状態のリストvを用意する
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    //サイズだけ指定してからのセグ木を作る
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v.size());
    for (int i=0; i<v.size(); ++i) {
        seg.set(i, {v[i], 1});//初期化時は{値, 1}とする
    }
    //[4, 7)の総和 区間は半開区間で指定する
    cout << seg.prod(4, 7).value << endl;//16
    //全区間の総和
    cout << seg.all_prod().value << endl;//31
    //[0, 8)に100を加算する
    seg.apply(0, 8, 100);
    print_seg(seg, v.size());//seg木の各要素を見てみる
    //全区間の総和
    cout << seg.all_prod().value << endl;//831
}
