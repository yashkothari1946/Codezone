#include<bits/stdc++.h>
using namespace std;


// void merge(int arr[],int a,int b,int c,int d,int e){
//   int n1,n2,n3,n4;
//   n1=b-a+1;n2=c-b;n3=d-c;n4=e-d;
//   int l1[n1],l2[n2],l3[n3],l4[n4];
//   int i=0,j=0,k=0,l=0;
//   while(i<n1){
//     l1[i]=arr[i+a];
//     i++;
//   }i=0;
//   while(i<n2){
//     l2[i]=arr[i+b+1];
//     i++;
//   }i=0;
//   while(i<n3){
//     l3[i]=arr[i+c+1];
//     i++;
//   }i=0;
//   while(i<n4){
//     l4[i]=arr[i+d+1];
//     i++;
//   }
//   i=0;
//   int ind=a;
//   while(i<n1 && j<n2 && k<n3 && l<n4 ){
//     if(l1[i]<l2[j]){
//       if(l1[i]<l3[k]){
//         if(l1[i]<l4[l]){
//           arr[ind]=l1[i];i++;
//         }else{
//           arr[ind]=l4[l];l++;
//         }
//       }else{
//         if(l3[k]<l4[l]){
//           arr[ind]=l3[k];k++;
//         }else{
//           arr[ind]=l4[l];l++;
//         }
//       }
//     }else{
//       if(l2[j]<l3[k]){
//         if(l2[j]<l4[l]){
//           arr[ind]=l2[j];j++;
//         }else{
//           arr[ind]=l4[l];l++;
//         }
//       }else{
//         if(l3[k]<l4[l]){
//           arr[ind]=l3[k];k++;
//         }else{
//           arr[ind]=l4[l];l++;
//         }
//       }
//     }
//     ind++;
//   }
//   while(i<n1 && j<n2 && k<n3){
//     if(l1[i]<l2[j]){
//       if(l1[i]<l3[k]){
//         arr[ind]=l1[i];i++;
//       }else{
//         arr[ind]=l3[k];k++;
//       }
//     }else{
//       if(l2[j]<l3[k]){
//         arr[ind]=l2[j];j++;
//       }else{
//         arr[ind]=l3[k];k++;
//       }
//     }
//     ind++;
//   }
//   while(i<n1 && j<n2 && l<n4){
//     if(l1[i]<l2[j]){
//       if(l1[i]<l4[l]){
//         arr[ind]=l1[i];i++;
//       }else{
//         arr[ind]=l4[l];l++;
//       }
//     }else{
//       if(l2[j]<l4[l]){
//         arr[ind]=l2[j];j++;
//       }else{
//         arr[ind]=l4[l];l++;
//       }
//     }
//     ind++;
//   }
//   while(i<n1 && l<n4 && k<n3){
//     if(l1[i]<l4[l]){
//       if(l1[i]<l3[k]){
//         arr[ind]=l1[i];i++;
//       }else{
//         arr[ind]=l3[k];k++;
//       }
//     }else{
//       if(l4[l]<l3[k]){
//         arr[ind]=l4[l];l++;
//       }else{
//         arr[ind]=l3[k];k++;
//       }
//     }
//     ind++;
//   }
//   while(l<n4 && j<n2 && k<n3){
//     if(l4[l]<l2[j]){
//       if(l4[l]<l3[k]){
//         arr[ind]=l4[l];l++;
//       }else{
//         arr[ind]=l3[k];k++;
//       }
//     }else{
//       if(l2[j]<l3[k]){
//         arr[ind]=l2[j];j++;
//       }else{
//         arr[ind]=l3[k];k++;
//       }
//     }
//     ind++;
//   }
//   while(i<n1 && j<n2){
//     if(l1[i]<l2[j]){
//       arr[ind]=l1[i];i++;
//     }else{
//       arr[ind]=l2[j];j++;
//     }ind++;
//   }
//   while(i<n1 && k<n3){
//     if(l1[i]<l3[k]){
//       arr[ind]=l1[i];i++;
//     }else{
//       arr[ind]=l3[k];k++;
//     }ind++;
//   }
//   while(i<n1 && l<n4){
//     if(l1[i]<l4[l]){
//       arr[ind]=l1[i];i++;
//     }else{
//       arr[ind]=l4[l];l++;
//     }ind++;
//   }
//   while(k<n3 && j<n2){
//     if(l3[k]<l2[j]){
//       arr[ind]=l3[k];k++;
//     }else{
//       arr[ind]=l2[j];j++;
//     }ind++;
//   }
//   while(l<n4 && j<n2){
//     if(l4[l]<l2[j]){
//       arr[ind]=l4[l];l++;
//     }else{
//       arr[ind]=l2[j];j++;
//     }ind++;
//   }
//   while(k<n3 && l<n4){
//     if(l3[k]<l4[l]){
//       arr[ind]=l3[k];k++;
//     }else{
//       arr[ind]=l4[l];l++;
//     }ind++;
//   }
//   while(i<n1){
//     arr[ind] = l1[i];
//     i++;
//     ind++;
//   }
//   while(j<n2){
//     arr[ind] = l2[j];
//     j++;
//     ind++;
//   }
//   while(k<n3){
//     arr[ind] = l3[k];
//     k++;
//     ind++;
//   }
//   while(l<n4){
//     arr[ind] = l4[l];
//     l++;
//     ind++;
//   }
// }
//
// void mergesort(int arr[],int l,int r){
//   if(l<r){
//     int mid1,mid2,mid3;
//     mid1=l+(r-l)/4;
//     mid2=l+(2*(r-l))/4;
//     mid3= l+(3*(r-l))/4;
//     mergesort(arr,l,mid1);
//     mergesort(arr,mid1+1,mid2);
//     mergesort(arr,mid2+1,mid3);
//     mergesort(arr,mid3+1,r);
//     merge(arr,l,mid1,mid2,mid3,r);
//   }
// }
//
// int main(){
//   int n;
//   cin>>n;
//   int arr[n];
//   for(int i=0;i<n;i++){
//     cin>>arr[i];
//   }
//   mergesort(arr,0,n-1);
//   for(int i=0;i<n;i++){
//     cout<<arr[i]<<" ";
//   }
// }


