// Read inputs from stdin. Write outputs to stdout.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node
{
public:
  Node(char c)
  {
    val = c;
  }
  char val;
  vector<Node*> children;
};

void add_tel(vector<Node*>* roots, const string& val)
{
  Node* node = NULL;
  char c = val.at(0);
  for(int i=0; i<roots->size(); i++) {
    if((*roots)[i]->val == c) {
      node = (*roots)[i];
      break;
    }
  }
  if(node == NULL) {
    node = new Node(c);
    roots->push_back(node);
  }
  if(val.length() > 1)
    return add_tel(&node->children, val.substr(1));
}

int count_nodes(const vector<Node*>& roots)
{
  int count = 0;
  for(int i=0; i<roots.size(); i++) {
    count += 1 + count_nodes(roots[i]->children);
  }
  return count;
}

int main()
{
  vector<Node*> roots;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    string tel;
    getline(cin, tel);
    if(tel == "")
      getline(cin, tel);
    add_tel(&roots, tel);
  }
  
  int count = count_nodes(roots);
	
  cout << count << endl;
	
  return 0;
}
