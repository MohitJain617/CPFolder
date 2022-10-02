vector<ll> dist;
vector<bool> vis;
//Single source shortest path algorithm
void dijkstra(vvpll& graph, ll start){
	int n = graph.size();
	vis.assign(n,false);
	dist.assign(n,1e18);
	//priority queue stores distance , current
	priority_queue<pair<ll,ll>, vpll, greater<pair<ll,ll>>> peq;
	dist[start] = 0;
	vis[start] = 0;
	peq.push(MP(0,start));
	while(!peq.empty()){
		ll curr = peq.top().S;
		ll currdist = peq.top().F;
		peq.pop();
		if(vis[curr]) continue;
		vis[curr] = true;
		//update all the children
		for(auto cpx: graph[curr]){
			if(vis[cpx.F]) continue;
			ll newDist = currdist+cpx.S;
			//relaxation
			if(dist[cpx.F] > newDist){
			dist[cpx.F] = newDist;
			peq.push(MP(newDist, cpx.F));
			}
		}}}