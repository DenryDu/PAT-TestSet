#include <bits/stdc++.h>
using namespace std;
#define Max 0x3f3f3f
void OutTime(int offTime){
   if(offTime==Max)
        cout<<"Sorry";
   else{
        int h=8+offTime/60;
        int s=offTime%60;
        printf("%02d:%02d", h, s);
   }
}
int main(){
   int numWin, numLine, numCus, numQCus;
   scanf("%d %d %d %d", &numWin, &numLine, &numCus, &numQCus);
   int time[1001]={0};
   for(int i=1;i<=numCus;i++)
       scanf("%d", &time[i]);
   vector<queue<int> > allWindows(numWin+1);
   vector<int> counter(numWin+1);
   fill(counter.begin(),counter.end()+1,0);
   for(int i=1;i<=numWin*numLine;i++){
       allWindows[(i-1)%numWin+1].push(time[i]);
       if(counter[(i-1)%numWin+1]>=540){
           time[i]=Max;   
           continue;
       }
       time[i]+=counter[(i-1)%numWin+1];
       counter[(i-1)%numWin+1]=time[i];
   }
   for(int i=numWin*numLine+1;i<=numCus;i++){
       int flag, min;
       flag=min=Max;
       for(int j=1;j<=numWin;j++)
           if(allWindows[j].front()<min){
               min=allWindows[j].front();
               flag=j;
           }
       if(counter[flag]>=540){
           time[i]=Max;   
           continue;
       }
       allWindows[flag].push(time[i]);
       for(int j=0;j<flag;j++)         allWindows[j].front()-=allWindows[flag].front();
       for(int j=flag+1;j<=numWin;j++)         allWindows[j].front()-=allWindows[flag].front();
       allWindows[flag].pop();
       time[i]+=counter[flag];
       counter[flag]=time[i];
   }
   for(int i=0;i<numQCus;i++){
       int temp;
       scanf("%d", &temp);
       OutTime(time[temp]);
       if(i<numQCus-1)   cout<<endl;
   }
   return 0;
}
