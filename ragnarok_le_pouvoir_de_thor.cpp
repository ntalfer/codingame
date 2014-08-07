#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Read init information from standard input, if any
    int lx, ly, tx, ty;
    cin >> lx >> ly >> tx >> ty;
    
    while (1) {
        // Read information from standard input
        int e;
        cin >> e;

        string move = "";
        
        // Compute logic here
        if(ty < ly)
        {
            ty++;
            move += "S";
        }
        else if(ty > ly)
        {
            ty--;
            move += "N";
        }
        
        if(tx < lx)
        {
            tx++;
            move += "E";
        }
        else if(tx > lx)
        {
            tx--;
            move += "W";
        }
        // cerr << "Debug messages..." << endl;

        // Write action to standard output
        cout << move << endl;
    }

    return 0;
}
