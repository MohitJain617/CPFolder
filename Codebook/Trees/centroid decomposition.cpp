vvll tree;
//return distance between a and b
int dist(int a, int b){
	// return depth[a] + depth[b] - 2*depth[lca];
}
//find depth and parent
void dfs1(int v, int p, int d = 0){
	depth[v] = d;
	for(ll &nbr: tree[v])
	{if(nbr == p) continue; dfs1(nbr, v, d+1);}
}
vvll centroidTree; //actual tree
int croot; //centroid root
vector<bool> vis; //helper
vll cpar; vll sz;
//construct centroid tree
int markSizeOfUnvisited(int v, int p = -1){
	sz[v] = 1;
	for(int nbr: tree[v]){
		if(!vis[nbr] && nbr != p){
			sz[v] += markSizeOfUnvisited(nbr, v);
		}
	}
	return sz[v];
}
int findCentroid(int v, int p, int num){
	for(int nbr: tree[v]){
		if(!vis[nbr] && nbr != p && sz[nbr] > num/2){
			return findCentroid(nbr, v, num);
		}
	}
	return v;
} 
void constructCentroidTree(int v, int p){
	markSizeOfUnvisited(v, p);
	int cvex = findCentroid(v, p, sz[v]);
	if(p == -1) croot = cvex;
	else{
		cpar[cvex] = p;
		centroidTree[cvex].push_back(p);
		centroidTree[p].push_back(cvex);
	}
	vis[cvex] = true;
	for(int nbr: tree[cvex]){
		if(vis[nbr]) continue;
		constructCentroidTree(nbr, cvex); 
	}
}
vll opt;
int query(int vx){ int res = 1e8;
	for(int px = vx; px != -1; px = cpar[px]){
		res = min(res, (int)opt[px] + dist(px, vx));
	} return res;
}
void update(int vx){
	for(int px = vx; px != -1; px = cpar[px]){
		opt[px] = min((int)opt[px], dist(vx, px));
	}
}
void init(int n){
	tree.assign(n, vll(0));
	centroidTree.assign(n, vll(0));
	cpar.assign(n, -1); sz.assign(n, 0);
	vis.assign(n, false);
}
void solve(){
	int n, m; cin>>n>>m; init(n);
	for(int i = 0; i < n-1; i++){
		int u, v; cin>>u>>v; u--; v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	constructCentroidTree(0,-1); //constructs tree
	// other dfs stuff
	const int inf = 1e8;
	opt.clear(); opt.resize(n, inf);
	update(0); //color node 0 
	for(int i = 0; i < m; i++){
		int type; cin>>type; int vx; cin>>vx; vx--;
		if(type == 1) update(vx);
		else cout<<query(vx)<<"\n";
	}
}