// DSU with Rollback
vll par; vll sz;
vector<pll> hist; int cc = 0;
int findRoot(int v){
	while(par[v] != v) v = par[v]; return v;
}
void unite(int u, int v){
	u = findRoot(u); v = findRoot(v);
	if(u != v){
		cc--;
		if(sz[u] > sz[v]) swap(u, v);
		hist.push_back({~v, sz[v]}); sz[v] += sz[u];
		hist.push_back({u, par[u]}); par[u] = v;
	}}
void rollback(int save){
	while((int)hist.size() > save){
		int v = hist.back().first;
		int val = hist.back().second;
		hist.pop_back();
		if(v < 0){
			cc++; sz[~v] = val;
		} else {
			par[v] = val;
		}}}
int n, m, q; 
void init(){
	par.assign(n, 0);
	iota(par.begin(), par.end(), 0);
	sz.assign(n, 1);cc = n; }
vll answer;
void dnc(int l, int r, vector<ppll>& redge){
	vector<ppll> partialoverlap;
	int save = hist.size();
	for(auto &val: redge){
		int cl = val.first.first;
		int cr = val.first.second;
		int u = val.second.first;
		int v = val.second.second;
		if(cr <= l || cl > r){/*nothing*/}
		else if(cl <= l && r < cr){
			unite(u, v);
		} else {
		partialoverlap.push_back(val);
		}
	}
	if(l == r){
		//answer query:
		answer[l] = cc;
	} else {
		int mid = (l+r)/2;
		dnc(l, mid, partialoverlap); dnc(mid+1, r, partialoverlap);
	}
	rollback(save);
}
int main(){
	cin>>n>>m>>q; init();//initialize dsu
	vector<pair<pll, ll>> edgelist;
	//already existing edges
	for(int i = 0; i < m; i++){
		int u,v;cin>>u>>v;u--;v--;
		if(u > v) swap(u, v);
		edgelist.push_back({{u,v}, 0});
	}
	answer.assign(q+1, -1);
	// if u,v then remove else add edge 
	for(int i = 1; i <= q; i++){
		int u,v; cin>>u>>v; u--; v--;
		if(u > v) swap(u, v);
		edgelist.push_back({{u,v}, i});
	}
	sort(edgelist.begin(), edgelist.end());
	int esize = edgelist.size();
	vector<ppll> rangeedge;
	for(int i = 0; i < esize; i++){
		auto &val = edgelist[i];
		int u = val.first.first, v = val.first.second;
		int aq = val.second; int en;
		if(i+1>=esize || val.first != edgelist[i+1].first){
			en = q+1;
		} else {
			en = edgelist[i+1].second; i++;
		}
		rangeedge.push_back({{aq,en}, {u,v}});
	}
	dnc(0,q, rangeedge);
	for(int i = 0; i <= q; i++){
		cout<<answer[i]<<" "; //number of cc
	}}