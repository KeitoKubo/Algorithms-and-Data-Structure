#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <stdlib.h>  // qsort
#include <math.h>
#include<stdio.h>
using namespace std;

using vi = vector<int>;
using vs = vector<string>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repback(i,n) for(int i=(int)n-1;i>=0;i--)
#define repa(i,a,n) for(int i=a;i<(int)(n);i++)
typedef pair<int, int> P;
typedef queue<int> qi;
typedef long long ll;
const ll INF = 1e7, MAX_N = 99, MAX_M = 1000, MAX_W = 100, MAX_H = 100;

#define max_n 100000
int s[max_n];

int main() {
    //(void)scanf("%d",&)
    int n, x; cin >> n >> x;
    rep(i, n) { (void)scanf("%d", &s[i]);}

    int p;
    ll ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (s[i - 1] + s[i] > x) {
            p = s[i - 1] + s[i] - x;
            ans += p;
            if (p > s[i]) { s[i - 1] -= p - s[i]; s[i] = 0; continue; }
            s[i] -= p;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
