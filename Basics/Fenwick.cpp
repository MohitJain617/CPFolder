#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i < b; i++)

class FenwickTree{
private:
	int size;
	vector<int> arr;
public:
	FenwickTree(int size, vector<int>& nums){
		//precomputation:
		this->size = size+1;
		for(int i = 0; i < size+1; i++){
			arr.push_back(0);
		}
		for(int i = 0; i <size; i++){
			update(i,nums[i]);
		}
	}

	void printTree(){
		for(auto i: arr){
			cout<<i<<" ";
		}
	}
	//update the index i given delta
	void update(int i, int delta){
		i+=1;
		while(i < size+1){
			arr[i] += delta;
			i += (i&(-i));
		}
	}
	//compute the prefix sum value [1 to i]
	int sumUpto(int i){
		int s = 0;
		i+=1; //indexing is one more than in original
		while(i > 0){
			s += arr[i];
			i -= i&(-i);
		}
		return s;
	}
	//compute the preffix sum value [i+1 to j]
	int rangeSum(int i, int j){
		return sumUpto(j)-sumUpto(i);
	}
};

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	FenwickTree ftree(n,v);
	ftree.printTree();
	int x = ftree.rangeSum(0,1);
	cout<<endl<<x<<endl;
	return 0;
}