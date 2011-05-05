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

class PerfectSequences {
public:
    string fixIt (vector <int> seq) {
        // string result;
        int i, j, n = seq.size();
        ll sum = 0, prod = 1, tmp_sum, tmp_prod;

        if (n == 1) return "Yes";

        for (i = 0; i < n; ++i) {
            sum += seq[i];
            prod *= seq[i];
        }

        for (i = 0; i < n; ++i) {
            for (j = seq[i] - 1; j >= 0; --j) {
                tmp_sum = sum - seq[i] + j;
                tmp_prod = prod / seq[i] * j;
                if (tmp_sum == tmp_prod)
                    return "Yes";
            }
        }

        return "No";
    }

    bool hasNegative (vector <int> seq) {
        for (int i = 0; i < seq.size(); ++i)
            if (seq[i] < 0)
                return false;

        return true;
    }



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
