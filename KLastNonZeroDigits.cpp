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

class KLastNonZeroDigits {
public:
  string getKDigits (int N, int K) {
    string result;
    ll f = getFactorialZeroRemoved(N);
    string str = toStr(f);
    if (str.length() > K) {
        result = str.substr(str.length()-K);
    }
    else {
        result = str;
    }
    return result;
  }

  ll getFactorialZeroRemoved (int n) {
      ll res = 1;
      while (n > 1) {
          res *= n;
          n--;
      }
      while (res % 10 == 0) {
          res /= 10;
      }
      return res;
  }

  string toStr(ll n) {
      ostringstream ss;
      ss << n;
      return ss.str();
  }

  

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
