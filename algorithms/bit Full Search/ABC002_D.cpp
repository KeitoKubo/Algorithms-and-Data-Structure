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

#define infi 2147483647
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

//---------------------------------------------------
int r[13][13];
int n, m;

int main() {
	//int a = in<int>(); string b = in<string>(); char c = in<char>();
	//double d = in<double>();
	//(void)scanf("%d",&);
	memset(r, 0, sizeof(r));
	int n, m; cin >> n >> m;
	int x, y;
	rep(i, m) {
		(void)scanf("%d%d", &x, &y);
		r[x][y] = r[y][x] = 1;
	}
	
	vi v;
	int count;
	int ans = 1;
	for (int i = 0; i < (int)pow(2, n); i++) {
		int p = i;
		count = 0;
		v.clear();
		for (int j = n - 1; j >= 0; j--) {
			if (p >= (int)pow(2, j)) {
				v.push_back(j + 1); p %= (int)pow(2, j); count++;
			}
		}
		if (count < 2) continue;
		bool flag = true;
		for (int a = 0; a < v.size() - 1; a++) {
			for (int b = a + 1; b < v.size(); b++) {
				if (r[v[a]][v[b]] == 0) {
					flag = false; goto EXIT;
				}
			}
		}
	EXIT:
		if (flag) ans = max(ans, count);
	}
	cout << ans << endl;


	return 0;
}