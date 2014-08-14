// Read inputs from stdin. Write outputs to stdout.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> get_line(int n, int r)
{
    vector<int> output;
    if(n == 1)
    {
        output.push_back(r);
        return output;
    }
    
    vector<int> v = get_line(n-1, r);
    int last_val = -1;
    int count = 0;
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if(*it == last_val)
        {
            count++;
        }
        else
        {
            if(count > 0)
            {
                output.push_back(count);
                output.push_back(last_val);
            }
            last_val = *it;
            count = 1;
        }
    }
    
    if(count > 0)
    {
        output.push_back(count);
        output.push_back(last_val);
    }
    
    return output;
}

int main()
{
    int r, l;
    cin >> r >> l;
    vector<int> v = get_line(l, r);
    cout << v[0];
    for(int i=1; i<v.size(); i++)
        cout << " " << v[i];
    return 0;
}
