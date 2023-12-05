#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int a[],int l,int h){
    int pivot=a[l];
    int i=l,j=h;
    do{

        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[i]>pivot);

        if(i<j)
        swap(&a[i],a[j]);

    }while(i<j);

    swap(&a[l],&A[j]);
    return j;
}

void quicksort(int a[],int l,int h){
    int j;
    while(l<h){
        
        j=partition(a,l,h);
        quicksort(a,l,j);
        qiucksort(a,j+1,h);
        
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i];
}


