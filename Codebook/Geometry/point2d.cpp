struct point2d {
    ll x, y;
    point2d() {}
    point2d(ll x, ll y): x(x), y(y) {}
point2d& operator+=(const point2d &t) {
    x += t.x; y += t.y;
    return *this;
}
point2d& operator-=(const point2d &t) {
    x -= t.x; y -= t.y;
    return *this;
}
point2d& operator*=(ll t) {
    x *= t; y *= t;
    return *this;
}
point2d& operator/=(ll t) {
    x /= t; y /= t;
    return *this;
}
point2d operator+(const point2d &t) const {
    return point2d(*this) += t;
}
point2d operator-(const point2d &t) const {
    return point2d(*this) -= t;
}
point2d operator*(ll t) const {
    return point2d(*this) *= t;
}
point2d operator/(ll t) const {
    return point2d(*this) /= t;
} 
long long cross(const point2d& p) const 
{ return x * p.y - y * p.x; }
long long cross(const point2d& a, const point2d& b) const 
{ return (a - *this).cross(b - *this); }
};
point2d operator*(ll a, point2d b) {
    return b * a;
}