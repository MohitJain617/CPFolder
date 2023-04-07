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
    int operator^(const point2d &t) const {
        return  x*t.y - y*t.x;  
    } 
    int operator|(const point2d &t) const {
        return  x*t.x + y*t.y;  
    } 
    bool operator<(const point2d&u)const {
        return (x<u.x) || (x==u.x && y<u.y);
    }
    int cross(const point2d &t1,const point2d &t2,const point2d &t3) const {
        return (t2-t1)^(t3-t1);
    }
    int dot(const point2d &t1,const point2d &t2,const point2d &t3) const {
        return (t2-t1)|(t3-t1);
    }
};
