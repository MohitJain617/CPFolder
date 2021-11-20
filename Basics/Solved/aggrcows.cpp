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

//optimize this
//cows*log(cows) ?
bool check(vector<int> & arr, int cows, int ans){
	int i = 0;
	int ctr=1;
	while(true){
		if(ctr >= cows) break;
		auto ptr = lower_bound(arr.begin()+i+1,arr.end(),arr[i]+ans); 
		if(ptr == arr.end()) break;
		int j = ptr-arr.begin();
		// for(j = i+1; j < arr.size(); j++){
		// 	if(arr[j] - arr[i] >= ans) break;
		// }
		i = j;
		ctr++;
	}
	return ctr >= cows;
}
int binarySearch(vector<int>& arr,int cows,int left, int right){
	int ans = -1;
	while(left <= right){
		int mid = left + (right - left)/2;
		if(check(arr,cows,mid) == true){
			ans = max(ans,mid);
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,cows;
		cin>>n>>cows;
		vector<int> arr(n);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		cout<<binarySearch(arr,cows,1,arr[n-1]-arr[0]);
		cout<<"\n";
	}

	return 0;
}