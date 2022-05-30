/*HackerLand National Bank has a simple policy for warning clients about possible fraudulent account activity. If the amount spent by a client on a particular day is 
greater than or equal to 2X the client's median spending for a trailing number of days, they send the client a notification about potential fraud. 
The bank doesn't send the client any notifications until they have at least that trailing number of prior days' transaction data.
Given the number of trailing days D and a client's total daily expenditures for a period of N days, determine the number of times the client will receive a 
notification over all N days.
*/
//MULTISET is one solution but its not efficient
//finding and erasing a random number takes O(K) time

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'activityNotifications' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY expenditure
 *  2. INTEGER d
 */

void rebalance(multiset<int,greater<int>> &maxHeap, multiset<int> &minHeap) {
    if (maxHeap.size() > minHeap.size() + 1) {
        auto itr = maxHeap.begin();
        minHeap.insert(*itr);
        maxHeap.erase(itr);
    }else if (minHeap.size() > maxHeap.size()+1) {
        auto itr = minHeap.begin();
        maxHeap.insert(*itr);
        minHeap.erase(itr);
    }
}

int getUnDividedMedian(multiset<int,greater<int>> maxHeap, multiset<int> minHeap,int d) {
    if(d%2==0) {
        //even case
        return ( (*maxHeap.begin()) + (*minHeap.begin()) );
    }else {
        //odd case
        if( maxHeap.size() > minHeap.size())
            return *maxHeap.begin()*2;
        else {
            return *minHeap.begin()*2;
        }
    }
}
void deleteOneElement(multiset<int,greater<int>> &maxHeap, multiset<int> &minHeap,int value) {
    if(value <= *maxHeap.begin()) {
        maxHeap.erase(maxHeap.find(value));
    }else {
        minHeap.erase(minHeap.find(value));
    }
    rebalance(maxHeap, minHeap);
}

void add(multiset<int,greater<int>> &maxHeap, multiset<int> &minHeap,int value) {
    if(maxHeap.size() == 0 || *maxHeap.begin() > value)
            maxHeap.insert(value);
    else {
            minHeap.insert(value);
    }
    rebalance(maxHeap, minHeap);
}
int activityNotifications(vector<int> expenditure, int d) {
    if(d >= expenditure.size()) {
        return 0;
    }
    
    multiset<int,greater<int>> maxHeap;
    multiset<int> minHeap;
    int notify = 0;
    
    for(int i = 0;i<expenditure.size();i++) {
        
        if(i>=d) {
            int twicemedian = getUnDividedMedian(maxHeap,minHeap,d);
            if(twicemedian <= expenditure[i]){
                notify++;
            }
            deleteOneElement(maxHeap,minHeap,expenditure[i-d]);
        }
        add(maxHeap,minHeap,expenditure[i]);
    }
    return notify;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split(rtrim(expenditure_temp_temp));

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
