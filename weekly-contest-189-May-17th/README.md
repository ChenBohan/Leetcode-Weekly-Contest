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

### people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list

- [题目](https://leetcode-cn.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/)
- 思路
    - 使用 map<int, vector<int>> 按照元素数量排个序，按照元素从多到少进行包含比较，如果没有在其他集合内，就加入答案中
        - 集合元素数量最多的肯定在答案中（题目给出每个集合都是不同的）
        - 实际上只要将当前集合与已经再答案的集合中比较即可（因为在当前集合之前但没有被加入答案集合的集合是答案集合的子集）
- 工具
    - 可用`std::includes`检查一个集合是否包含另一个集合，两个集合都必须以 operator< 排序。
    - `c.rbegin()`返回一个逆序迭代器，它指向容器c的最后一个元素，`c.rend()`返回一个逆序迭代器，它指向容器c的第一个元素前面的位置
```cpp
for (auto it = indexLengthMap.rbegin(); it != indexLengthMap.rend(); it++) {
    for (auto i : it->second) {
        if (it != indexLengthMap.rbegin() && checkSubSet(favoriteCompanies, ans, i)) {
            continue;
        } else {
            ans.push_back(i);
        }
    }
}
```

### rearrange-words-in-a-sentence
- [题目](https://leetcode-cn.com/problems/rearrange-words-in-a-sentence/)
- 思路
    - 申请map, key为单词长度，value为string的vector放置对应的单词；
    - 依次拿出map中的单词
    - 首大小写处理，尾部空格处理。
- 工具
    - 利用map的key自动排序特性，将相同长度的单词，都放在它后面 
    - 将字母全转为小写：`text[0] = text[0] -('A' - 'a');`
    - 以空格为界分割句子为单词
```cpp
for (int i = 0; i <= textlen; i++) {
    if (text[i] == ' ' || i == textlen){
       lenStrMap[tmp.size()].push_back(tmp);
       tmp = "";
    } else {
        tmp += text[i];
    }
}
```
