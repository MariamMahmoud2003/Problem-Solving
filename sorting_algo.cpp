#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
/*string k;
string convertToBinary(int decimal_num){
    if(decimal_num==1)
        return "1";
    return convertToBinary(decimal_num/2)+ to_string(decimal_num%2);
}*/
template <class T>
void insertion_sort(T arr[], int n){
    for (int i=1,j;i<n;++i){
        T temp=arr[i]; // O(1)
        for(j=i;j>0;--j){ //O(n*n)
            if(temp<arr[j-1]) {
                arr[j] = arr[j-1];
            }
            else break;
        }
        arr[j]=temp;
        for(int k=0; k<n; ++k){
            cout<<arr[k]<<' ';
        }
        cout<<endl;
    }

}
template <class T>
void selection_sort(T arr[], int n){
    for(int i=0,j,least;i<n-1;++i){
        least=i;
        for(j=i+1;j<n;++j){
            if(arr[least]>arr[j]){
               least=j;
            }
        }
        swap(arr[i],arr[least]);
        for(int k=0; k<n;++k)
            cout<<arr[k]<<' ';
        cout<<endl;
    }

}
template<typename T>
void Bubble_sort(T arr[],int n){
    bool flag=true;
    for(int i=0; i<n-1 && flag;++i){
        flag=false;
        for(int j=n-1; j>0;--j){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
                flag=true;
            }
        }
        for (int k=0; k<n; ++k)
            cout<<arr[k]<<' ';
        cout<<endl;
    }

}
template<typename T>
void Shell_sort(T arr[],int n){
    for (int gap=n/2;gap>0;gap/=2){
        for (int i=gap; i<n;++i){
            T tmp= arr[i];
            int j=i;
            for(;j>=gap && tmp < arr[j-gap];j-=gap)
                arr[j]=arr[j-gap];
            arr[j]=tmp;
            for(int k=0; k<n; ++k)
                cout<<arr[k]<<' ';
            cout<<endl;
        }

    }

}
template<typename T>
void MERGE(int begin, int end, int middle ,T arr[]){
    int ls=middle-begin+1,rs=end-middle;
    T l[ls] , r[rs];
    int i=0;
    for(; i<ls; ++i)
        l[i]=arr[i+begin];
    for(i=0; i<rs;++i)
        r[i]=arr[i+1+middle];
    i=0;
    int k=begin,j=0;
    while(i<ls && j<rs){
        if(l[i]<=r[j])
            arr[k++] = l[i++] ;
        else
            arr[k++] = r[j++] ;
    }
    while(i<ls)
        arr[k++] = l[i++]  ;
    while(j<rs)
        arr[k++] = r[j++] ;
}
template<typename T>
void Merge_sort(int begin , int end , T arr[]){
    if(begin>=end) {
        return;
    }
    int middle= begin+(end-begin) / 2;
    Merge_sort(begin,middle,arr);
    Merge_sort(middle+1,end,arr);
    MERGE(begin,end,middle,arr);
}
// complete;)
template<typename T>
int Partition(int begin, int end ,T arr[]){
    T pivot=arr[begin];
    int i=begin;
    for(int j=begin+1;j<=end;j++){
        if(pivot>arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[begin]);
    return i;
}
template<typename T>
void Quick_sort(int begin , int end , T arr[]){
    if(begin>=end) {
        return;
    }
    for(int i=begin; i<end;++i)
        cout<<arr[i]<<' ';
    cout<<endl;
    int middle = Partition(begin, end ,arr);
    Quick_sort(begin,middle-1,arr);
    Quick_sort(middle+1,end,arr);
}
//another way for quick sort <pivot is middle>
void quickSort(int arr[], int left, int right) { // at first would be called
    // with left = 0 & right = size-1
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    // partition
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    // recursion
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
template<typename T>
void print (int n, int b, int e, T arr[]){
    //Merge_sort(b,e,arr);
    Quick_sort(b,e,arr);
    for (int i =0; i<n;++i)
        cout << arr[i] << ' ';
    cout<<endl;
}

// count sort
void Count_sort (int n, int arr[]){
    cout<<"array before sorting\n";
    for (int i =1; i<=n;++i)
        cout << arr[i] << ' ';
    cout<<endl;
    // get maximum value in array
    int k=*max_element(arr,arr+n+1);
    // make auxallary array and another one to sort it outside
    int c[k+1],b[n+1];
    // initialize auxallary array elements by zero
    for(int i=1; i<=k;++i)
        c[i]=0;
    // count elements
    for(int i=1;i<=n;++i)
        c[arr[i]]+=1;
    // make cumulative sum
    for(int i=2;i<=k;++i)
        c[i]+=c[i-1];
    // put each element in certain direction
    for(int i=n;i>0;--i){
        b[c[arr[i]]]=arr[i];
        c[arr[i]]-=1;
    }
    cout<<"array after sorting\n";
    for (int i =1; i<=n;++i)
        cout << b[i] << ' ';
    cout<<endl;
}

int main (){
    int n;
    cout<<"enter number of elements\n";
    cin>>n;
    int array[n+1];
    cout<<"enter array's elements\n";
    for(int i=1; i<n+1;++i)
        cin>>array[i];
    Count_sort(n,array);
    /*int n;
    const int* ptr =&n;
    n=100;int main (){

    const int* ptr =&n;
    n=100;
    cout<<n<<"        "<<*ptr;
    const vector <int> v;
    find(v.begin(),v.end(),3);*/
    //cout<<convertToBinary(13);
    int arr[]={4,1,3,4,3};
    int arr1[]={ 3, 4, 7, 12, 14, 14, 20, 21, 33, 38, 10, 55, 9, 23, 28, 16};
    //insertion_sort(arr,5);
    //selection_sort(arr,5);
    //Bubble_sort(arr,5);
    //Shell_sort(arr,5);
    //Merge_sort(0,4,arr);
    //Quick_sort(0,4,arr);
    //print(5,0,4,arr);
    //Count_sort(5,arr);
    //insertion_sort(arr1,16);
    //selection_sort(arr1,16);
    //Bubble_sort(arr1,16);
    //Shell_sort(arr1,16);
    //Merge_sort(0,15,arr1);
    //Quick_sort(0,15,arr1);
    //print(16,0,15,arr1);
    return 0;
}
