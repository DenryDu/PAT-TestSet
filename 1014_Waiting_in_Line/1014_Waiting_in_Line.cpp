#include <bits/stdc++.h>
using namespace std;
#define Max 0x3f3f3f
int time[1001]={0};////////////////////////////////��������Ÿ�����ʱ�������������Ž���ʱ�� 
int numWin, numLine, numCus, numQCus;//////////////�ֱ��ʾ�������������ڳ��ȣ��˿�������Ҫ���ѯ�Ĺ˿����� 
vector<queue<int> > allWindows(numWin+1);//////////�������ÿ���������ڶ����ÿ���˵ķ���ʱ�� 
vector<int> counter(numWin+1);/////////////////////������ŵ�ǰÿ��ȷ��Ҫ���ĵ�ʱ�� 
void OutTime(int offTime){/////////////////////////�������ʱ�� 
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
   fill(counter.begin(),counter.end()+1,0);////////��ʼ����ʱ�� 
   ////////////////////////////////////////////////�Ȱ�˳��������ڶ��� 
   for(int i=1;i<=numWin*numLine;i++){
      allWindows[(i-1)%numWin+1].push(time[i]);////ֱ������Դ��ڵĶ� 
      if(counter[(i-1)%numWin+1]>=540){////////////�����ʱ���Ѿ���ʱ������ʼʱ�Ѿ��°ࣩ 
          time[i]=Max;   				///////////�ͽ����˵Ľ���ʱ����Ϊ�����
          continue;
      }
      time[i]+=counter[(i-1)%numWin+1];///////////����ʱ���Ǿͽ�����ʱ�����Ϊ�öӼ�ʱ��ʱ�䣨����ʼʱ�䣩���Ϸ���Ԥ������ʱ�� 
      counter[(i-1)%numWin+1]=time[i];////////////���¼�ʱ�� 
   }
   for(int i=numWin*numLine+1;i<=numCus;i++){/////��ʼ�����������˿� 
      int flag, min;
      flag=min=Max;
      for(int j=1;j<=numWin;j++)//////////////////��Ѱ��ÿ�Ӷ�ͷ��˭��С 
         if(allWindows[j].front()<min){///////////     ����ζ�ţ��ĸ����������ȼ�һ�� 
            min=allWindows[j].front();
            flag=j;///////////////////////////////���ϱ�� 
         }
      if(counter[flag]>=540){/////////////////////����öӼ�ʱ����Ҳ���ǵ�ǰ����ӹ˿͵ĵȴ�ʱ�䳬��Ӫҵʱ�� 
         time[i]=Max;   //////////////////////////�ͽ����˵Ľ���ʱ����Ϊ����󣬹�һ��ֱ�����Sorry 
         continue;
      }
      allWindows[flag].push(time[i]);/////////////ʱ�����ü��Ǿ���� 
      for(int j=0;j<flag;j++)/////////////////////��Ӵ���֮ǰ�Ǹ��˷���ʱ������ 
         allWindows[j].front()-=allWindows[flag].front();
      for(int j=flag+1;j<=numWin;j++)/////////////��Ӧ�ģ������Ӷ�ͷ��ʣ��ʱ��Ӧ�ü�ȥ���ʱ��  
         allWindows[j].front()-=allWindows[flag].front();
      allWindows[flag].pop();/////////////////////�����뿪 
      time[i]+=counter[flag];/////////////////////�����ӹ˿�Ԥ�����ʱ�� 
      counter[flag]=time[i];//////////////////////���¸öӼ�ʱ�� 
   }
   for(int i=0;i<numQCus;i++){
      int temp;
      scanf("%d", &temp);/////////////////////////��ȡ��� 
      OutTime(time[temp]);////////////////////////�������������ʱ�� 
      if(i<numQCus-1)   cout<<endl;
   }
   return 0;
}
