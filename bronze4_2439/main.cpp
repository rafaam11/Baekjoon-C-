#include <iostream>

using namespace std;


int main() 
{
    int num;
    cin >> num;

    for (int row = 1 ; row <= num ; row++) {

        for (int i = 0 ; i < num - row ; i++) {
            cout << " " ;
        }
        
        for (int i = 0 ; i < row ; i++) {
            cout << "*" ;
        }

        cout << endl;

    }
    
    return 0;

}