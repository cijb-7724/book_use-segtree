#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

//以下の4行はまるまるコピペで良い
using S = long long;
S INF = 1e18;
S op(S a, S b) { return min(a, b); }
S e() { return INF; }

void print_seg(segtree<S, op, e> &seg, int n) {
    for (int i=0; i<n; ++i) {
        //0-indexでi番目の要素を取得
        cout << seg.get(i) << ' ';
    }
    cout << endl;
}

int main() {
    //初期状態のリストvを用意する
    vector<ll> v = {3, 1, 4, 1, 5, 9, 2, 6};
    //このように書くとセグ木が使える　これもコピペする
    segtree<S, op, e> seg(v);
    //[4, 8)の最小値 区間は半開区間で指定する
    cout << seg.prod(4, 8) << endl;//2
    //全区間の最小値
    cout << seg.all_prod() << endl;//1
    //0番目の要素を-5で上書き
    seg.set(0, -5);
    print_seg(seg, v.size());//seg木の各要素を見てみる
    //全区間の最小値
    cout << seg.all_prod() << endl;//-5
}
