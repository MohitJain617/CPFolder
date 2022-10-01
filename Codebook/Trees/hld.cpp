//import lca
//import segment tree
const int maxn = 200005;
vvll tree;
vvll par;
ll sz[maxn], pos[maxn], moola[maxn], depth[maxn];
ll heavy[maxn], chain[maxn];
int num = 0;
//assigns first parent, subtree size, heavy child and depth
int dfs(int curr, int p, int d = 0){
	par[curr][0] = p; sz[curr] = 1;
	depth[curr] = d;
	int maxchild = -1, msize = 0;
	for(auto &child: tree[curr]){
		if(child == p) continue;
		sz[curr] += dfs(child, curr, d+1);
		if(sz[child] > msize){
			maxchild = child; msize = sz[child];
		}
	}
	heavy[curr] = maxchild;
	return sz[curr];
}
//assign pos (in segtree), and chaintop
void decompose(int curr, int p, bool isheavy = false){
	pos[curr] = num++;
	if(isheavy == true) chain[curr] = chain[p];
	else chain[curr] = curr;
 
	if(heavy[curr] != -1){
		decompose(heavy[curr], curr, true);
	} 
	for(auto &child: tree[curr]){
		if(child == p || child == heavy[curr]) continue;
		decompose(child, curr, false);
	}
}
 
int query(Node* stree, int from, int p){
	int res = 0;
	while(chain[from] != chain[p]){
		int top = pos[chain[from]];
		int till = pos[from];
		res = max(stree->query(top, till+1), res);
		//jump to the above one
		from = chain[from];
		from = par[from][0];
	}
	int top = pos[p];
	int till = pos[from];
	res = max(res, stree->query(top, till+1));
	return res;
}
//call dfs(0,-1) then decompose(0,-1,false) 
//then query(node, child, lca), segtree is of size n (vertices)