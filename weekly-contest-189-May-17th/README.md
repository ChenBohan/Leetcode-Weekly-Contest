# Leetcode-Weekly-Contest
Weekly Contest Problems on Leetcode 

### maximum-number-of-darts-inside-of-a-circular-dartboard

- [题目](https://leetcode-cn.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/)
- 思路
    - 本题就是要计算给定半径，圆心不定，然后算圆内的点数最多是多少。我们可以通过两点确定一个圆心，穷举所有的圆心即可。
- 用向量求圆心
    - 向量a+向量b=向量c
    - 向量a是两点的中点坐标，向量b是AB垂线的单位方向向量乘以高度h，向量c是圆心坐标
```cpp
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
    //化为单位向量
    hd.x/=len,hd.y/=len;
    //再乘以长度h
    hd.x*=h,hd.y*=h;
    return point(hd.x+mid.x,hd.y+mid.y);
}
```
