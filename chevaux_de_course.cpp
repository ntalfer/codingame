// Read inputs from stdin. Write outputs to stdout.

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
  int n;
  cin >> n;
  set<int> powers;
	
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    powers.insert(p);
  }
	
  int diff_min = 10000000;
  for (set<int>::iterator it=powers.begin(); it!=powers.end();) {
    int first = *it;
    int second = *(++it);
    diff_min = min(abs(second-first), diff_min);
  }
	
  cout << diff_min << endl;
	
  return 0;
}
