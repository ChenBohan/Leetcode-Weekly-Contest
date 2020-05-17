struct point{
    double x,y;
    point(double i,double j):x(i),y(j){}
};

//算两点距离
double dist(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

//计算圆心
point f(point& a,point& b,int r){
    //算中点
    point mid((a.x+b.x)/2.0,(a.y+b.y)/2.0);
    //AB距离的一半
    double d=dist(a.x,a.y,mid.x,mid.y);
    //计算h
    double h=sqrt(r*r-d*d);
    //计算垂线
    point ba(b.x-a.x,b.y-a.y);
    point hd(-ba.y,ba.x);
    double len=sqrt(hd.x*hd.x+hd.y*hd.y);
    hd.x/=len,hd.y/=len;
    hd.x*=h,hd.y*=h;
    return point(hd.x+mid.x,hd.y+mid.y);
}

class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int n=points.size();
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j){//一个点
                    continue;
                }else{//两个点
                    //通过长度判断有没有圆心
                    double d=dist(points[i][0],points[i][1],points[j][0],points[j][1]);
                    if(d/2>r) continue;

                    point a(points[i][0],points[i][1]),b(points[j][0],points[j][1]);
                    point res=f(a,b,r);
                    int cnt=0;
                    for(int k=0;k<n;k++){
                        double tmp=dist(res.x,res.y,points[k][0],points[k][1]);
                        if(tmp<=r) cnt++;
                    }
                    ans=max(cnt,ans);
                }
            }
        }
        return ans;
    }
};
