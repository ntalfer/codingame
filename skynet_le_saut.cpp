#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Read init information from standard input, if any
    int r, g, l;
    cin >> r >> g >> l;

    while (1) {
        // Read information from standard input
        int s, x;
        cin >> s >> x;
        string cmd;
        
        // Compute logic here
        if(x < r-1)
        {
            if(s < g+1)
                cmd = "SPEED";
            else if(s > g+1)
                cmd = "SLOW";
            else
                cmd = "WAIT";
        }
        else if(x == r-1)
        {
            cmd = "JUMP";
        }
        else if(x < r+g)
        {
            cmd = "WAIT";
        }
        else
        {
            cmd = "SLOW";
        }
        // cerr << "Debug messages..." << endl;

        // Write action to standard output
        cout << cmd << endl;
    }

    return 0;
}
