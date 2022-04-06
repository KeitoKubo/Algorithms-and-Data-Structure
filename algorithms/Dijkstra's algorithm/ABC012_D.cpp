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
#include <climits>

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
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	else {
		return a.first > b.first;
	}
}

//---------------------------------------------------
const int max_n = 300;
const int WHITE = -1;
const int GRAY = 0;
const int BLACK = 1;
int e[max_n + 1][max_n + 1];
int maxi[max_n + 1]; //i番目をstartにした時の最長時間
int n, m;
int colors[max_n + 1];//if visited
int dp[max_n + 1];

int longest(int s) {
	memset(colors, WHITE, sizeof(colors));
	repa(i, n) dp[i] = infi;
	dp[s] = 0;
	
	while (1) {
		int u = -1;
		int mincost = infi;
		repa(i, n) {
			if (mincost > dp[i] && colors[i] != BLACK) {
				u = i;
				mincost = dp[i];
			}
		}
		if (u == -1) break;
		colors[u] = BLACK;
		repa(i, n) {
			if (colors[i] != BLACK && e[u][i]!=infi) {
				if (dp[i] > dp[u] + e[u][i]) {
					dp[i] = dp[u] + e[u][i];
					colors[i] = GRAY;
				}
			}
		}
	}
	int ans = -1;
	repa(i, n) {
		ans = max(ans, dp[i]);
	}

	return ans;
}

int main() {
	//int a = in<int>(); string b = in<string>(); char c = in<char>();
	//double d = in<double>();
	//(void)scanf("%d",&);
	//(void)scanf("%d%d",& ,&);
	cin >> n >> m;
	repa(i, n) { repa(j, n) { e[i][j] = infi; } }
	int x, y, t;
	rep(i, m) {
		(void)scanf("%d%d%d", &x, &y, &t);
		e[x][y] = e[y][x] = t;
	}

	int ans = infi;
	repa(i, n) {
		ans = min(ans, longest(i));
	}
	cout << ans << endl;

	return 0;
}