void merge(int arr[],int a,int b,int c,int d,int e){
  int n1,n2,n3,n4;
  n1=b-a+1 ;n2=c-b;n3=d-c;n4=e-d;
  int l1[n1+1],l2[n2+1],l3[n3+1],l4[n4+1];
  int i=0,j=0,k=0,l=0;
  while(i<n1){
    l1[i]=arr[i+a];
    i++;
  }l1[n1]=INT_MAX;
  i=0;
  while(i<n2){
    l2[i]=arr[i+b+1];
    i++;
  }l2[n2]=INT_MAX;
  i=0;
  while(i<n3){
    l3[i]=arr[i+c+1];
    i++;
  }l3[n3]=INT_MAX;
  i=0;
  while(i<n4){
    l4[i]=arr[i+d+1];
    i++;
  }l4[n4]=INT_MAX;
  i=0;
  int ind=a;
  while(ind<=e){
    arr[ind] = min(l1[i],min(l2[j],min(l3[k],l4[l])));
    if(arr[ind]==l1[i]){
      i++;
    }else if(arr[ind]==l2[j]){
      j++;
    }else if(arr[ind]==l3[k]){
      k++;
    }else{
      l++;
    }
    ind++;
  }
}

void mergesort(int arr[],int l,int r){
  if(l<r){
    int mid1,mid2,mid3;
    mid1=l+(r-l)/4;
    mid2=l+(2*(r-l))/4;
    mid3= l+(3*(r-l))/4;
    mergesort(arr,l,mid1);
    mergesort(arr,mid1+1,mid2);
    mergesort(arr,mid2+1,mid3);
    mergesort(arr,mid3+1,r);
    merge(arr,l,mid1,mid2,mid3,r);
  }
}

int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  mergesort(arr,0,n-1);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }cout<<"\n";
}
