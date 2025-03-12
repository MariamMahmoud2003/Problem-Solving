#include <iostream>
using namespace std;
// sequential search iteratively
int sequential_search_it(const int arr[],int n,int item){//O(n)
    for(int i=0;i<n;++i)
        if(item==arr[i])
            return i;
    return -1;
}
// recursive binary search
int binary_search_rec(const int arr[],int item,int left,int right){//O(log n)
        if(left<=right){
            int middle = (right+left)/2;
            if(item==arr[middle])
                return middle;
            if(item<arr[middle])
                return binary_search_rec(arr,item,left,middle-1);
            return binary_search_rec(arr,item,middle+1,right);
        }
    return -1;
}
// binary search iterative
int binary_search_it(int arr[],int item,int n){//O(log n)
    int index =-1,low=0,high=n-1;
    while(low<=high){
        int middle = (low+high)/2;
        if(item==arr[middle])
            index=middle;
        if(item<arr[middle])
            high=middle-1;
        else
            low=middle+1;
    }
    return index;
}
// recursive sequential search
int sequential_search_rec(int n,int arr[],int item ,int index){// O(n)
    if(item==arr[index])
        return index;
    if(index<n)
        return sequential_search_rec(n,arr,item,index+1);
    else
        return -1;
}
