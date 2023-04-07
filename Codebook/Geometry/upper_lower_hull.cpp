//this code gives combined upper and lower hull of a polygon, given points in random order(not necessarily CW/ACW)
//include operators overload from convex_hull.cpp
typedef pair<int,int> pi;
int cross(pi& a, pi& b, pi& c) { return (c-a)*(b-a); }
void solve()  
{
    int n;
    cin>>n;
    vector<pair<pi,int>> vec;
    vec.push_back({{-1,-1},-1}); //vector is 1-based index
    for(int i=0;i<n;i++) {
        int u,v; cin>>u>>v; vec.push_back({{u,v},0}); }
    sort(vec.begin()+1,vec.end()); int r=0;
    vector<pair<pi,int>> res((int)2e5+10);
    for(int i=1;i<=n;i++) {
        while(r>1 and cross(res[r-1].first,res[r].first,vec[i].first)>0) r--;
        res[++r]=vec[i];}
    int j=r;
    for(int i=n;i>=1;i--){
        while(r>j and cross(res[r-1].first,res[r].first,vec[i].first)>0) r--;
        res[++r]=vec[i]; } }
