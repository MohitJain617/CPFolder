#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <utility>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;
typedef vector<vector<bool>> vvb;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < b; i++)
#define DEB(a) cout<<#a<<" = "<<a<<"\n";

//---------------SEGTREE IMPLEMENTATION----------------

int left(int v) {return 2*v;}
int right(int v) {return 2*v + 1;}

template <typename T>
class SegTree {
public:
	int n;
	vector<T> val;
	vector<T> lazy;
	SegTree(int len, vector<T>& nums){
		n = len;
		val.assign(4*n + 1, 0);
		lazy.assign(4*n + 1, 0);
		build(nums, 1, 0,n-1);
	}
	//----Changeable functions----
	void update(int v){
		val[v] = min(val[left(v)]+lazy[left(v)], val[right(v)]+lazy[right(v)]);
	}
	void prop(int v){
		lazy[left(v)] += lazy[v];
		lazy[right(v)] += lazy[v];
		lazy[v] = 0;
	}
	//---------------------------
	void build(vector<T>& nums, int v, int l, int r){
		if(l == r){
			//base case
			val[v] = nums[l];
		} else {
			int mid = (l+r)/2;
			build(nums,left(v),l,mid);
			build(nums, right(v),mid+1,r);
			update(v);
		}
	}

	T query(int l, int r){
		return query(1,l,r,0,n-1);
	}
	T query(int v, int l, int r, int tl, int tr){
		if((tr < l) || (tl > r)){
			//no overlap
			return INT_MAX;
		}
		if((tl >= l) && (tr <= r)){
			//total overlap
			return val[v]+lazy[v];
		}

		prop(v);

		int mid = (tl + tr)/2;
		T leftVal = query(left(v),l,r,tl,mid);
		T rightVal = query(right(v),l,r,mid+1,tr);

		update(v);
		return min(leftVal,rightVal);
	}

	// increment
	void increment(int l, int r, T del){
		incre(1,del,l,r,0,n-1);
	}
	void incre(int v, T del, int l, int r, int tl, int tr){
		if((tr < l) || (tl > r)){
			//no overlap
			return;
		}
		if((tl >= l) && (tr <= r)){
			//total overlap
			lazy[v]+=del;
			return;
		}

		prop(v);
		int mid = (tl+tr)/2;
		incre(left(v),del,l,r,tl,mid);
		incre(right(v),del,l,r,mid+1,tr);
		update(v);

	}
};

// --------------------

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T = 1;
	while(T--){
		int n; cin>>n;
		vi arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		SegTree<int> seg(n,arr);
		int q; cin>>q;
		while(q--){
			int l,r; cin>>l>>r;
			l--; r--;
			int val = seg.query(l,r);
			cout<<val<<"\n";
		}
	}
	return 0;
}