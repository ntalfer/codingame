#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

int main()
{
    // Read init information from standard input, if any
    int min_bomb_x, max_bomb_x, min_bomb_y, max_bomb_y;
    int w, h, n, x0, y0, x, y;
    string line, field;
    
    getline(cin, line);
    stringstream ss(line);
    getline(ss, field, ' ');
    w = stoi(field);
    getline(ss, field, ' ');
    h = stoi(field);
    
    getline(cin, line);
    n = stoi(line);
    
    getline(cin, line);
    stringstream ss2(line);
    getline(ss2, field, ' ');
    x0 = stoi(field);
    getline(ss2, field, ' ');
    y0 = stoi(field);

    // init Batman pos and bomb boundaries    
    min_bomb_x = min_bomb_y = 0;
    max_bomb_x = w-1;
    max_bomb_y = h-1;
    x = x0;
    y = y0;
    
    while (1) {
        // Read information from standard input
        string bomb_dir;
        getline(cin, bomb_dir);
        
        // calculate the new bomb vertical boundaries
        if(bomb_dir.find('U') != string::npos)
            max_bomb_y = y-1;
        else if(bomb_dir.find('D') != string::npos)
            min_bomb_y = y+1;
        else
            min_bomb_y = max_bomb_y = y;

        // calculate the new bomb horizontal boundaries
        if(bomb_dir.find('L') != string::npos)
            max_bomb_x = x-1;
        else if(bomb_dir.find('R') != string::npos)
            min_bomb_x = x+1;
        else
            min_bomb_x = max_bomb_x = x;
            
        // calculate the next x pos
        if(max_bomb_x - min_bomb_x == 1)
            x = max_bomb_x;
        else
            x = floor((min_bomb_x + max_bomb_x) / 2);
        
        // calculate the next y pos    
        if(max_bomb_y - min_bomb_y == 1)
            y = max_bomb_y;
        else
            y = floor((min_bomb_y + max_bomb_y) / 2);
        
        // Write action to standard output
        cout << x << " " << y << endl;
    }

    return 0;
}
