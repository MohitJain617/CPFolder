class DSU{ // 1 based
public:
	vector<ll> par, sz;
	ll maxSize; //size of the max componenet
	ll numc; //number of connected components
	DSU(ll n){
		par.assign(n+1,-1);
		sz.assign(n+1,1);
		for(int i = 1; i <= n; i++) par[i] = i;
		maxSize = 1; numc = n;
	}
	ll findRoot(ll node){
		if(par[node] == node) return node;
		return par[node] = findRoot(par[node]);
	}
	void merge(ll a, ll b){
		a = findRoot(a); b = findRoot(b);
		if(a != b){
			if(sz[a] < sz[b]) swap(a,b);
			par[b] = a;  sz[a] += sz[b];
			maxSize = max(maxSize,sz[a]); numc--;
		}
	}
};
