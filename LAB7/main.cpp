#include<iostream>
#include<fstream>

using namespace std;

int main() {
    ifstream input("2Darray.txt");
    if(!input)
    {
        cout<<"Error: File does not exits"<<endl;
        return -1;
    }

    const int ROWS = 5;
    const int COLS = 5;
    int arr[ROWS][COLS];

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            input>>arr[i][j];
        }
    }

    input.close();

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++)
        {
            cout<<arr[i][j]<< " ";
        }
    }
}