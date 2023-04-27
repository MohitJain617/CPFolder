int leaf1 = -1;
    queue<int> bfs;
    bfs.push(1);
    vector<bool> vis(n+1, false);
    vis[1] = true;
    while(!bfs.empty()){
        int curr = bfs.front(); bfs.pop();
        leaf1 = curr;
        for(auto nbr: tree[curr]) if(!vis[nbr]){
            vis[nbr] = true;
            bfs.push(nbr);
        }
    }
    vis.assign(n+1, false);
    vis[leaf1] = true;
    bfs.push(leaf1);
    int leaf2 = -1;
    while(!bfs.empty()){
        int curr = bfs.front(); bfs.pop();
        leaf2 = curr;
        for(auto nbr: tree[curr]) if(!vis[nbr]){
            vis[nbr] = true;
            bfs.push(nbr);
        }
    }
