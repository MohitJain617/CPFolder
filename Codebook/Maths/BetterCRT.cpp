int normalize(int x,int m) {
    x %= m; if(x<0) x+= m; return x;
}
// add gcd(a,b,x,y) extended
// x = a[0] mod n[0], a[1] mod n[1] ... works for non coprime n.
pair<int, int> CRT(vector<int>& a, vector<int>& n)
{
    int len = a.size();
    for(int i = 0; i < len; i++)
    {
        a[i] = normalize(a[i],n[i]);
    }
    int ans = a[0];
    int lcm = n[0];
    for(int i = 1; i < len; i++){
        int x1,y1;
        int d = gcd(lcm, n[i], x1, y1);
        if((a[i]-ans)%d != 0) 
        {
            return {-1,-1};
        }
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lcm, lcm * n[i]/d);
        lcm = (lcm*n[i])/__gcd(lcm, n[i]);
    }
    return {ans,lcm};
}
