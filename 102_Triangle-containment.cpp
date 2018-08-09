#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define X first
#define Y second

using namespace std;

const double EPSILON = 0.00001;
const double ZERO    = 0.00000;

typedef pair<double, double> Point;

bool ContainsOrigin(Point a, Point b, Point c)
{        
    double s = a.Y * c.X - a.X * c.Y + (c.Y - a.Y) * ZERO + (a.X - c.X) * ZERO;
    double t = a.X * b.Y - a.Y * b.X + (a.Y - b.Y) * ZERO + (b.X - a.X) * ZERO;
    
    if((s < ZERO) != (t < ZERO)) return false;
    
    double A = -b.Y * c.X + a.Y * (c.X - b.X) + a.X * (b.Y - c.Y) + b.X * c.Y;
    
    if(A < ZERO)
    {
        s = -s;
        t = -t;
        A = -A;
    }
    return ((s + EPSILON > ZERO) && (t + EPSILON > ZERO) && ((s + t) <= A));
}

int main() 
{
    int N;
    cin >> N;
    
    int ans = 0;
    
    Point origin = {ZERO, ZERO};
    
    for(int i=0; i<N; i++)
    {
        Point a, b, c;
        
        cin >> a.X >> a.Y
            >> b.X >> b.Y 
            >> c.X >> c.Y;
                
        if((a.X == ZERO && b.X == ZERO) || (b.X == ZERO && c.X == ZERO) || (a.X == ZERO && c.X == ZERO)
        || (a.Y == ZERO && b.Y == ZERO) || (b.Y == ZERO && c.Y == ZERO) || (a.Y == ZERO && c.Y == ZERO))
        {
            ans++;
            continue;
        }
        if(ContainsOrigin(a, b, c)) ans++;        
    }
    cout << ans;
    
    return 0;
}
