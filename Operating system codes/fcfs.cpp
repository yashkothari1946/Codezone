#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int at[100],bt[100],entry=-1,num=0;
	while(entry==-1 ){
		cout<<"Enter arrival and burst time : "; 
	    if(cin>>at[num]>>bt[num]>>entry){
        num++;
        }
        else
        entry=0;
    }
    int temp;
    for(int i=0;i<num;i++){
    	for(int j=i+1;j<num;j++){
    		if(at[i]>at[j]){
    			temp=at[i];
    			at[i]=at[j];
    			at[j]=temp;
    			temp=bt[i];
    			bt[i]=bt[j];
    			bt[j]=temp;
    		}
    	}
    }
    int time=0,wt[num]={0},tot[num]={0},comt[num]={0};
    fill(wt,wt+num,-1);
    for(int i=0;i<num;i++){
    	time+=bt[i];
    	wt[i]=time-bt[i]-at[i];
    	tot[i]=time-at[i];
    	comt[i]=time;

    }
    printf("\nArrival\tBurst\tWaiting\tTurn Around\tCompletion\n");
    for(int i=0;i<num;i++){
    	printf("%d\t%d\t%d\t%d\t%d\n",at[i],bt[i],wt[i],tot[i],comt[i]);
    }

}

/*sample input
0 24  -1
2 3  -1
1 2  -1

sample output
Enter arrival and burst time : 
Enter arrival and burst time : 
Enter arrival and burst time : 
Arrival Burst   Waiting Turn Around Completion
0   24  0   24  24
1   2   23  25  26
2   3   24  27  29

*/