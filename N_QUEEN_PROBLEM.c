#include<bits/stdc++.h>
using namespace std;
int n;

void queen( vector < vector < int >> &arr,int size,int i){
    
    for(int j=0;j<size;j++){
        if(arr[i][j]==0){
            
            vector < vector < int >> parr;
              parr.resize(size);
            int k,l;
    for( k = 0 ; k < size ; ++k) 
        parr[k].resize(size);
    for( k = 0 ; k < size ; ++k) {
        for(l=0;l < size; ++l){
            parr[k][l]=arr[k][l];
        }
    }
             parr[i][j]=1;
             if(i+1==size){
    for( k = 0 ; k < size ; ++k) {
        for(l=0;l < size; ++l){
            if(parr[k][l]==-1)
          cout<<"*"<<" ";
            else
          cout<<"Q"<<" ";
        }
        cout<<endl;
    }cout<<endl;
             }else{
           
            for(k=i-1,l=j-1;k>=0&&l>=0;k--,l--)
                parr[k][l]=-1;
            
            for(k=i+1,l=j-1;k<size&&l>=0;k++,l--)
                parr[k][l]=-1;
            
            for(k=i+1,l=j+1;k<size&&l<size;k++,l++)
                parr[k][l]=-1;
            
            for(k=i-1,l=j+1;k>=0&&l<size;k--,l++)
                parr[k][l]=-1;
            
            for(k=i,l=j+1;l<size;l++)
                parr[k][l]=-1;
            
            for(k=i,l=j-1;l>=0;l--)
                parr[k][l]=-1;
            
            for(k=i+1,l=j;k<size;k++)
                parr[k][l]=-1;
            
            for(k=i-11,l=j;k>=0;k--)
                parr[k][l]=-1;
        }
            if(i+1<size)
            queen(parr,size,i+1);
        }
    }
}
int main ()
{
     cin>>n;
    vector < vector < int >> arr;
      int i,j;
  arr.resize(n);
    for( i = 0 ; i < n ; ++i) 
        arr[i].resize(n);
    
   queen(arr,n,0);
   return(0);
}
