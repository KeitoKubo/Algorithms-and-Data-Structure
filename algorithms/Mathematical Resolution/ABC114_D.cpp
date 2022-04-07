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
/*
約数75=3*5*5個持つ→素因数分解した時の組が(74)(2,24)(4,14)(2,4,4)のいずれか

*/
const int max_n = 100;
bool isprime[max_n + 1];
int prime_count[max_n + 1];
int n;

void primer() {
	repa(i, n) { isprime[i] = true; }
	for (int i = 2; i * i <= n; i++) {
		if (isprime[i]) {
			for (int j = i * 2; j <= n; j += i) {
				isprime[j] = false;
			}
		}
	}
}
int solve() {
	repa(i, n) prime_count[i] = 0;
	primer();
	for (int i = 2; i <= n; i++) {
		int x = i;
		for (int j = 2; j <= n; j++) {
			if (x == 1) break;
			if (isprime[j] && x % j == 0) {
				while (x % j == 0) {
					x /= j; prime_count[j]++;
				}
			}
		}
	}
	vi v[5]; //2,4,14,24,74
	for (int i = 2; i <= n; i++) {
		if (!isprime[i]) continue;
		if (prime_count[i] >= 74) v[4].push_back(i);
		if (prime_count[i] >= 24) v[3].push_back(i);
		if (prime_count[i] >= 14) v[2].push_back(i);
		if (prime_count[i] >= 4) v[1].push_back(i);
		if (prime_count[i] >= 2) v[0].push_back(i);
	}

	int ans = 0;
	ans += v[4].size();
	rep(i, v[3].size()) {
		rep(j, v[0].size()) {
			if (v[3][i] != v[0][j]) ans++;
		}
	}
	rep(i, v[1].size()) {
		rep(j, v[2].size()) {
			if (v[1][i] != v[2][j]) ans++;
		}
	}
	for (int i = 0; i < v[0].size();i++) {
		for (int j = 0; j < v[1].size(); j++) {
			for (int k = j + 1; k < v[1].size(); k++) {
				if (v[0][i] != v[1][j] && v[0][i] != v[1][k]) ans++;
			}
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
	cout << solve() << endl;




	return 0;
}
