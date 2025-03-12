#include <iostream>
using namespace std;
// normal fibonacci
long long fib1(int n){//O(2^n)
    if(n<=1 && n>=0) return n;
    return fib1(n-1)+fib1(n-2);
}
// dp fibonacci
long long fib2(int n){//O(n)
    long long arr[n+1];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=n;++i){
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n];
}
// matrix fibonacci
void matrix_multi(long long arr[2][2],long long brr[2][2]){
    long long crr[2][2];
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j){
            crr[i][j]=0;
            for(int k=0;k<2;++k)
                crr[i][j]+=arr[i][k]*brr[k][j];
        }
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
        arr[i][j]=crr[i][j];
}
long long powering(int n,long long arr[2][2]){
    long long brr[2][2]={{1,1},{1,0}};
    if(n==1)
        return brr[0][0]+brr[0][1];
    powering(n/2,arr);
    matrix_multi(arr,arr);
    if(n%2)
        matrix_multi(arr,brr);
    return arr[0][0]+arr[0][1];
}
long long fib3(int n){//O(log n)
    long long brr[2][2]={{1,1},{1,0}};
    if(n<=1)
        return n;
    if(n==2)
        return 1;
    return powering(n,brr);
}
