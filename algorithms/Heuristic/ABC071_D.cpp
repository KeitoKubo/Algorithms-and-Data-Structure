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

//other useful methods
void clear(std::queue<int>& q) //make queue empty
{
	std::queue<int> empty;
	std::swap(q, empty);
}
bool compare_by_b(pair<int, int> a, pair<int, int> b) { //sort vector<pii>
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}

//---------------------------------------------------
const int max_n = 52;
char c[2][max_n + 1];
int used[max_n + 1];
int n;
vi v;
int main() {
	/*
	int a = in<int>(); string b = in<string>(); char c = in<char>();
	double d = in<double>();
	(void)scanf("%d",&);
	(void)scanf("%d%d",& ,&);
	*/
	memset(used, 0, sizeof(used));
	char ch;
	cin >> n;
	rep(i, n) { cin >> ch; c[0][i] = ch; }
	rep(i, n) { cin >> ch; c[1][i] = ch; }
	c[0][n] = '.';
	c[1][n] = '#';
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		if (c[0][i] != c[1][i]) {
			v.push_back(0); used[i + 1] = 1;
		}
		else {
			if (c[0][i + 1] != c[1][i + 1]) {
				v.push_back(2);
			}
			else { v.push_back(1); used[i + 1] = 1; }
		}
	}

	ll ans = 1;
	if (v[0] == 0) ans *= 6;
	else if (v[0] == 1) ans *= 6;
	else ans *= 3;

	for (int i = 1; i < v.size(); i++) {
		if (v[i] == 0) {
			if (v[i - 1] == 0) ans *= 3;
			else ans *= 2;
		}
		else if (v[i] == 1) {
			if (v[i - 1] == 0) ans *= 2;
			else ans *= 4;
		}
		else {
			if (v[i - 1] == 0) ans *= 1;
			else ans *= 2;
		}
		ans %= MOD;
	}
	cout << ans << endl;


	return 0;
}
