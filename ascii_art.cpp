// Read inputs from stdin. Write outputs to stdout.

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
  string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";
  vector<string> alpha_ascii;
  int L, H;
  string L_str, H_str, T;

  getline(cin, L_str);
  getline(cin, H_str);
  getline(cin, T);

  L = atoi(L_str.c_str());
  H = atoi(H_str.c_str());
	
  for (int i = 0; i < H; i++) {
    string line;
    getline(cin, line);
    alpha_ascii.push_back(line);
  }
	
  vector<string> output(H, "");
	
  for(int i=0; i<T.length(); i++) {
    char s = toupper(T[i]);
    if((s < 'A') or (s > 'Z'))
      s = '?';
    int index = alpha.find(s);
    for(int j=0; j<H; j++) {
      string s_line = alpha_ascii[j].substr(index*L, L);
      output[j] += s_line;
    }
  }
	
  for(int i=0; i<H; i++)
    cout << output[i] << endl;
	
  return 0;
}
