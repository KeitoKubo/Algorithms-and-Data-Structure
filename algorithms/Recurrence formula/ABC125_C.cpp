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
const int max_n = 100000;
int dp[max_n + 1];
int a[max_n + 1];
int L[max_n + 1], R[max_n + 1];
int n;
int gcd(int a, int b) {
	if (a % b == 0)return b;
	else return gcd(b, a % b);
}

int solve() {
	int ans = -infi;
	int x;
	for (int i = 1; i <= n; i++) {
		if (i == 1) { x = R[i + 1]; }
		else if (i == n) { x = L[i - 1]; }
		else {
			x = gcd(L[i - 1], R[i + 1]);
		}
		ans = max(ans, x);
	}
	return ans;
}
int main() {
	//int a = in<int>(); string b = in<string>(); char c = in<char>();
	//double d = in<double>();
	//(void)scanf("%d",&);
	cin >> n;
	repa(i, n) { (void)scanf("%d", &a[i]); }
	L[1] = a[1]; R[n] = a[n];
	for (int i = 2; i <= n; i++) {
		L[i] = gcd(L[i - 1], a[i]);
	}
	for (int i = n - 1; i >= 1; i--) {
		R[i] = gcd(R[i + 1], a[i]);
	}
	
	cout << solve() << endl;

	return 0;
}
