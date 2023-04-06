vector<int> ansval(maxn, 0);
map<int, int> nmaps[maxn];
 
void dfs2(int curr, int par){
	map<int, int> &currmap = nmaps[curr];
	int bestans = 0;
	for(int child: tree[curr]) if(child != par){
		dfs2(child, curr);
		auto &cmap = nmaps[child];
		bestans = max(bestans, ansval[child]);
		
		if(cmap.size() > currmap.size()){
			swap(cmap, currmap);
		}
		// merge cmap to currmap
		for(auto temp: cmap){
			currmap[temp.first] += temp.second;
			if(currmap[temp.first] > 1){
				bestans = max(bestans, temp.first);
			}
		}
	}
	currmap[colors[curr]]++;
	if(currmap[colors[curr]] > 1) bestans = max(bestans, colors[curr]);
	ansval[curr] = bestans;
	
	if(par != -1 && bestans != 0){
		ans[minmax(curr, par)] = max(ans[minmax(curr, par)], bestans);
	}
}
