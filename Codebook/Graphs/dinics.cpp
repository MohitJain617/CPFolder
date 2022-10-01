struct Dinics{
	struct Edge{
		int to, revidx;
		ll cap, ocap;
		Edge(int to, int revidx, ll cap, ll ocap):to(to), revidx(revidx), cap(cap), ocap(ocap){}
		Edge(){}
		ll flow(){
			return max(ocap - cap, 0ll);
		}
	};
	vector<vector<Edge>> adj;
	vector<int> level;
	vector<int> next;
	int n;
	Dinics(int n):n(n){
		level.assign(n, 0), next.assign(n,0);
		adj.assign(n, vector<Edge>(0));
	}
	void addEdge(int u, int v, ll cap, ll rev = 0){
		adj[u].push_back(Edge(v, adj[v].size(), cap, cap));
		adj[v].push_back(Edge(u, adj[u].size() - 1, rev, rev));
	}
	ll dfs(int curr, int t, ll flow){
		// cout<<curr<<" "<<t<<" "<<flow<<"\n";
		if(curr == t || !flow) return flow;
		for(int& i = next[curr]; i < adj[curr].size(); i++){
			Edge &edge = adj[curr][i];
			if(level[edge.to] != level[curr]+1) continue; 
			ll actualflow;
			actualflow = dfs(edge.to, t, min(flow, edge.cap));
			if(actualflow){
				edge.cap -= actualflow; 
				adj[edge.to][edge.revidx].cap += actualflow;		
				return actualflow;
			}
		}
		return 0;
	}
	ll calc(int src, int t){
		ll flow = 0;
		const ll inf = 1e16;
		//capacity scaling
		for(int L = 30; L >= 0; L--){
			do{
				level.assign(n, 0);
				next.assign(n, 0);
				//level assignment
				queue<int> q;
				level[src] = 1;
				q.push(src);
				while(!q.empty() && !level[t]){
					int curr = q.front(); q.pop();
					for(int i = 0; i < adj[curr].size(); i++){
						Edge &e = adj[curr][i];
						if(!level[e.to] && (e.cap >> L)){
							level[e.to] = level[curr] + 1;
							q.push(e.to);
						}
					}
				}
				//flows
				ll curflow;
				while(curflow = dfs(src, t, inf)) flow += curflow;
			} while(level[t] != 0);
		}
		return flow;
	}
};