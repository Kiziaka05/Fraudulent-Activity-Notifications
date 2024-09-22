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

int activityNotifications(vector<int>& expenditure, int d) {
    int notifications = 0;
    vector<int> count(201, 0);  //vector for spendings in range 0-200
    int n = expenditure.size();
    //push numbers from expenditure to count
    for (int i = 0; i < d; i++) {
        count[expenditure[i]]++;
    }

    for (int i = d; i < n; i++) {
        //find median
        int sum = 0;
        double median = 0.0;

        //d%2==1
        if (d % 2 == 1) {
            int medianPos = d / 2 + 1;
            for (int j = 0; j < 201; j++) {
                sum += count[j];
                if (sum >= medianPos) {
                    median = j;
                    break;
                }
            }
        }
        // d%2==0
        else {
            int medianPos1 = d / 2;
            int medianPos2 = medianPos1 + 1;
            int median1 = -1, median2 = -1;

            for (int j = 0; j < 201; j++) {
                sum += count[j];
                if (median1 == -1 && sum >= medianPos1) {
                    median1 = j;
                }
                if (sum >= medianPos2) {
                    median2 = j;
                    break;
                }
            }
            median = (median1 + median2) / 2.0;
        }

        //notification counter
        if (expenditure[i] >= 2 * median) {
            notifications++;
        }

        // //Erese one element and add one element
        count[expenditure[i - d]]--;  
        count[expenditure[i]]++;     
    }

    return notifications;
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

