#include <iostream>

using namespace std;

int main() 
{
    int H, M;
    cin >> H >> M;

    int H2, M2;

    if ( M >= 45 ) {
        H2 = H;
        M2 = M - 45;
    
    }

    else {
        if ( H == 0 ){
            H2 = H + 23;
        }

        else {
            H2 = H - 1;
        }
        M2 = M + 15;

    }

    cout << H2 << " " << M2 << endl;

    return 0;
}