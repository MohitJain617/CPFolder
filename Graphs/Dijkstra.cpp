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

#include <queue>
typedef vector<vector<pair<long long, long long>>> vvpll;
typedef vector<pair<ll,ll>> vpll;
vector<ll> dist;
vector<bool> vis;
//Single source shortest path algorithm
void dijkstra(vvpll& graph, ll start){
	int n = graph.size();
	vis.assign(n,false);
	dist.assign(n,1e18);
	//priority queue stores distance , current
	priority_queue<pair<ll,ll>,vpll,greater<pair<ll,ll>>> peq;
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
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T; cin>>T;
	while(T--){

	}
	return 0;
}