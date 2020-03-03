#include <bits/stdc++.h>
using namespace std;
#define Max 0x3f3f3f
int time[1001]={0};////////////////////////////////先用来存放个人用时，计算后用来存放结束时间 
int numWin, numLine, numCus, numQCus;//////////////分别表示：窗口数，线内长度，顾客数量，要求查询的顾客数量 
vector<queue<int> > allWindows(numWin+1);//////////用来存放每个窗口线内队伍的每个人的服务时间 
vector<int> counter(numWin+1);/////////////////////用来存放当前每队确定要消耗的时间 
void OutTime(int offTime){/////////////////////////输出结束时间 
   if(offTime==Max)
      cout<<"Sorry";
   else{
        int h =8+offTime/60;
        int s=offTime%60;
        printf("%02d:%02d", h, s);
   }
}
int main(){
   scanf("%d %d %d %d", &numWin, &numLine, &numCus, &numQCus);
   for(int i=1;i<=numCus;i++)
      scanf("%d", &time[i]);
   fill(counter.begin(),counter.end()+1,0);////////初始化计时器 
   ////////////////////////////////////////////////先按顺序放置线内队列 
   for(int i=1;i<=numWin*numLine;i++){
      allWindows[(i-1)%numWin+1].push(time[i]);////直接入各自窗口的队 
      if(counter[(i-1)%numWin+1]>=540){////////////如果计时器已经超时（服务开始时已经下班） 
          time[i]=Max;   				///////////就将此人的结束时间设为无穷大
          continue;
      }
      time[i]+=counter[(i-1)%numWin+1];///////////不超时，那就将结束时间更新为该队计时器时间（服务开始时间）加上服务预计消耗时间 
      counter[(i-1)%numWin+1]=time[i];////////////更新计时器 
   }
   for(int i=numWin*numLine+1;i<=numCus;i++){/////开始逐个放置线外顾客 
      int flag, min;
      flag=min=Max;
      for(int j=1;j<=numWin;j++)//////////////////先寻找每队对头中谁最小 
         if(allWindows[j].front()<min){///////////     （意味着，哪个队伍人数先减一） 
            min=allWindows[j].front();
            flag=j;///////////////////////////////做上标记 
         }
      if(counter[flag]>=540){/////////////////////如果该队计时器，也就是当前待入队顾客的等待时间超过营业时间 
         time[i]=Max;   //////////////////////////就将此人的结束时间设为无穷大，过一会直接输出Sorry 
         continue;
      }
      allWindows[flag].push(time[i]);/////////////时间来得及那就入队 
      for(int j=0;j<flag;j++)/////////////////////入队代表之前那个人服务时间已满 
         allWindows[j].front()-=allWindows[flag].front();
      for(int j=flag+1;j<=numWin;j++)/////////////相应的，其他队对头的剩余时间应该减去这段时间  
         allWindows[j].front()-=allWindows[flag].front();
      allWindows[flag].pop();/////////////////////此人离开 
      time[i]+=counter[flag];/////////////////////获得入队顾客预计离店时间 
      counter[flag]=time[i];//////////////////////更新该队计时器 
   }
   for(int i=0;i<numQCus;i++){
      int temp;
      scanf("%d", &temp);/////////////////////////读取序号 
      OutTime(time[temp]);////////////////////////根据序号输出离店时间 
      if(i<numQCus-1)   cout<<endl;
   }
   return 0;
}
