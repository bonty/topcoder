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

#define TRUE 1
#define FALSE 0

string toStr(int n) {ostringstream ss; ss << n; return ss.str();}

class TheNumbersWithLuckyLastDigit {
public:
    int find (int n) {
        int result = 0;
        vector <int> cache(n+1);
        int i;

        int j = getLargestLucky(n);
        if (n == j)
            return 1;

        for (i = 0; i < n+1; i++) {
            cache[i] = 0;
            if (isLucky(i))
                cache[i] = 1;
            else if (i == 4 || i == 7)
                cache[i] = 1;
            else if (i < 7)
                cache[i] = -1;
            else {
                int m = getLargestLucky(i);
                while (m > 0) {
                    if (cache[i-m] != -1)
                        cache[i] = 1 + cache[i-m];
                    m = getLargestLucky(m-1);
                }
                if (cache[i] == 0)
                    cache[i] = -1;
            }
        }

        // for (i=0;i<n+1;i++)
        //     cout << i << "\t" << cache[i] << endl;

        result = cache[n];
        
        return result;
    }

    int getLargestLucky (int n) {
        while (n > 0) {
            string s = toStr(n);
            char l = s[s.size()-1];
            if (l == '4' || l == '7')
                break;
            n--;
        }
        return n;
    }

    int isLucky (int n) {
        string s = toStr(n);
        char l = s[s.size()-1];
        if (l == '4' || l == '7')
            return TRUE;
        return FALSE;
    }



// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 99; int Arg1 = 4; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { int Arg0 = 11; int Arg1 = 2; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { int Arg0 = 13; int Arg1 = -1; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { int Arg0 = 1234567; int Arg1 = 1; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  TheNumbersWithLuckyLastDigit ___test;
  ___test.run_test(-1);
}
// END CUT HERE
