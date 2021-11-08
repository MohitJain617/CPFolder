#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <utility>
#include <climits>
using namespace std;
typedef long long ll;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < b; i++)


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//precomputation
	//-------------------
	const int n = 100000;
	vector<vector<int>> pre;
	for(int i = 0; i < 10; i++){
		vector<int> v;
		pre.PB(v);
	}
	vector<bool> isNosq(n+1,true);
	for(int i = 2; i < 320; i++){
		int k = i*i;
		if(k > n) break;
		else {
			for(int j = k; j <= n; j+=k){
				isNosq[j] = false;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(isNosq[i] == true){
			//store this into 10 different arrays for each digit
			int temp = i;
			while(temp != 0){
				int digit = temp%10;
				int len = pre[digit].size();
				if((len == 0) || (pre[digit][len-1] != i)) pre[digit].PB(i);
				temp = temp/10;
			}
		}
	}
	//-----------------------
	//precomputation over

	int T;
	cin>>T;
	while(T--){
		int a,b,d;
		cin>>a>>b>>d;
		auto start = lower_bound(pre[d].begin(), pre[d].end(),a);
		auto end = upper_bound(pre[d].begin(),pre[d].end(),b);
		int ans = (end - start);
		cout<<ans<<"\n";
	}

	return 0;
}