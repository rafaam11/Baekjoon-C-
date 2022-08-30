#include <iostream>
#include <string>

using namespace std;

int main() 
{
    while (true) {
        string num;
        cin >> num;

        if (num == "0") { break; }

        int num_len = num.length();
        bool no_button = false;

        for (int i = 0 ; i < num_len / 2 ; i++) {
            if (num[i] != num[num_len - i - 1]) {
                no_button = true;
                break;
            }
        }
        
        if ( no_button == true ) { cout << "no" << endl;}
        else { cout << "yess" << endl; }

    }
    
    return 0;

}