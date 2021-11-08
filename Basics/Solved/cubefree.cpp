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

const int n = 1000000;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	//sieve
	int arr[n+1] = {0};
	arr[0] = 0;
	arr[1] = 0;
	REP(i,2,120){
	    if(arr[i] == 0){
	        ll k = i*i*i;
	        if(k > n) break;
	        arr[k] = -1;
	        for(int j = k+k; j <=n; j+=k){
	            arr[j] = -1;
	        }
	    }
	}
	int k=1;
	for(int i = 1; i <= n; i++){
	    if(arr[i] == 0){
	        arr[i] = k++;
	    }
	}

	int T;
	cin>>T;
	int x = T;
	while(T--){
		int q;
		cin>>q;
		cout<<"Case "<<x-T<<": ";
		if(arr[q] == -1){
			cout<<"Not Cube Free";
		} else {
			cout<<arr[q];
		}
		cout<<"\n";
	}

	return 0;
}