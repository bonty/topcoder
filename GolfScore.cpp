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
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;

class GolfScore {
public:
  int tally (vector <int> parValues, vector <string> scoreSheet) {
    int result = 0;
    int hole = parValues.size();
    for (int i=0; i<hole; i++) {
        if (scoreSheet[i] == "triple bogey")
            result += parValues[i] + 3;
        else if (scoreSheet[i] == "double bogey")
            result += parValues[i] + 2;
        else if (scoreSheet[i] == "bogey")
            result += parValues[i] + 1;
        else if (scoreSheet[i] == "par")
            result += parValues[i];
        else if (scoreSheet[i] == "birdie")
            result += parValues[i] - 1;
        else if (scoreSheet[i] == "eagle")
            result += parValues[i] - 2;
        else if (scoreSheet[i] == "albatross")
            result += parValues[i] - 3;
        else if (scoreSheet[i] == "hole in one")
            result += 1;
    }
    return result;
  }

  
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1, 1, 1, 1,
 1, 1, 1, 5, 5, 5,
 5, 5, 5, 5, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bogey", "bogey", "bogey", "bogey", "bogey", "bogey",
 "bogey", "bogey", "bogey", "eagle", "eagle", "eagle",
 "eagle", "eagle", "eagle", "eagle", "eagle", "eagle"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 45; verify_case(0, Arg2, tally(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3, 2, 4, 2, 2, 1,
 1, 1, 3, 2, 4, 4,
 4, 2, 3, 1, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"bogey", "double bogey", "par", "double bogey", "double bogey", "triple bogey",
 "triple bogey", "triple bogey", "bogey", "double bogey", "par", "par",
 "par", "double bogey", "bogey", "triple bogey", "bogey", "double bogey"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 72; verify_case(1, Arg2, tally(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3, 2, 4, 2, 2, 1,
 1, 1, 3, 2, 4, 4,
 4, 2, 3, 1, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"eagle", "birdie", "albatross", "birdie", "birdie", "par",
 "hole in one", "par", "eagle", "birdie", "albatross", "albatross",
 "albatross", "birdie", "eagle", "hole in one", "eagle", "birdie"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 18; verify_case(2, Arg2, tally(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {4, 1, 3, 3, 4, 4,
 1, 4, 2, 3, 3, 5,
 4, 1, 4, 4, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"triple bogey", "triple bogey", "bogey", "par", "triple bogey", "double bogey",
 "triple bogey", "triple bogey", "par", "eagle", "bogey", "bogey",
 "birdie", "par", "triple bogey", "eagle", "triple bogey", "triple bogey"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 77; verify_case(3, Arg2, tally(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  GolfScore ___test;
  ___test.run_test(-1);
}
// END CUT HERE