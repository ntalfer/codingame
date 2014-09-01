// Read inputs from stdin. Write outputs to stdout.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Ood
{
public:
  Ood(long b)
  {
    budget = b;
    participation = 0;
    ruined = (budget == 0);
  }
        
  void add_p(long* price)
  {
    if(!ruined)
      {
	participation++;
	(*price)--;
	ruined = (budget == participation);
      }
  }
    
  long budget;
  long participation;
  bool ruined;
};

bool sort_by_budget(Ood first, Ood second) 
{ 
  return first.budget < second.budget;
}

bool sort_by_participation(Ood first, Ood second) 
{
  return first.participation < second.participation;
}

int main()
{
  long n, c;
  cin >> n;
  cin >> c;
  vector<Ood> oods;
	
  long max_b = 0;
  for(long i=0; i<n; i++) {
    long b;
    cin >> b;
    Ood ood(b);
    max_b += b;
    oods.push_back(ood);
  }
  
  if(max_b < c) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
	
  sort(oods.begin(), oods.end(), sort_by_budget);
	
  long price = c;
  while(price > 0) {
    for(int i=0; i<n and price>0; i++) {
      oods[i].add_p(&price);
    }
  }
  
  sort(oods.begin(), oods.end(), sort_by_participation);

  for(int i=0; i<n; i++) {
    cout << oods[i].participation << endl;
  }
	    
  return 0;
}
