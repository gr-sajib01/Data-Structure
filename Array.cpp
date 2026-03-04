#include<iostream>


using namespace std;

int main() {
    int n1 , n2 ;
    cout << "Enter the size of first array: ";
    cin >> n1;
    cout << "Enter the size of second array: ";
    cin >> n2;
    int arr1[n1], arr2[n2];
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    bool found = false;
    int size = 0 ;
    int commonArray[n1 + n2] ;

    for( int i = 0 ; i < n1 ; i++){
        for( int j = 0 ; j < n2 ;  j++){
            if(arr1[i] == arr2[j]) {
               
                commonArray[size] = arr1[i];
                found = true;
                  size++;
            }

        }
    }

    if(!found) {
        cout << "No common elements found." << endl;
    } else {
        cout << "Common elements are: ";
        for (int i = 0; i < size; i++) {
            cout << commonArray[i] << " ";
        }
        cout << endl;
    }

    return 0;
}