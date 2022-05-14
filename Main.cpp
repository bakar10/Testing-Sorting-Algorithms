#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>


using namespace std;


class Sorter {
public:

 virtual  void selectionSort(int arr[],int n){
     for (int i = 0, j, least; i < n-1; i++) {

         for (j = i+1, least = i; j < n; j++){

             if (arr [j] < arr [least])
                 least = j;}
         swap (arr [least], arr [i]);
     }





 }
 virtual  void quickSort(int arr[], int low, int high)
 {
     if (low < high){

         int x = part(arr, low, high);

         quickSort(arr, low, x - 1);
         quickSort(arr, x + 1, high);
     }
 }
 virtual  int part (int arr[], int low, int high)
 {
     int pivot = arr[high];
     int s = (low - 1);

     for (int j = low; j <= high - 1; j++)
     {

         if (arr[j] < pivot)
         {
             s++;
             swap1(&arr[s], &arr[j]);
         }
     }
     swap1(&arr[s + 1], &arr[high]);
     return (s + 1);
 }
 virtual  void swap1(int* m, int* n)
 {
     int t = *m;
     *m = *n;
     *n = t;
 }

};
class Testbed {
public:
    friend  void Sorter:: selectionSort(int data[],int n);
    friend void Sorter::quickSort(int *arr, int low, int high);

    int * GenerateRandomlist(int max,int min,int size){
        int*pointer;
        pointer= new int[size];
        auto ran= [&min, &max]() -> int{return min +  rand()  % (max-min+1) ;};
        generate(pointer,pointer+size,ran);
        return pointer;
    }
    int * GenerateReverseOrderedlist(int max,int min ,int size){
        int * arr;
        arr= GenerateRandomlist(max,min,size);
        sort(arr,arr+size,greater<>());
        return arr;

    }
    int RunOnce (int sorter,int* data,int size){
        int* arr;
        arr= new int[size];
        arr= GenerateRandomlist(100,0,size);
        Sorter a;
        auto start= std::chrono::high_resolution_clock::now();
        if(sorter==1){

            a.selectionSort(arr,size);
        }
        else{
            a.quickSort(arr,0,size-1);
        }
        auto end=std::chrono::high_resolution_clock::now();
        auto time=std::chrono::duration_cast<std::chrono::microseconds>(end-start);

        return time.count();
    }
    double RunAvarage (int sorter,int type,int min,int max,int size,int sets_num){ float sum=0;
        for(int i=0;i<sets_num;i++){
            int* arr;
            arr = new int[size];
            if(type==1){
                arr= GenerateRandomlist(max,min,size);

            }
            else if(type==2) {
                arr= GenerateReverseOrderedlist(max,min,size);
            }
           sum=sum+ RunOnce(sorter,arr,size);



        }
        double avarage = sum/sets_num;
        return avarage;
    }
     vector<double> RunExperient(int sorter,int type,int min,int max,int min_val,int max_val,int sets_num,int step){

        vector<double> v;
         int size=min_val;
         int m=max_val;
         for(int i=size;i<=m;i=i+step){
          double avarage = RunAvarage(sorter,type,min,max,size,sets_num);
          v.push_back(avarage);
          size=size+step;
         }
         return v;
    }


};


class SelectionSort : Sorter {
public:
    void selectionSort(int arr[],int n){
        for (int i = 0, j, least; i < n-1; i++) {

            for (j = i+1, least = i; j < n; j++){

                if (arr [j] < arr [least])
                    least = j;}
            swap (arr [least], arr [i]);
        }


    }
};
class QuickSort : Sorter{
public:
    void swap1(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[high]; // pivot
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {

            if (arr[j] < pivot)
            {
                i++;
                swap1(&arr[i], &arr[j]);
            }
        }
        swap1(&arr[i + 1], &arr[high]);
        return (i + 1);
    }
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
};


int main() {

Testbed obj;
vector<double> v;
int n;

while(1) {
    cout << "Choose Function to test: " << endl;
    cout << "1.GenerateRandomList\n";
    cout << "2.GenerateReverseOrderedList\n";
    cout << "3.RunOnce\n";
    cout << "4.RunAndAverage\n";
    cout << "5.RunExperient\n";
    cout << "6.Exit\n";
    cin >> n;
    if (n == 1) {
        int *a;
        int min, max, s;
        cout << "Enter min and max and size\n";
        cin >> min >> max >> s;
        a = new int[s];
        a = obj.GenerateRandomlist(max, min, s);
        for (int i = 0; i < s; i++) {
            cout << a[i] << " ";
        }

    }
    else if(n==2){
        int *a;
        int min, max, s;
        cout << "Enter min and max and size\n";
        cin >> min >> max >> s;
        a = new int[s];
        a = obj.GenerateReverseOrderedlist(max,min,s);
        for (int i = 0; i < s; i++) {
            cout << a[i] << " ";
        }
    }
    else if(n==3){
        int min, max, s;
        int * a;
        cout << "Enter min and max and size\n";
        cin >> min >> max >> s;
        a = new int[s];
        a = obj.GenerateReverseOrderedlist(max,min,s);
        cout<<"Choose Sorting Algorithm: \n";
        cout<<"1.Selection Sort\n";
        cout<<"2.Quick Sort\n";
        int x;
        cin>>x;
        int m=obj.RunOnce(x,a,s);
        cout<<"time: "<<m<<"ms"<<endl;

    } else if(n==4){

        cout<<"Choose Sorting Algorithm: \n";
        cout<<"1.Selection Sort\n";
        cout<<"2.Quick Sort\n";
        int x;
        cin>>x;
        int min, max, s;
        cout << "Enter min and max and size\n";
        cin >> min >> max >> s;
        cout<<"Enter sets_num \n";
        int a;
        cin>>a;
        cout<<"Choose Type: \n";
        cout<<"1.Normal\n";
        cout<<"2.Reversed\n";
        int h;
        cin>>h;
        double av=obj.RunAvarage(x,h,min,max,s,a);
        cout<<"Avarage : "<<av<<endl;
    }
    else if(n==5){cout<<"Choose Sorting Algorithm: \n";
        cout<<"1.Selection Sort\n";
        cout<<"2.Quick Sort\n";
        int x;
        cin>>x;
        cout<<"Choose Type: \n";
        cout<<"1.Normal\n";
        cout<<"2.Reversed\n";
        int h;
        cin>>h;
        int min, max, s;
        cout << "Enter min and max \n";
        cin >> min >> max ;
        cout<<"Enter sets_num \n";
        int a;
        cin>>a;
        cout<<"Enter Step \n";
        cin>>s;
        int maxv,minv;
        cout<<"Enter max_val \n";
        cin>>maxv;
        cout<<"Enter min_val \n";
        cin>>minv;

        vector<double> r;
       r= obj.RunExperient(x,h,min,max,minv,maxv,a,s);
        for(int i=0;i<r.size();i++){
            if(i==0){
                cout<<minv<<"    "<<r[i]<<endl;}
            else {
                minv=minv+s;
                cout<<minv<<"    "<<r[i]<<endl;
            }
        }



    }
    else if(n==6){break;}


}
}


