// Read inputs from stdin. Write outputs to stdout.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
  int n, q;
  string n_str, q_str;
  getline(cin, n_str);
  n = atoi(n_str.c_str());
  getline(cin, q_str);
  q = atoi(q_str.c_str());
  map<string, string> table;
  for (int i = 0; i < n; i++) {	
    string ext_mime, ext, mime;
    getline(cin, ext_mime);
    unsigned pos = ext_mime.find(' ');
    ext = ext_mime.substr(0, pos);
    transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
    mime = ext_mime.substr(pos+1);
    table[ext] = mime;
  }
	
  vector<string> files;
  for (int i = 0; i < q; i++) {	
    string file;
    getline(cin, file);
    transform(file.begin(), file.end(), file.begin(), ::tolower);
    files.push_back(file);
  }
	
  for (int i = 0; i < q; i++) {	
    string f = files[i];
    unsigned pos = f.rfind('.');
    if(pos == -1) {
      // no extension
      cout << "UNKNOWN" << endl;
    }
    else {
      string f_ext = f.substr(pos + 1);
      map<string, string>::iterator it = table.find(f_ext);
      if(it == table.end()) {
	// extension not found in table
	cout << "UNKNOWN" << endl;
      }
      else {
	// extension found in table
	string f_mime = it->second;
	cout << f_mime << endl;
      }
    }
  }	
	
  return 0;
}
