// Read inputs from stdin. Write outputs to stdout.

#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
  string text;
  getline(cin, text);
    
  // construct the bit string
  string bit_string = "";
  for(int i=0; i<text.length(); i++) {
    char s = text[i];
    bitset<7> bs(s);
    bit_string += bs.to_string();
  }

  string out = "";
  int is_zero = -1;
  string temp = "";
  for(string::iterator it = bit_string.begin(); it != bit_string.end(); ++it) {
    int new_is_zero = (*it == '0');
    if(new_is_zero == is_zero) {
      temp += "0";
    }
    else {
      is_zero = new_is_zero;
      if(out.length() > 0)
	out += " ";
      out += temp;
      if(is_zero)
	temp = "00 0";
      else
	temp = "0 0";
    }
  }

  // the last char has not been flushed, do it!
  if(temp.length() > 0) {
    if(out.length() > 0)
      out += " ";
    out += temp;
  }
    
  cout << out << endl;
  return 0;
}
