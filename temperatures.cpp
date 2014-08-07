// Read inputs from stdin. Write outputs to stdout.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  int out_val = 5526;
  int n;
  cin >> n;
	
  vector<int> temps;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    temps.push_back(t);
  }
	
  if(n == 0) {
    out_val = 0;
  }
  else {
    for(int i=0; i<temps.size(); i++) {
      int t = temps[i];
      if(abs(t) < abs(out_val))
	out_val = t;
      else if((abs(t) == abs(out_val)) and (t == -out_val))
	out_val = abs(out_val);
                
      if(out_val == 0) // no need to go further
	break;
    }
  }
	
  cout << out_val << endl;
	
  return 0;
}
