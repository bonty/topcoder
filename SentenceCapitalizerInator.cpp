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

class SentenceCapitalizerInator {
public:
    string fixCaps (string paragraph) {
        string result = "";
        int i, n = paragraph.size(), flag = 1;

        for (i = 0; i < n; ++i) {
            if (flag == 1)
                result += toupper(paragraph[i]);
            else
                result += paragraph[i];

            if (paragraph[i] == '.')
                flag = 1;
            else if (flag == 1 && paragraph[i] == ' ')
                flag = 1;
            else
                flag = 0;
        }

        return result;
    }



};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
