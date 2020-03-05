#include <bits/stdc++.h>
using namespace std;
int winNum, cusNum;
double total=0.0;
typedef struct Time{
    int hour;
    int min;
    int sec;
    Time(int h, int m, int s): hour(h), min(m), sec(s){}
    Time& operator =(const Time &t){
        this->hour=t.hour;
        this->min=t.min;
        this->sec=t.sec;
        return *this;
    }
    bool operator <(const Time &t){
        if(this->hour!=t.hour)  return this->hour<t.hour;
        else if(this->min!=this->min)   return this->min<t.hour;
        else return this->sec<t.sec;
    }
}Time;
typedef struct record{
    Time t;
    int pro_t;
}record;
bool cmp(const record &a, const record &b){
        if(a.t.hour!=b.t.hour) return (a.t.hour<b.t.hour);
        else if(a.t.min!=b.t.min)   return (a.t.min<b.t.min);
        else    return (a.t.sec<b.t.sec);
}
double subtrac(const Time &t1, const Time &t2){
    double cnt=0.0;
    cnt+=t1.sec-t2.sec;
    cnt+=(t1.min-t2.min)*60;
    cnt+=(t1.hour-t2.hour)*60*60;
    return cnt;
}
Time join_t(const record &rc){
    Time rst(rc.t.hour, rc.t.min, rc.t.sec);
    rst.min+=rc.pro_t%60;
    rst.hour+=rc.pro_t/60;
    return rst;
}
vector< record > que;
vector< Time > win;
int main(){
    cin>>cusNum>>winNum;
    for(int i=0;i<winNum;i++){
        Time temp(8,0,0);
        win.push_back(temp);
    }
    for(int i=0;i<cusNum;i++){
        record temp;
        scanf("%d:%d:%d %d", &temp.t.hour, &temp.t.min, &temp.t.sec, &temp.pro_t);
        if((temp.t.hour>17)||(temp.t.hour==17&&temp.t.min!=0))  
            continue;
        que.push_back(temp);
    }
    sort(que.begin(), que.end(), cmp);
    for(int i=0;i<que.size();i++){
        int flag=-1;
        Time temp(80,0,0);
        for(int j=0;j<win.size();j++){
           if(win[j]<temp){
               temp=win[j];
               flag=i;
           }
        }
        if(que[i].t<win[flag]){
          total+=subtrac(win[flag],que[i].t);
          win[flag]=join_t(que[i]);
        }
    }
    total/=cusNum;
    total=(int)(total/60)+((int)total%60)/60;
    printf("%.1f", total);
    return 0;
}
