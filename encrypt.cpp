/**
This is an old version, please check "v2" folder for the latest. Thank you!
**/

#include <bits/stdc++.h>
using namespace std;

const string lib[] = {"iostream", "assert.h", "math.h", "memory.h", "stdio.h", "algorithm",
                      "complex", "ctime", "fstream", "iostream", "list", "queue", "deque",
                      "unordered_map", "unordered_set", "map", "bitset", "numeric", "climits",
                      "iomanip", "set", "stack", "string", "vector", "array", "random", "chrono"};

const string YOURNAME = "abcdxyz";

void std_lib(){
  for(const string &S: lib) cout << "#include <" << S << ">\n";
  cout << "using namespace std;\n";
}

vector <char> chars;
void prep(){
  for(int i = 0; i < 26; i++){
    chars.push_back('a' + i);
    chars.push_back('A' + i);
    if(i <= 9) chars.push_back('0' + i);
  }
}

const int len_def = 10;
vector <string> main_codes;
vector <string> defines;
string def;
void getrandstr(){
  def = "#define " + YOURNAME;
  string ok = YOURNAME;
  int len = rand() % len_def + 5;

  while(len--){
    int pos = rand() % chars.size();
    ok.push_back(chars[pos]);
    def.push_back(ok.back());
  }

  ok.push_back(' ');
  def.push_back(' ');
  main_codes.push_back(ok);
}

bool isdef(const string &s){
  if(s.find("typedef") != -1) return 1;
  if(s.find("#define") != -1) return 1;
  if(s.find("using") != -1 && s != "using namespace std;") return 1;
  return 0;
}

int main(){
  freopen("code.cpp", "r", stdin);
  freopen("res.cpp", "w", stdout);

  srand(time(NULL));
  prep();
  std_lib();

  string s;

  while(getline(cin, s)){
    while(s.size() && (s[0] == ' ' || s[0] == '\t')) s.erase(0, 1);

    //any comment without code will be deleted
    if(s.find("//") != -1){
      if(s.substr(0, 2) == "//") continue;
    }

    //this code cant encrypt your comment well, so comments begin with /* will be deleted
    if(s.find("/*") != -1){
      while(s.find("*/") == -1) getline(cin, s);
      continue;
    }

    //your definition won't be encrypted, because when this program shuffles your definition (which has been encrypted),
    //you will receive a "Compilation Error" code
    if(s.find("#include") != -1) continue;
    if(isdef(s)){
      cout << s << '\n';
      continue;
    }

    if(s == " " || s == "\n") continue;
    if(s.size() == 0) continue;

    getrandstr();
    def += s;
    defines.push_back(def);
  }

  for(int time_rand = 10; time_rand--; ) shuffle(defines.begin(), defines.end(), default_random_engine(0));

  for(const string &codes : defines) cout << codes << '\n';
  for(const string &codes : main_codes) cout << codes << '\n';

  cerr << "Done ! Check file res.cpp";

  return 0;
}
