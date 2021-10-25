#include <bits/stdc++.h>
using namespace std;

string s;
map <string, string> conv;
vector <string> save;

const string YOURNAME = "abcdxyz";

int main(){
  freopen("res.cpp", "r", stdin);
  freopen("code.cpp", "w", stdout);

  cout << "#include <bits/stdc++.h>\n";
  cout << "using namespace std;\n\n";

  while(getline(cin, s)){
    if(s.find("include") != -1) continue;
    if(s == "using namespace std;") continue;

    if(s.find("#define") != -1){
      if(s.find(YOURNAME) == -1){
        cout << s << '\n';
        continue;
      }
      string token = "", en = "", de;
      stringstream read(s);

      while(read >> token){
        if(token == "#define") continue;
        if(token.find(YOURNAME) != -1) de = token;
        else en += token, en += " ";
      }

      while(en.size() && en.back() == ' ') en.pop_back();
      conv[de] = en;
      continue;
    }

    while(s.size() && s.back() == ' ') s.pop_back();
    cout << (conv.count(s) ? conv[s] : s) << '\n';

  }

  cerr << "Done ! Check file code.cpp";

  return 0;
}
