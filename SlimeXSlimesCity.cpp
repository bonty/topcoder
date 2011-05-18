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

class SlimeXSlimesCity {
public:
    int merge (vector <int> population) {
        int result = 1;
        int size = population.size();
        int i, j;
        sort(population.begin(), population.end());

        int max = population[size-1];

        for (i = size - 2; i >= 0; i--) {
            int flag = 0;
            unsigned long long sum = population[i];
            if (sum >= max) {
                result++;
                continue;
            }

            for (j = i - 1; j >= 0; j--) {
                sum += population[j];
                if (sum >= max) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1 || sum >= max)
                result++;
            cout << max << " : " << sum << endl;
        }

        return result;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, merge(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, merge(Arg0)); }
	void test_case_2() { int Arr0[] = {8,2,3,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(2, Arg1, merge(Arg0)); }
	void test_case_3() { int Arr0[] = {1000000000, 999999999, 999999998, 999999997}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, merge(Arg0)); }
	void test_case_4() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, merge(Arg0)); }
	void test_case_5() { int Arr0[] = {1, 2, 4, 6, 14, 16, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, merge(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  SlimeXSlimesCity ___test;
  ___test.run_test(-1);
}
// END CUT HERE
