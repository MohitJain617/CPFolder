// line intersection:
point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}
//line segment intersection (a,b), (c,d):
int sgn(const long long& x) 
{ return x >= 0 ? x ? 1 : 0 : -1; }
bool inter1(ll a, ll b, ll c, ll d) {
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    return max(a, c) <= min(b, d);
}
bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (cross(a-c, d-c) == 0 && cross(b-c, d-c) == 0)
     return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(cross(b-a, c-a)) != sgn(cross(b-a, d-a)) &&
     sgn(cross(d-c, a-c)) != sgn(cross(d-c, b-c));
}

