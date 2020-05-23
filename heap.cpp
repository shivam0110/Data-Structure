#include<bits/stdc++.h>
using namespace std;

void max_heapify(int b[], int n, int i) { 
    int p=i; 
    int l=2*i+1; 
    int r=2*i+2; 
    if(l<n && b[l]>b[p]){ 
        p=l; 
    } 
    if(r<n && b[r]>b[p]){ 
        p=r; 
    } 
    if(p!=i){ 
        int temp=b[i]; 
        b[i]=b[p]; 
        b[p]=temp; 
        max_heapify(b, n, p);
    } 
} 

void min_heapify(int b[], int n, int i){ 
    int p=i; 
    int l=2*i+1; 
    int r=2*i+2; 
    if(l<n && b[l]<b[p]){ 
        p=l; 
    } 
    if(r<n && b[r]<b[p]){ 
        p=r; 
    } 
    if(p!=i){ 
        int temp=b[i]; 
        b[i]=b[p]; 
        b[p]=temp;
        min_heapify(b, n, p);
    } 
} 

void heapSort(int b[], int n){ 
    int c; 
    cout<<"\nSort using \n1)Maxheap\n2)Minheap\n"; 
    cin>>c; 
    switch(c){ 
        case 1: for (int i=n/2-1;i>=0;i--) 
                max_heapify(b, n, i); 
                for (int i=n-1;i>=0;i--){ 
                    int temp=b[0]; 
                    b[0]=b[i]; 
                    b[i]=temp; 
                    max_heapify(b, i, 0); 
                } 
                break; 
        case 2: for (int i=n/2-1;i>=0;i--) 
                min_heapify(b, n, i); 
                for (int i=n-1;i>=0;i--){ 
                    int temp=b[0]; 
                    b[0]=b[i]; 
                    b[i]=temp; 
                    min_heapify(b, i, 0); 
                } 
                break; 
        default:cout<<"Enter valid case\n"; 
                break; 
    }
} 

void max_buildHeap(int b[], int n) { 
    for(int i=(n/2)-1;i>= 0;i--){ 
        max_heapify(b, n, i); 
    } 
} 

void min_buildHeap(int b[], int n){ 
    for(int i=(n/2)-1;i>= 0;i--){ 
        min_heapify(b, n, i); 
    } 
} 

void printHeap(int b[], int n) { 
    cout<<"The array representation is:\n "; 

    for (int i=0;i<n;++i){ 
        cout<<b[i]<<"\t"; 
    } 
    cout<<endl; 
} 

void insert_maxheap(int arr[], int n, int value){
    int i; 
    i=n;
    while(i>0){ 
        int parent=(int)(i/2); 
        if(arr[parent]<arr[i]){ 
            int temp=arr[parent]; 
            arr[parent]=arr[i]; 
            arr[i]=temp; i=parent; 
        } 

        else
            return ; 
    } 
} 

void insert_minheap(int arr[], int n, int value){ 
    int i; 
    i=n; 
    while(i>0){ 
        int parent=(int)(i/2); 
        if(arr[parent]>arr[i]){ 
            int temp=arr[parent]; 
            arr[parent]=arr[i]; 
            arr[i]=temp; i=parent; 
        } 

        else
            return ; 
    } 
} 

int main(){ 
    int b[]={2,7,26,25,19,17,1,90,3,36}; 
    int n=sizeof(b)/sizeof(b[0]); 
    int arr[10],i,c,x,a; 

    while(1){ 
        cout<<"-------------------------------------\n";
        cout<<"\n1)Create Maxheap\n2)Create Minheap\n3)Convert an array into Maxheap";
        cout<<"\n4)Convert an array into Minheap\n5)Heapsort\n6)Exit\t"; 
        cin>>a;
        cout<<"\n\n";
        switch(a){ 
            case 1: i=0; 
                    c=0; 
                    cout<<"Enter Number of elements for maxheap: ";
                    cin>>x; 
                    while(x--){ 
                        cin>>arr[i]; 
                        insert_maxheap(arr,c,arr[i]);
                        i++; 
                        c++; 
                    } 
                    cout<<"Representation : ";
                    for(i=0;i<c;i++) 
                        cout<<arr[i]<<"\t";                
                    cout<<endl<<endl;
                    break; 
            case 2: i=0;
                    c=0; 
                    cout<<"Enter Number of elements for minheap: ";
                    cin>>x;
                    while(x--){ 
                        cin>>arr[i]; 
                        insert_minheap(arr,c,arr[i]); 
                        i++; 
                        c++; 
                    } 
                    cout<<"Representation : ";
                    for(i=0;i<c;i++)
                        cout<<arr[i]<<"\t"; 
                    cout<<endl<<endl;
                    break; 
            case 3: max_buildHeap(b, n); 
                    printHeap(b, n); 
                    cout<<endl<<endl;
                    break; 
            case 4: min_buildHeap(b, n); 
                    printHeap(b, n);
                    cout<<endl<<endl;
                    break; 
            case 5: heapSort(b, n);
                    printHeap(b, n); 
                    cout<<endl<<endl;
                    break; 
            case 6: cout<<"Exiting...";
                    exit(0);
            default:cout<<"Enter valid case\n"; 
                    break; 
        } 
    } 
    return 0; 
}