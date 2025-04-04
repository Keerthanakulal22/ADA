#include<stdio.h>
#define MAX_ITEMS 10
int knapSack(int W,int wt[],int val[],int n){
int i,j;
int v[MAX_ITEMS+1][W+1];
for(i=0;i<=n;i++){
for(j=0;j<=W;j++){
if(i==0 || j==0){
v[i][j]=0;
}
else if(j-wt[i]<0){
v[i][j]=v[i-1][j];
}
else{
v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-wt[i]]);
}}}
return v[n][W];
}
int max(int a,int b){
return(a>b)?a:b;
} 
void main(){
int W,n,i;
printf("Enter the no. of value : ");
scanf("%d",&n);
int val[n],wt[n];
printf("Enter the maximum weight : ");
scanf("%d",&W);
printf("Enter the weight : ");
for(i=1;i<=n;i++){
scanf("%d",&wt[i]);
}
printf("Enter the value : ");
for(i=1;i<=n;i++){
scanf("%d",&val[i]);
}
int maxprofit=knapSack(W,wt,val,n);
printf("The maximum profit is %d : ",maxprofit);
}
