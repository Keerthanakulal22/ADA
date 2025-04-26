#include<stdio.h>
#define max_items 100
double ComputeMaxValue(double w,double weight[],double value[],double ratio[],int nitems){
double cW=0;
double cV=0;
printf("Items considered are:\n");
while(cW<w){
int item=getNextitem(weight,value,ratio,nitems);	
if(item==-1){
break;
}
printf("%d",item+1);
if(cW+weight[item]<=w){
cW+=weight[item];
cV+=value[item];
ratio[item]=0;
}
else{
cV+=(ratio[item]*(w-cW));
cW+=(w-cW);
break;
}}
return cV;
}
int getNextitem(double weight[],double value[],double ratio[],int nitems){
double highest=0;
int i;
int index=-1;
for( i=0;i<nitems;i++){
if(ratio[i]>highest){
highest=ratio[i];
index=i;
}
}
return index;
}
int main(){
int nitems,i;
double w,weight[max_items],value[max_items];
double ratio[max_items];
printf("Enter the no.of items : ");
scanf(" %d",&nitems);
printf("Enter the weight of the items\n");
for( i=0;i<nitems;i++){
scanf("%lf",&weight[i]);
}
printf("Enter the value/profitsof item:\n");
for( i=0;i<nitems;i++){
scanf("%lf",&value[i]);
}
for( i=0;i<nitems;i++){
ratio[i]=value[i]/weight[i];
}
printf("Enter the capacity of knapsack:");
scanf("%lf",&w);
printf("\n Then maximum value in a kanapsack capacity%.2f is : %.2f\n",w,ComputeMaxValue(w,weight,value,ratio,nitems));
return 0;
}