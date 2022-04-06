#define _USE_MATH_DEFINES
#include <iostream>                         // cout, endl, cin
#include <cstdio>                           // printf, scanf
#include <string>                           // string, to_string, stoi
#include <algorithm>                        // min, max, swap, lower_bound, upper_bound
// & stable_sort, sort, reverse
#include <cmath>                            //sin(rad),cos,tan, abs, pow, sqrt, cbrt,  exp, log, log10, log2
#include <utility>                          // pair, make_pair
#include <map>                              // map
#include <set>                              // set
#include <vector>                           // vector
#include <queue>                            // queue, priority_queue
#include <stack>                            // stack
#include <list>                             // list
#include <deque>                            // deque
#include <iomanip>
#include <numeric>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<string, bool> msb;
typedef priority_queue<int> pqi;
typedef stack<int> sti;
typedef queue<int> qi;

#define infi 1147483647
#define infl 9223372036854775806
#define MOD  1000000007
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define repa(i,n) for(int i=1;i<=(int)n;i++)
#define irep(i,n) for(int i=(int)n-1;i>=0;i--)

using std::cin;
using std::string;

template <typename T>
T in() {
	T temp; cin >> temp; return temp;
}

template <>
int in() {
	int temp; (void)scanf("%d", &temp); return temp;
}
template <>
double in() {
	double temp; (void)scanf("%lf", &temp); return temp;
}
template <>
char in() {
	char temp; (void)scanf("%c", &temp); return temp;
}

template<typename T1, typename T2>
constexpr auto equals(T1 a, T2 b) { return (fabs(a - b) < EPS); }

//その他便利なメソッド
void clear(std::queue<int>& q)
{
	std::queue<int> empty;
	std::swap(q, empty);
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

//---------------------------------------------------
int n;
ll k;
vector<ll> v;

int main() {
    //(void)scanf("%d",&)
	cin >> n >> k;
	ll maxi = infi;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		ll x; (void)scanf("%lld", &x); v.push_back(x); maxi = min(maxi, x); if (x == (ll)0) flag = true;
	}
	if (flag) { cout << n << endl; return 0; }
	if (maxi > k) { cout << 0 << endl; return 0; }

	ll cur = 1;
	int s = 0, t = 0;
	int ans = -1;
	//最初のsを決定,tを決定
	rep(i, n) { if (v[i] < k) { s = i; break; } }
	for (int i = s; i < n; i++) {
		if (cur * v[i] > k) {
			t = i - 1; break;
		}
		cur *= v[i];
	}
	ans = t - s + 1;

	for (int i = t + 1; i < n; i++) {
		cur *= v[i];
		while (cur > k) {
			cur /= v[s++];
		}
		ans = max(ans, i - s + 1);
	}
	cout << ans << endl;




    return 0;
}
