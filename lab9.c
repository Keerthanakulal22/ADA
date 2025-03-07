#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
int k,t,n,i,j;
printf("Enter the no.of elements :");
scanf("%d",&n);
int a[n];
//printf("Enter the array elements :");
srand(time(NULL));
for(i=0;i<n;i++){
a[i]=rand()%5000;
}
clock_t start=clock();
for(i=0;i<n;i++){
j=i;
for(k=i+1;k<n;k++){
if(a[k]<a[j])
j=k;
}
t=a[i];
a[i]=a[j];
a[j]=t;
}
clock_t end=clock();
double Timetaken=((double)(end-start))/CLOCKS_PER_SEC;
printf("The time taken is %f:",Timetaken);
//printf("The sorted array is :");
//for(i=0;i<n;i++)
//printf("%d ",a[i]);
}