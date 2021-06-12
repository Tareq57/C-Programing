#include<stdio.h>
#include<math.h>
struct point{
    double x,y;
};
struct circle{
    double x,y,r;
};
struct rectangle{
    double x1,y1,x2,y2;
};
double area(struct rectangle r){
    return fabs(r.x1-r.x2)*fabs(r.y1-r.y2);
}
void inside(struct circle c, struct rectangle r){
    if((c.x-r.x1)*(c.x-r.x1)+(c.y-r.y1)*(c.y-r.y1)>c.r){
        printf("Not inside");
    }
    else if((c.x- r.x1)*(c.x-r.x1)+(c.y-r.y2)*(c.y-r.y2)>c.r){
        printf("Not inside");
    }
    else if((c.x-r.x2)*(c.x-r.x2)+(c.y-r.y1)*(c.y-r.y1)>c.r){
        printf("Not inside");
    }
    else if((c.x-r.x2)* (c.x-r.x2)+(c.y-r.y2)*(c.y-r.y2)>c.r){
        printf("Not inside");
    }
    else{
        printf("Inside");
    }
}
int main(){
    struct circle c;
    struct rectangle r;
    scanf("%lf %lf %lf", &c.x, &c.y, &c.r);
    scanf("%lf %lf %lf %lf", &r.x1, &r.y1, &r.x2, &r.y2);
    printf("Area of rectangle %lf\n", area(r));
    inside(c, r);
    return 0;
}
