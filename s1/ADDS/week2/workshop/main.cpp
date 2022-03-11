#include <iostream>

using namespace std;

void stringPointerOperation(char* str, char* firstPtr, char* secondPtr)
{ 
    cout << str << endl;
    cout << "First character = " << *firstPtr << endl; 
    cout << "Second character = " << *secondPtr << endl; 
    cout << "Char between first and second: " << (secondPtr - firstPtr) / sizeof(char) << endl;
} 

int main(void) {
    char arr[] = "abc";
    stringPointerOperation(arr, &arr[0], &arr[2]);
}