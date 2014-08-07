#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Node
{
    public:
    
        Node()
        {
           is_gateway = false;
        }
        
        set<int> neighbors;
        bool is_gateway;
};

int main()
{
    // Read init information from standard input, if any
    int n, l, e;
    cin >> n >> l >> e;

    vector<Node*> nodes;
    for(int i=0; i<n; i++)
        nodes.push_back(new Node());

    int n1, n2;
    for(int i=0; i<l; i++)
    {
        cin >> n1 >> n2;
        nodes[n1]->neighbors.insert(n2);
        nodes[n2]->neighbors.insert(n1);
    }
    
    int ei;
    for(int i=0; i<e; i++)
    {
        cin >> ei;
        nodes[ei]->is_gateway = true;
    }
    
    while (1) {
        // Read information from standard input
        int si;
        cin >> si;

        int sj = -1;
        
        // if one neighbor of skynet is a gateway, break the link
        Node* skynet = nodes[si];
        for(set<int>::iterator it=skynet->neighbors.begin(); it!=skynet->neighbors.end(); ++it)
        {
            if(nodes[*it]->is_gateway)
            {
                sj = *it;
                break;
            }    
        }
        
        // no skynet neighbor is a gateway, break the link
        // with the first neighbor
        if(sj == -1)
            sj = *skynet->neighbors.begin();

        // update links info
        skynet->neighbors.erase(sj);
        nodes[sj]->neighbors.erase(si);

        // Write action to standard output
        cout << si << " " << sj << endl;
    }

    return 0;
}
