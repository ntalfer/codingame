#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{

    set<pair<int, int>> nodes;
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    vector<vector<char>> map(width);
    for (int i = 0; i < width; i++) {
        map[i].resize(height);
    }
    
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        for(int j=0; j<line.length(); j++){
            if(line.at(j) == '0') {
                nodes.insert(make_pair(j, i));
            }
            map[j][i] = line.at(j);
        }
    }

    set<pair<int,int>>::iterator it1;
    for(it1 = nodes.begin(); it1 != nodes.end(); ++it1) {
        int x = (*it1).first;
        int y = (*it1).second;
        cerr << x << " " << y << endl;
        int bx = -1, by = -1, rx = -1, ry = -1;
        // right neighbour (same y)
        for(int i = x+1; i<width; i++) {
            if(map[i][y] == '0') {
                ry = y;
                rx = i;
                break;
            }
        }
        // below neighbour (same x)
        for(int j = y+1; j<height; j++) {
            if(map[x][j] == '0') {
                by = j;
                bx = x;
                break;
            }
        }
        
        cout << x << " " << y << " "  << rx << " "  << ry << " "  << bx << " "  << by << endl;
    }
}
