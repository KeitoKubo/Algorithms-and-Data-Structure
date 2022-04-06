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
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second > b.second;
	}
	else {
		return a.first > b.first;
	}
}

//---------------------------------------------------
int isused[52][52];
char maze[52][52];
int w[52][52];
int r, c;

int main() {
	//int a = in<int>(); string b = in<string>(); char c = in<char>();
	//double d = in<double>();
	//(void)scanf("%d",&);
	//(void)scanf("%d%d",& ,&);
	memset(isused, 0, sizeof(isused));
	memset(w, 0, sizeof(w));
	cin >> r >> c;
	int sx, sy, gx, gy;
	cin >> sy >> sx >> gy >> gx;
	char ch[52];
	repa(i, r) {
		(void)scanf("%s", ch);
		repa(j, c) {
			maze[i][j] = ch[j - 1];
		}
	}

	queue<pii> Q;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	isused[sx][sy] = 1;
	Q.push(make_pair(sx, sy));

	while (!Q.empty()) {
		pii p = Q.front(); (void)Q.pop();
		int x = p.first, y = p.second;
		rep(i, 4) {
			int xx = x + dx[i], yy = y + dy[i];
			if (maze[xx][yy] == '.' && isused[xx][yy] == 0 ) {
				w[xx][yy] = w[x][y] + 1;
				isused[xx][yy] = 1;
				Q.push(make_pair(xx, yy));
			}
		}
	}

	cout << w[gy][gx] << endl;
	return 0;
}