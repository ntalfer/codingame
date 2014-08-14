// Read inputs from stdin. Write outputs to stdout.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int get_score(const vector<int>& p, const string& s)
{
  int score = 0;
  for(int i=0; i<s.length(); i++)
    score += p[s[i]-'a'];
  return score;
}

bool match(const string& letters, const string& word)
{
  string l(letters);
  string w(word);
  for(int i=0; i<w.length(); i++) {
    int pos = l.find(w[i]);
    if(pos == string::npos)
      return false;
    l.erase(pos, 1);
  }
  return true;
}

int main()
{
  vector<int> p(26);
  p['e'-'a'] = p['a'-'a'] = p['i'-'a'] = p['o'-'a'] = p['n'-'a'] = p['r'-'a'] = p['t'-'a'] = p['l'-'a'] = p['s'-'a'] = p['u'-'a'] = 1; 
  p['d'-'a'] = p['g'-'a'] = 2;
  p['b'-'a'] = p['c'-'a'] = p['m'-'a'] = p['p'-'a'] = 3; 
  p['f'-'a'] = p['h'-'a'] = p['v'-'a'] = p['w'-'a'] = p['y'-'a'] = 4;
  p['k'-'a'] = 5;
  p['j'-'a'] = p['x'-'a'] = 8;
  p['q'-'a'] = p['z'-'a'] = 10;
    
  int n;
  cin >> n;
  vector<string> words;
  for(int i = 0; i<n; i++) {
    string w;
    cin >> w;
    // we have only 7 letters, no need to store longer words
    if(w.length() < 8)
      words.push_back(w);
  }
	
  string letters;
  cin >> letters;
	
  // calculate the max score if we use all letters
  // stop the process if we place all letters
  int max_score = get_score(p, letters);
	
  int score = 0;
  int index = 0;
  for(int i=0; (i<words.size()) and (score<max_score); i++) {
    if(match(letters, words[i])) { // can we build this word?
      // if the score is greater, store the word index in the dictionnary
      int temp_score = get_score(p, words[i]);
      if(temp_score > score) {
	index = i;
	score = temp_score;
      }
    }
  }
	
  cout << words[index];
	
  return 0;
}
