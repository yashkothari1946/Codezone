//priority Scheduling (Non preemptive)
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


void priority_sort(pcb process[],int priority[],int ready[],int upto){
    int i=0,j=0;
    int temp;
     for(j=1;j<upto;j++){
          if(priority[ready[0]] < priority[ready[j]]){
               temp = ready[0];
               ready[0] =ready[j];
               ready[j] =temp;
          }
          else if(priority[ready[0]] == priority[ready[j]]   &&    process[ready[0]].arr > process[ready[j]].arr){
               temp = ready[0];
               ready[0] =ready[j];
               ready[j] =temp;
          }
     }
    
}

void priority_non_preemptive(pcb process[],int priority[]){
   int i=0,j=0,time=0,task=0;
   int waiting[number]={0},completion[number]={0},tot[number]={0};
   int ready[number],move=0,all_arrived=0;
   while(task<number){
      move=0;
      for(j=0;j<number;j++){
          if(time >= process[j].arr && process[j].status==0)
          {ready[move]=j;move++;}
      }
      if(move>0){
            priority_sort(process,priority,ready,move);
            time += process[ready[0]].burst;
            process[ready[0]].status =1;
            waiting[ready[0]] = time - process[ready[0]].arr - process[ready[0]].burst;
            tot[ready[0]] = time - process[ready[0]].arr;
            completion[ready[0]] = time;
            task++;
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
   priority_non_preemptive(process,priority);
   return 0;
}
