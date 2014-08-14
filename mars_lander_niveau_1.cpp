#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int parse_int(stringstream& ss)
{
    string val;
    getline(ss, val, ' ');
    return stoi(val);
}

int power_up(int p)
{
    if(p == 4)
        return 4;
    return p+1;
}

int power_down(int p)
{
    if(p == 0)
        return 0;
    return p-1;;
}

int rotate_left(int r)
{
    if(r == -90)
        return -45;
    return r-15;
}

int rotate_right(int r)
{
    if(r == 90)
        return 45;
    return r+15;
}

int main()
{
    // Read init information from standard input, if any
    string line;
    getline(cin, line);
    int n = stoi(line);

    int landing_x_min = 0, landing_x_max = 6999;
    int landing_y = -1;
    bool landing_found = false;
    vector<int> ground(n);
    for(int i=0; i<n; i++)
    {
        getline(cin, line);
        stringstream ss(line);
        int x = parse_int(ss);
        int y = parse_int(ss);
        //cerr << "x=" << x << " y=" << y << endl;
        ground[x] = y;
        if(i == 0)
        {
            landing_x_min = landing_x_max = x;
            landing_y = y;
        }
        else
        {
            if(y == landing_y)
            {
                landing_x_max = x;
            }
            else if(landing_x_min == landing_x_max)
            {
                landing_x_min = landing_x_max = x;
                landing_y = y;                
            }
        }
    }
    //cerr << "landing_x_min=" << landing_x_min << ", landing_x_max=" << landing_x_max << endl;
    
    while (1) {
        // Read information from standard input
        getline(cin, line);
        stringstream ss(line);
        int x = parse_int(ss);
        int y = parse_int(ss);        
        int hs = parse_int(ss); 
        int vs = parse_int(ss);
        int f = parse_int(ss);        
        int r = parse_int(ss); 
        int p = parse_int(ss);
        int new_r = r, new_p = p;
        
        if(x < landing_x_min)
        {
            // todo in level 2
        }
        else if(x > landing_x_max)
        {
            // todo in level 2
        }
        else
        {
            // we are over the landing area
            if(vs < -39)
                new_p = power_up(p);
            else if(p > 3)
                new_p = power_down(p);
            if(r > 0)
                new_r = rotate_left(r);
            else if(r < 0)
                new_r = rotate_right(r);
        }
        
        // Write action to standard output
        cout << new_r << " " << new_p << endl;
    }

    return 0;
}
