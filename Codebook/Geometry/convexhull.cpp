vector<pair<int,int>> vec;
vector<pair<int,int>> hull;
typedef pair<int,int> pi;
pi operator+(pi a,pi b) {
    return {a.first+b.first, a.second+b.second};
}
pi operator-(pi a,pi b) {
    return {a.first-b.first, a.second-b.second};
}
int operator&(pi a,pi b) {
    return a.first*b.first + a.second*b.second;
}
int operator*(pi a,pi b) {
    return a.first*b.second - a.second*b.first;
}
void solve()  
{
    int n;
    cin>>n;
    vec.clear();
    hull.clear();
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        vec.push_back({u,v});
    }
    sort(all(vec));
    for(int rep=0;rep<2;rep++) 
    {
        int lim=sz(hull);
        for(auto &p:vec) 
        {
            while(sz(hull)>=lim+2) 
            {
                auto a=hull.end()[-2];
                auto b=hull.end()[-1];
                if(((b-a)*(p-a)) <= 0) break;
                hull.pop_back();
            }
            hull.push_back(p);
        }
        hull.pop_back();
        reverse(all(vec));
    }
}
