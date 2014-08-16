#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define TOP     "TOP"
#define LEFT    "LEFT"
#define RIGHT   "RIGHT"
#define BOTTOM  "BOTTOM"
#define ERROR   "ERROR"

class Cell
{
    public:
        Cell(int t)
        {
            this->type = t;
        }
        
        int type;
        
        string next_dir(string in);
};

string Cell::next_dir(string in)
{
    switch(this->type)
    {
        case 0:
            return ERROR;
        case 1:
        case 3:
            return BOTTOM;
        case 2:
        case 6:
            if(in == LEFT)
                return RIGHT;
            if(in == RIGHT)
                return LEFT;
            return ERROR;
        case 4:
            if(in == TOP)
                return LEFT;
            if(in == RIGHT)
                return BOTTOM;
            return ERROR;
        case 5:
            if(in == TOP)
                return RIGHT;
            if(in == LEFT)
                return BOTTOM;
            return ERROR;
        case 7:
            if((in == TOP) or (in == RIGHT))
                return BOTTOM;
            return ERROR;
        case 8:
             if((in == LEFT) or (in == RIGHT))
                return BOTTOM;
            return ERROR;
        case 9:
            if((in == LEFT) or (in == TOP))
                return BOTTOM;
            return ERROR;
        case 10:
            if(in == TOP)
                return LEFT;
            return ERROR;
        case 11:
            if(in == TOP)
                return RIGHT;
            return ERROR;
        case 12:
            if(in == RIGHT)
                return BOTTOM;
            return ERROR;
        case 13:
            if(in == LEFT)
                return BOTTOM;
            return ERROR;
        default:
            return ERROR;
    }
}

int main()
{
    // Read init information from standard input, if any
    int w, h, ex;
    cin >> w >> h;
    
    int grid[20][20];
    for(int y=0; y<h; y++)
        for(int x=0; x<w; x++)
            cin >> grid[x][y];
    
    cin >> ex;
    
    while (1) {
        // Read information from standard input
        int xi, yi;
        string pos;
        cin >> xi >> yi >> pos;
        if(cin.fail()) break;
        
        // Compute logic here
        int type = grid[xi][yi];
        Cell cell(type);
        string out = cell.next_dir(pos);

        if(out == LEFT)
            xi--;
        else if(out == RIGHT)
            xi++;
        else if(out == BOTTOM)
            yi++;
            
        // Write action to standard output
        cout << xi << " " << yi << endl;
    }

    return 0;
}
