#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Read init information from standard input, if any
    
    while (1) {
        // Read information from standard input
        int sx, sy;
        cin >> sx >> sy;

        int max_y = -1;
        int max_x = 0;
        
        for(int i=0; i<8; i++)
        {
            int h;
            cin >> h;
            if(h > max_y)
            {
                max_y = h;
                max_x = i;
            }
        }
        
        // Compute logic here
        string cmd;
        if(sx == max_x)
            cmd = "FIRE";
        else
            cmd = "HOLD";
        // cerr << "Debug messages..." << endl;

        // Write action to standard output
        cout << cmd << endl;
    }

    return 0;
}
