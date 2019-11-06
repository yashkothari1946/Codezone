#include<bits/stdc++.h>
using namespace std;
int siz;
void display(int arr[]){
  for(int i=0;i<siz;i++){
    cout<<arr[i]<<" ";
  }cout<<"\n";
}

void bubble(int arr[]){
  for(int i=0;i<siz-1;i++){
    for(int j=i+1;j<siz;j++){
      if(arr[i]>arr[j]){
        swap(arr[i],arr[j]);
      }
    }
  }
}
void selection(int arr[]){
  int minn;
  for(int i=0;i<siz-1;i++){
    minn=i;
    for(int j=i+1;j<siz;j++){
      if(arr[j]<arr[minn]){
        minn=j;
      }
    }
    swap(arr[i],arr[minn]);
  }
}
void insertion(int arr[]){
  int j;
  for(int i=0;i<siz;i++){
    int el=arr[i];
    j=i-1;
    for(j=i-1;arr[j]>el && j>=0;j--){
      arr[j+1]=arr[j];
    }
    arr[j+1]=el;
  }
}

void merge(int arr[],int l,int m,int r){
  int i=0,j=0,k;
  int n1=m-l+1,n2=r-m;
  int L1[n1],L2[n2];
  while(i<n1){
    L1[i]=arr[i+l];
    i++;
  }
  while(j<n2){
    L2[j]=arr[m+1+j];
    j++;
  }
  i=0;j=0;k=l;
  while(i<n1 && j<n2){
    if(L1[i]<L2[j]){
      arr[k]=L1[i];i++;
    }else{
      arr[k]=L2[j];j++;
    }
    k++;
  }
  while(i<n1){
    arr[k]=L1[i];i++;k++;
  }
  while(j<n2){
    arr[k]=L2[j];j++;k++;
  }
}
void mergesort(int arr[],int l,int r){
  if(r>l){
    int m=(l+r)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}

int partition(int arr[],int low,int high){
  int i=low-1;
  int pivot=high;
  for(int j=low;j<high;j++){
    if(arr[j]<=arr[pivot]){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[pivot]);
  return i+1;
}
void quicksort(int arr[],int low,int high){
  if(high>low){
    int pi = partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
  }
}

void heapify(int arr[],int n,int i){
  int l = i*2+1,r=i*2+2;
  int largest=i;
  if(l<n && arr[largest]<arr[l])largest=l;
  if(r<n && arr[largest]<arr[r])largest=r;
  if(largest!=i){
    swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
  }
}
void heapsort(int arr[],int n){
  for(int i=n/2+1;i>=0;i--){
    heapify(arr,n,i);
  }
  for(int i=n-1;i>=0;i--){
    swap(arr[0],arr[i]);
    heapify(arr,i,0);
  }
}

int main(){
  cout<<"Enter size : ";
  cin>>siz;
  int arr[siz];
  for(int i=0;i<siz;i++){
    cin>>arr[i];
  }
  int i=1;
  while(i<=6){
    cout<<"Enter Your choice :\n1.Bubble\n2.Selection\n3.Merge sort\n4.Insertion\n5.Quicksort\n6.Heap Sort\n";
    cin>>i;
    switch(i){
      case 1:bubble(arr);display(arr);break;
      case 2:selection(arr);display(arr);break;
      case 3:mergesort(arr,0,siz-1);display(arr);break;
      case 4:insertion(arr);display(arr);break;
      case 5:quicksort(arr,0,siz-1);display(arr);break;
      case 6:heapsort(arr,siz);display(arr);break;
    }
  }
}
