#include <map> 
#include <memory> 
#include <new> 
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf> 
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <iostream>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */





int activityNotifications(vector<int> expenditure, int d) {
    int notification = 0;
    int n= expenditure.size();
    multiset<int> expedituresorted;

    //filling multiset with numbers from expediture in range i-d
    for (int i = 0; i < d; ++i) {
        expedituresorted.insert(expenditure[i]);
    }
    for (int i = d; i < n; ++i) {


        //find median 
        double median = 0;
        auto it = expedituresorted.begin();
        if (d % 2 == 1) {
            advance(it, d / 2);
            median = *it;
        }
        else {
            advance(it, d / 2 - 1);
            double lower = *it;
            advance(it, 1);
            double upper = *it;
            median = (lower + upper) / 2.0;
        }


        //notification counter
        if (expenditure[i] >= 2 * median) {
            notification++;
        }

        //Erese one element and add one element
        expedituresorted.erase(expedituresorted.find(expenditure[i - d]));
        expedituresorted.insert(expenditure[i]);
    }

    return notification;
}

int main()
{
    
    int d = 4;
    vector<int> expenditure;
    expenditure = { 1, 2, 3, 4,4 };

    int result = activityNotifications(expenditure,d);
    cout << result;
    

    return 0;
}

