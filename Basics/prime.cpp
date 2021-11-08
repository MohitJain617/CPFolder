#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <utility>
using namespace std;
typedef long long ll;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < b; i++)

vector<bool> sieve(int n){
	vector<bool> v(n+1,true);
	v[0]=v[1]=false;
	for(ll i = 2; i < n+1; i++){
		if(v[i] == true){
			//mark the other elements of sieve
			for(ll j = i*i; j < n+1; j+=i){
				v[j] = false;
			}
		}
	}
	return v;
}

//lowest prime factor for every number till n:
vector<int> lpf(int n){
	vector<int>v(n+1,INT_MAX);
	v[0]=v[1]=1;
	REP(i,0,n+1){
		if(v[i] == INT_MAX){
			v[i] = i; //prime number itself
			for(ll j=i*i; j < n+1; j+=i){
				v[j] = min(v[j],v[i]);
			}
		}
	}
	return v;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	
	vector<int> arr = lpf(n);
	cout<<"lpf :\n";
	int len = arr.size();
	REP(i,1,arr.size()){
		cout<<i<<" : "<<arr[i]<<"\n";
	}

	return 0;
}