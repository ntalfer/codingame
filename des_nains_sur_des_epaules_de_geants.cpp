// Read inputs from stdin. Write outputs to stdout.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Person
{
  vector<int> influenced_by_me;
  vector<int> influenced_me;
};

int max_relationships(const map<int, Person>& persons, int root_index)
{
  Person root = persons.at(root_index);
  int max_r = 0;
  for(int i=0; i<root.influenced_by_me.size(); i++) {
    max_r = max(max_r, 1 + max_relationships(persons, root.influenced_by_me[i]));
  }
  return max_r;
};

int main()
{
  // init
  map<int, Person> persons;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    persons[x].influenced_by_me.push_back(y);
    persons[y].influenced_me.push_back(x);
  }
	
  // for every person influenced by nobody (a root person), 
  // calculate the max nb of relationships he influences
  // and then take the max of these root persons
  int max_r = 0;
  for(map<int, Person>::iterator it = persons.begin(); it != persons.end(); ++it) {
    int id = it->first;
    Person p = it->second;
    if(p.influenced_me.size() == 0)
      max_r = max(max_r, max_relationships(persons, id));
  }
	
  // the max nb of persons is the max nb of relationships + 1
  int max_p = max_r + 1;
	
  cout << max_p << endl;
	
  return 0;
}
