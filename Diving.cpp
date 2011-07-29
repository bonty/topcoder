#line 118 "Diving.cpp"
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;

class Diving {
public:
  string needed(string difficulty, string need, string ratings) {
    double di = stod(difficulty)*10;
    double n = stod(need)*100;

    for (double d = 0.0; d <= 10.0; d += 0.5) {
      vector<double> rs = getRating(ratings, d);
      
      if (check(rs, di, n) == 1) {
        return dtos(d);
      }
    }

    return string("-1.0");
  }

  double stod(string s) {
    return atof(s.c_str());
  }

  string dtos(double d) {
    char chr[50];
    sprintf(chr, "%.1f", d);
    return string(chr);
  }

  vector<double> getRating(string rating, double replace) {
    vector<double> res;
    stringstream ss;
    ss << rating;

    for (int i = 0; i < 5; ++i) {
      string r;
      ss >> r;
      if (r == "?.?") {
        res.push_back(replace*10);
      }
      else {
        res.push_back(stod(r)*10);
      }
    }
    
    return res;
  }

  int check(vector<double> ratings, double difficulty, double need) {
    double max = -1.0, min = 100.0;
    double score = 0.0;
    for (int i = 0; i < 5; ++i) {
      if (ratings[i] >= max)
        max = ratings[i];
      if (ratings[i] <= min)
        min = ratings[i];
      score += ratings[i];
    }

    score = score - max - min;

    if (score * difficulty >= need)
      return 1;
    else
      return 0;
  }
};  
  // BEGIN CUT HERE
#include <ctime>
#include <sstream>
#include <fstream>
double start_time; string timer()
 { ostringstream os; os << " (" << int((clock()-start_time)/CLOCKS_PER_SEC*1000) << " msec)"; return os.str(); }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
 { os << "{ ";
   for(typename vector<T>::const_iterator it=v.begin(); it!=v.end(); ++it)
   os << '\"' << *it << '\"' << (it+1==v.end() ? "" : ", "); os << " }"; return os; }
void verify_case(const int caseno, const string&difficulty, const string&need, const string&ratings, const string& Expected, bool verbose = false) {
  string Received = Diving().needed(difficulty, need, ratings);
  cerr << "Test Case #" << caseno << "...";
  bool ok = (Expected == Received);
  if(ok) cerr << "PASSED" << timer() << endl;   else { cerr << "FAILED" << timer() << endl;
  if (verbose) cerr << "\tdifficulty: " << difficulty<< endl;
  if (verbose) cerr << "\tneed: " << need<< endl;
  if (verbose) cerr << "\tratings: " << ratings<< endl;
  cerr << "\to: \"" << Expected << '\"' << endl << "\tx: \"" << Received << '\"' << endl; } }
void notify_memory_usage(){
#ifndef _WIN32
  std::ifstream ifs("/proc/self/status",std::ios_base::in);
  std::string str;
  for(;;){std::getline(ifs, str);
    if(str.find("VmPeak") != std::string::npos){cout << str << " (< 64MB)" << endl;}
    if(str.find("VmStk") != std::string::npos){cout << str << " (< 8MB)" << endl;break;} }
#endif
}
#define CASE(N) if (N==runno_ || (runno_<0 && N+1>=-runno_)) {int caseno=N; start_time=clock();
#define RUN_TEST()	 verify_case(caseno, difficulty, need, ratings, _, verbose_);}
int main(int argc, char **argv){
    bool verbose_ = false;
    int runno_ = -1;
    if (argc >= 2) if(!strcmp(argv[1], "-v")) verbose_ = true;
    if (argc == 2 && !verbose_) runno_ = atoi(argv[1]);
    else if (argc == 3 && verbose_) runno_ = atoi(argv[2]);

    CASE(0){
        string difficulty = "3.2";
        string need = "50.32";
        string ratings = "5.5 7.5 10.0 ?.? 4.5";
        string _ = "0.0";
        RUN_TEST();
    }
    CASE(1){
        string difficulty = "3.2";
        string need = "50.32";
        string ratings = "5.5 5.5 10.0 ?.? 4.5";
        string _ = "5.0";
        RUN_TEST();
    }
    CASE(2){
        string difficulty = "4.0";
        string need = "120.00";
        string ratings = "9.5 10.0 ?.? 10.0 10.0";
        string _ = "10.0";
        RUN_TEST();
    }
    CASE(3){
        string difficulty = "4.0";
        string need = "120.00";
        string ratings = "9.5 10.0 ?.? 9.5 10.0";
        string _ = "-1.0";
        RUN_TEST();
    }
    CASE(4){
        string difficulty = "2.3";
        string need = ".01";
        string ratings = "0.0 0.0 ?.? 0.0 0.5";
        string _ = "0.5";
        RUN_TEST();
    }
    CASE(5){
        string difficulty = "3.3";
        string need = "47.85";
        string ratings = "0.5 5.5 3.5 7.0 ?.?";
        string _ = "5.5";
        RUN_TEST();
    }
    // notify_memory_usage();

    return 0;
}
// END CUT HERE


// // BEGIN CUT HERE
// int main() {
//   Diving ___test;
//   ___test.run_test(-1);
// }
// // END CUT HERE
