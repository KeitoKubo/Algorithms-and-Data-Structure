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
static const int max_n = 100000;
int n; string s;
int a[max_n + 1];

//sheep:0 wolf:1
bool solve(int x, int y) {
	a[1] = x; a[2] = y;
	for (int i = 2; i <= n - 1; i++) {
		if (a[i] == 0) {
			if (s[i - 1] == 'o') a[i + 1] = a[i - 1];
			else a[i + 1] = (a[i - 1] + 1) % 2;
		}
		else {
			if (s[i - 1] == 'x') a[i + 1] = a[i - 1];
			else a[i + 1] = (a[i - 1] + 1) % 2;
		}
	}
	//最後があっているかどうか
	bool ans = true;
	if (a[n - 1] == a[1]) {
		if (a[n] == 0) {
			if (s[n - 1] == 'o')ans = true;
			else ans = false;
		}
		else {
			if (s[n - 1] == 'x')ans = true;
			else ans = false;
		}
	}
	else {
		if (a[n] == 0) {
			if (s[n - 1] == 'x')ans = true;
			else ans = false;
		}
		else {
			if (s[n - 1] == 'o')ans = true;
			else ans = false;
		}
	}
	
	if (ans == false) return false;

	if (a[n] == a[2]) {
		if (a[1] == 0) {
			if (s[0] == 'o')ans = true;
			else ans = false;
		}
		else {
			if (s[0] == 'x')ans = true;
			else ans = false;
		}
	}
	else {
		if (a[1] == 0) {
			if (s[0] == 'x')ans = true;
			else ans = false;
		}
		else {
			if (s[0] == 'o')ans = true;
			else ans = false;
		}
	}
	return ans;
}



int main() {
    //(void)scanf("%d",&)
	cin >> n >> s;
	
	bool flag = false;
	for (int x = 0; x < 2; x++) {
		rep(y, 2) {
			if (solve(x, y)) {
				flag = true; goto EXIT;
			}
		}
	}
EXIT:
	if (!flag) {
		cout << -1 << endl; return 0;
	}
	repa(i, n) {
		if (a[i] == 0)cout << "S";
		else cout << "W";
	}
	cout << endl;

    return 0;
}
