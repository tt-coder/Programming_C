#include <cstdio>
#include <cmath>

struct Point{
    double x;
    double y;
};

void getPoint(int n, Point p1, Point p2){
    if(n == 0) return;
    Point a, b, c; // a,b:p1p2を3等分する点、c:s,tと正三角形を作る点
    double theta = M_PI * 60.0 / 180.0; // 60度
    a.x = (2.0 * p1.x + p2.x) / 3.0;
    a.y = (2.0 * p1.y + p2.y) / 3.0;
    b.x = (p1.x + 2.0 * p2.x) / 3.0;
    b.y = (p1.y + 2.0 * p2.y) / 3.0;
    c.x = (b.x - a.x) * cos(theta) - (b.y - a.y) * sin(theta) + a.x;
    c.y = (b.x - a.x) * sin(theta) + (b.y - a.y) * cos(theta) + a.y;
    getPoint(n-1, p1, a);
    printf("%.8f %.8f\n", a.x, a.y);
    getPoint(n-1, a, c);
    printf("%.8f %.8f\n", c.x, c.y);
    getPoint(n-1, c, b);
    printf("%.8f %.8f\n", b.x, b.y);
    getPoint(n-1, b, p2);
}

int main(){
    int n;
    Point p1,p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    scanf("%d",&n);
    printf("%.8f %.8f\n", p1.x, p1.y);
    getPoint(n, p1, p2);
    printf("%.8f %.8f\n", p2.x, p2.y);
    return 0;
}