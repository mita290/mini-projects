#include <iostream>
using namespace std;
const int maxsize=10;
int arr[maxsize], n;

void display(){
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        cout<<arr[i]<<" ";
        if(i==n-1){
            break;
        }
    }
}

void create(){
    int i;
    cout<<"Enter the number of elements to be added in the list"<<endl;
    cin>>n;
    cout<<"Enter the array elements"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    display();
}

void insert(){
    int i,data,pos;
    cout<<endl<<"Enter the data to be inserted"<<endl;
    cin>>data;
    cout<<"Enter the position"<<endl;
    cin>>pos;
    if(maxsize==n){
        cout<<"Array overflow";
        return;
    }
        for(i=n-1;i>=pos-1;i--){
            arr[i+1]=arr[i];
        }
        arr[pos-1]=data;
        n=n+1;
        display();
}

void deleteElement(){
    int i, pos;
    cout<<"Enter the position of the data to be deleted: ";
    cin>>pos;
    for(i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n=n-1;
    display();
}

void search(){
    int i, j, k, ele;
    cout<<"Which element do you want to search for?"<<endl;
    cin>>ele;
    for(i=0;i<n;i++){
        if(ele==arr[i]){
            j++;
            k=i+1;
            break;
        }
    }
    if(j==0){
        cout<<"Element not present"<<endl;
    }
    else{
        cout<<"Element present at index "<<k<<endl;
    }
}

int main(){
    int a;
    do{
        cout<<"Which action do you wish to perform?"<<endl;
        cout<<"1.Create"<<endl;
        cout<<"2.Insertion"<<endl;
        cout<<"3.Deletion"<<endl;
        cout<<"4.Search"<<endl;
        cout<<"0.Exit"<<endl;
        cin>>a;
        switch(a){
            case 1:
                create();
                break;
            case 2: 
                insert();
                break;
            case 3:
                deleteElement();
                break;
            case 4:
                search();
                break;
            case 0: 
                break;
            default: 
                cout<<"error"<<endl;
        }
    } while(a!=0);
}
    