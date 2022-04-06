#define _USE_MATH_DEFINES
#include <iostream>                         // cout, endl, cin
#include <cstdio>                           // printf, scanf
#include<cassert>
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

//other useful methods
void clear(std::queue<int>& q) //make queue empty
{
	std::queue<int> empty;
	std::swap(q, empty);
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) { //sort vector<pii>
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

//---------------------------------------------------
vector<ll> h, s;
int n;

bool ispos(ll tmp) {
	vector<ll> p;
	rep(i, n) {
		if (h[i] > tmp) return false;
		ll g = (tmp - h[i]) / s[i];
		p.push_back(g);
	}
	sort(p.begin(), p.end());
	
	bool ans = true;
	rep(i, n) {
		if (p[i] < i) {
			ans = false; break;
		}
	}
	return ans;
}

signed main() {
	/*
	int a = in<int>(); string b = in<string>(); char c = in<char>();
	double d = in<double>();
	(void)scanf("%d",&);
	(void)scanf("%d%d",& ,&);
	(void)scanf("%d%d%d", &, &, &);
	*/
	cin >> n;
	ll maxH = 0, maxS = 0;
	rep(i, n) {
		ll a, b; (void)scanf("%lld%lld", &a, &b);
		h.push_back(a); s.push_back(b);
		maxH = max(maxH, a); maxS = max(maxS, b);
	}

	ll right = (ll)n - 1;
	ll left = maxH + (ll)n * maxS + 1;
	ll opt = (left + right) / 2;
	while (left - right > 1) {
		opt = (left + right) / 2;
		if (ispos(opt)) {
			left = opt;
		}
		else {
			right = opt;
		}
	}

	cout << left << endl;



	return 0;
}
