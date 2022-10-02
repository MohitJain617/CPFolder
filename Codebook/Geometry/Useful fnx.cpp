ftype dot(point2d a, point2d b) {
return a.x * b.x + a.y * b.y;
}
ftype dot(point3d a, point3d b) {
return a.x * b.x + a.y * b.y + a.z * b.z;
}
point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y,
    	a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x);
}
ftype triple(point3d a, point3d b, point3d c) {
    return dot(a, cross(b, c));
}
ftype cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}
// line intersection:
point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) {
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}
// plane intersection:
point3d intersect(point3d a1, point3d n1, point3d a2, point3d n2, point3d a3, point3d n3) {
    point3d x(n1.x, n2.x, n3.x);
    point3d y(n1.y, n2.y, n3.y);
    point3d z(n1.z, n2.z, n3.z); 
    point3d d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
    return point3d(triple(d, y, z),
    triple(x, d, z),
    triple(x, y, d)) / triple(n1, n2, n3);
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

