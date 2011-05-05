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

class HealthFood {
public:
    vector <int> selectMeals (vector <int> protein, vector <int> carbs, vector <int> fat, vector <string> dietPlans) {
        vector <int> result;
        vector <int> search, calorie, p_max, p_min, c_max, c_min, f_max, f_min, t_max, t_min;
        int i, n = protein.size(), m = dietPlans.size();

        for (i=0; i<n; i++)
            calorie[i] = protein[i]*9 + (carbs[i]+fat[i])*5;


        p_max = getMaxIndex(protein);
        p_min = getMinIndex(protein);
        c_max = getMaxIndex(carbs);
        c_min = getMinIndex(carbs);
        f_max = getMaxIndex(fat);
        f_min = getMinIndex(fat);
        t_max = getMaxIndex(calorie);
        t_min = getMinIndex(calorie);

        for (i=0; i<m; i++) {
            int j, l = dietPlans[i].length();

            for (j=0;j<n;j++)
                search[i] = i;

            for (j=0; j<l; j++) {
                if (search.size() == 1)
                    break;
                switch (dietPlans[i][j]) {
                    case 'p':
                        search = getCorrespond(search, p_min);
                        break;
                    case 'P':
                        search = getCorrespond(search, p_max);
                        break;
                    case 'c':
                        search = getCorrespond(search, c_min);
                        break;
                    case 'C':
                        search = getCorrespond(search, c_max);
                        break;
                    case 'f':
                        search = getCorrespond(search, f_min);
                        break;
                    case 'F':
                        search = getCorrespond(search, f_max);
                        break;
                    case 't':
                        search = getCorrespond(search, t_min);
                        break;
                    case 'T':
                        search = getCorrespond(search, t_max);
                        break;
                }
            }

            result.push_back(search[0]);
        }
        return result;
    }

    vector <int> getCorrespond (vector <int> a1, vector <int> a2) {
        int i,j,m=a1.size(),n=a2.size();
        vector <int> res;
        for (i=0;i<m;i++)
            for (j=0;j<n;j++)
                if (a1[i]==a2[j])
                    res.push_back(a1[i]);

        return res;
    }

    vector <int> getMinIndex (vector <int> arr) {
        vector <int> res;
        int min=10000, i, n=arr.size();
        for (i=0; i<n; i++)
            if (min > arr[i])
                min = arr[i];

        for (i=0; i<n; i++)
            if (arr[i] == min)
                res.push_back(i);

        return res;
    }

    vector <int> getMaxIndex (vector <int> arr) {
        vector <int> res;
        int max=-1, i, n=arr.size();
        for (i=0; i<n; i++)
            if (max < arr[i])
                max = arr[i];

        for (i=0; i<n; i++)
            if (arr[i] == max)
                res.push_back(i);

        return res;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"P", "p", "C", "c", "F", "f", "T", "t"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 1,  0,  1,  0,  0,  1,  1,  0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(0, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {3, 4, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 8, 5, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5, 2, 4, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"tFc", "tF", "Ftc"}; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 3,  2,  0 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(1, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {18, 86, 76,  0, 34, 30, 95, 12, 21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {26, 56,  3, 45, 88,  0, 10, 27, 53}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {93, 96, 13, 95, 98, 18, 59, 49, 86}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arr3[] = {"f", "Pt", "PT", "fT", "Cp", "C", "t", "",
 "cCp", "ttp", "PCFt", "P", "pCt", "cP", "Pc"}
; vector <string> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = { 2,  6,  6,  2,  4,  4,  5,  0,  5,  5,  6,  6,  3,  5,  6 }; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); verify_case(2, Arg4, selectMeals(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  HealthFood ___test;
  ___test.run_test(-1);
}
// END CUT HERE
