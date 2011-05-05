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

class MathContest {
public:
    int countBlack (string ballSequence, int repetitions) {
        int result = 0;
        int turn = 1, access = 1, i, len;
        char curr;
        string sum;

        for (i=0; i< repetitions; i++)
            sum += ballSequence;
        len = sum.length();

        while (len > 0) {
            // cout << sum;

            if (access == 1) {
                curr = sum[0];
                sum = sum.substr(1);
            } else {
                curr = sum[len-1];
                sum = sum.substr(0, len-1);
            }
            len = sum.length();

            // char tmp;
            // if (turn == 1)
            //     if (curr == 'B')
            //         tmp = 'B';
            //     else
            //         tmp = 'W';
            // else
            //     if (curr == 'B')
            //         tmp = 'W';
            //     else
            //         tmp = 'B';

            // cout << " " << curr << " " << tmp << " " << turn << endl;

            if (turn == 1) {
                if (curr == 'B') {
                    result++;
                    turn = 3 - turn;
                }
                else {
                    access = 3 - access;
                }
            }
            else {
                if (curr == 'W') {
                    result++;
                    turn = 3 - turn;
                }
                else {
                    access = 3 - access;
                }
            }
        }

        return result;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BBWWB"; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "BBB"; int Arg1 = 10; int Arg2 = 1; verify_case(1, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BW"; int Arg1 = 10; int Arg2 = 20; verify_case(2, Arg2, countBlack(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "WWWWWWWBWWWWWWWWWWWWWW"; int Arg1 = 1; int Arg2 = 2; verify_case(3, Arg2, countBlack(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  MathContest ___test;
  ___test.run_test(-1);
}
// END CUT HERE
