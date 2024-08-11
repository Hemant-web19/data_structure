#include<stdio.h>
int main (){
int n ;
int b,i,j ,tem,num ;
int mid ,low,high;

int a[100];
printf("Enter the size of array");
scanf("%d",&n);
printf("enter the elements in the array ");
for(i=0;i<n;i++){
    scanf("%d/n",&a[i]);
    }


printf("Enter the sorting algo , 1 for selestion sort, 2 for bubble sort   ");
scanf("%d",b);
if (b=1){
for(i=0;i<n;i++){
    j=i+1;
   for (j=i+1;j<n;j++){
    if(a[j]<a[i]){
        tem=a[i];
        a[i]=a[j];
        a[j]=tem;
    }
   }
}
printf("sortey array is :");
for(i=0;i<n;i++){
    printf("%d ",a[i]);}
}
if (b=2){
   for(i=0;i<n;i++){
    //j=i+1;
    for(j=0;j<n-i;j++){
        if(a[j]<a[j++]){
        tem=a[j];
        a[j]=a[j++];
        a[j]=tem;}}
    printf("sortey array is :");
    for(i=0;i<n;i++){
    printf("%d ",a[i]);}
   
}
}
else {
    printf("incorrect input");
}

printf("Enter the element want to search using Binaray search");
scanf("%d",&num);
low=0;
high=n;
while (low<=high){
mid=(low+high)/2;
if(a[mid]==num){
    printf("the number is found ata a index %d",mid);

}
else{
    if(num<a[mid]){
        high=mid-1;
    }
    if(num>a[mid]){
        low=high+1;

    }
}
}








}