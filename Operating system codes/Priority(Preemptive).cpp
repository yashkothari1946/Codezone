//priority Scheduling (Preemptive)
#include<bits/stdc++.h>
int number;
struct pcb{
   int pid,arr,burst;
   int status,priority;
};
typedef struct pcb pcb;

void print(pcb process[],int number,int waiting[],int tot[],int completion[]){
    int i=0;
    printf("\nProcess ID   Arrival   Burst  Priority   Waiting   Turn Around   Completion\n");
    for(i=0;i<number;i++){
      printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",process[i].pid,process[i].arr,process[i].burst,process[i].priority,waiting[i],tot[i],completion[i]);
    }printf("\n");
    double avgwait=0,avgtot=0;
   for(i=0;i<number;i++){
      avgwait+=waiting[i];
      avgtot+=tot[i];
   }
   avgwait = (double)avgwait/number;
   avgtot = (double)avgtot/number;
   printf("average waiting time : %lf \n average turn around time : %lf",avgwait,avgtot);
}

void priority_sort(int priority[],int ready[],int upto){
    int i=0,j=0;
    int temp;
    for(i=0;i<upto-1;i++){
       for(j=0;j<upto-i-1;j++){
            if(priority[ready[j]] < priority[ready[j+1]]){
                 temp = ready[j];
                 ready[j] =ready[j+1];
                 ready[j+1] =temp;
            }
            else if(priority[ready[j]] == priority[ready[j+1]]   &&    priority[ready[j]] > priority[ready[j+1]]){
                 temp = ready[j];
                 ready[j] =ready[j+1];
                 ready[j+1] =temp;
            }
       }
    }
}

void priority_preemptive(pcb process[],int priority[]){
   int i=0,j=0,time=0,task=0;
   int waiting[number]={0},completion[number]={0},tot[number]={0};
   int ready[number],move=0,all_arrived=0;
   int remaining[number];
   for(i=0;i<number;i++){
      remaining[i] = process[i].burst;
   }
   while(task<number){
      move=0;
      for(j=0;j<number;j++){
          if(time >= process[j].arr &&  remaining[j]!=0)
          {ready[move]=j;move++;}
      }
      if(time>=process[number-1].arr)
      all_arrived=1;

      if(move>0 && all_arrived==0){
         priority_sort(priority,ready,move);
         time++;
         process[ready[0]].status =1;
         remaining[ready[0]]--;
         if(remaining[ready[0]]==0){
             completion[ready[0]]=time;
             waiting[ready[0]]=time - process[ready[0]].burst-process[ready[0]].arr;
             tot[ready[0]]=time-process[ready[0]].arr;
             task++;
         }
        //  printf("\n");
        // printf("Process id    Arrival time     Burst time   Remaining time\n");
        // for(i=0;i<number;i++){
        // printf("%d\t\t%d\t\t%d\t\t%d\n",process[i].pid,process[i].arr,process[i].burst,remaining[i]);
        // }printf("***********************************************************************\n");
      }
      else if(move>0 && all_arrived==1){
         priority_sort(priority,ready,move);
         for(j=0;j<move;j++){
            time += remaining[ready[j]];
            remaining[ready[j]]=0;
            process[ready[j]].status =1;
            waiting[ready[j]] = time - process[ready[j]].arr - process[ready[j]].burst;
            tot[ready[j]] = time - process[ready[j]].arr;
            completion[ready[j]] = time;
            task++;
            //  printf("\n");
            // printf("Process id    Arrival time     Burst time   Remaining time\n");
            // for(i=0;i<number;i++){
            // printf("%d\t\t%d\t\t%d\t\t%d\n",process[i].pid,process[i].arr,process[i].burst,remaining[i]);
            // }printf("***********************************************************************\n");
         }
      }
      else
      time++;
   }
   print(process,number,waiting,tot,completion);
}

int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
   printf("Enter number of processes : ");
   scanf("%d",&number);
   int i=0;
   pcb process[number];
   for(i=0;i<number;i++){
      printf("Enter arrival time , process time and priority of process %d :",i);
      process[i].pid = i;
      process[i].status =0;
      scanf("%d",&process[i].arr);
      scanf("%d",&process[i].burst);
      scanf("%d",&process[i].priority);
   }
   int priority[number];
   for(i=0;i<number;i++){
       priority[i]=process[i].priority;
   }
   priority_preemptive(process,priority);
   return 0;
}