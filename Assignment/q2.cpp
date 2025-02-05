#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array : ";
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    cout<<"The reverse of the array is : ";
    for(int i=n-1 ; i>=0 ; i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int max = arr[0];
    int min = arr[0];
    int secondmax = arr[0];
    int secondmin = arr[0];
    for(int i=0 ; i<n ; i++){
        if(arr[i]>max){
            secondmax = max;
            max = arr[i];
        }
        else if(arr[i]>secondmax && arr[i]!=max){
            secondmax = arr[i];
        }
    }
        
    cout<<"The second largest element  is : "<<secondmax<<endl;
}