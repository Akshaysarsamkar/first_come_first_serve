#include<stdio.h>

//waiting time function
void findwaitime(int process[],int n,int bt[],int wt[])
{
   wt[0]=0;
   
   for(int i=1;i<n;i++)
     wt[i] = bt[i-1] + wt[i-1];
  
}


void findtat(int process[],int n,int bt[],int wt[],int tat[])
{

  for(int i=0;i<n;i++)
    tat[i] = bt[i] + wt[i];

}

void calavgtime(int process[],int n,int bt[])
{
  
   int wt[n],tat[n],total_wt=0,total_tat=0;
   
   findwaitime(process,n,bt,wt);

   findtat(process,n,bt,wt,tat);

   printf("process brust time waiting time tat \n");
   
   for(int i=0;i<n;i++)
   {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      printf("%d\t",(i+1));
      printf("%d\t",bt[i]);
      printf("%d\t",wt[i]);
      printf("%d\n",tat[i]);   
   }
   
   float s =(float)total_wt / (float)n;
   float t =(float)total_tat/ (float)n;
   printf("avg waiting time:%f",s);
   printf("\n");
    printf("avg turnaround time time:%f",t);
    }
    
    int main()
    {
          int process[] = {1,2,3,4,5,6};
          int n = sizeof(process)/sizeof process[0];
          
          int brusttime[] ={9,3,2,4,3,2};
          
          calavgtime(process,n,brusttime);
          return 0;
    }
