const int max_n = 2 << 17 + 5;
int n;
int seg_tree[max_n];

//generate a segment tree bigger than _n_, initialize them of INT_MAX
void _init_(int _n_) {
	int x = 1;
	while (x < _n_) {
		x *= 2;
	}

	rep(i, x) seg_tree[i] = INT_MAX;
}

//update k-th element to x
void update(int k, int x) {
	k += n - 1; //There are n-1 intervals on the k-th element

	while (k > 0) {
		k = (k - 1) / 2;
		seg_tree[k] = min(seg_tree[2 * k + 1], seg_tree[2 * (k + 1)]);
	}
}

//Find the minimum value of the interval [a,b)
//k := the node number which is to return
//l,r := k-th node's interval range
int query(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l) return INT_MAX;
	if (a <= r && l <= b) return seg_tree[k];
    
	int value_1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
	int value_2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
	return min(value_1, value_2);
}
