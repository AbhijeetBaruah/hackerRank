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
//COUNTSORT => https://www.youtube.com/watch?v=pEJiGC-ObQE
//EFFICIENT ==>  use countsort when the range is known and small

void removeOldValueFromCountArray(vector<int> &countArray,int value) {
    countArray[value]--;
}
void UpdateNewValueToCountArray(vector<int> &countArray,int value) {
    countArray[value]++;
}
void getCumulativeFrequency(vector<int> &cumulativeFreq,int index) {
    cumulativeFreq[index]+=cumulativeFreq[index-1];
}

int getTwiceMedian(vector<int> countArray,int d) {
    vector<int> cumulativeFreq(countArray);
    int a=0,b=0;
    //median either a+b(even) or 2a(odd)
    if(d%2==0) {
        //even
        int i=0;
        for(;i<countArray.size();i++) {
            getCumulativeFrequency(cumulativeFreq, i);
            if( (d/2) <= cumulativeFreq[i]) {
                a = i;
                break;
            }
        }
        for(;i<countArray.size();i++) {
            if(d/2+1 <= cumulativeFreq[i]) {
                b = i;
                break;
            }
            if(i+1 < countArray.size())
                getCumulativeFrequency(cumulativeFreq, i+1); 
        }
    }else {
        //odd
        //since countArray window size is D so space occupied by a sorted countArray at index D/2 is median, and cumulativeFrequency of countArray gives us the largest index occupied by number. 
    //example real array [0,1,2,0,3,2,3] , d=7
    //countArray=> [(0,2),(1,1),(2,2),(3,2)]  (index/arrayValue,frequency)
    //cumulativeFreq=> [(0->2),(1->3),(2->5),(3->6),(3->7)]  (index/arrayValue,cumulativeValue) CumulativeFrequency gives index 1 based values so add 1 to D/2.
        //sorted array => [(0,0),(1,0),(2,1),(3,2),(4,2),(5,3),(6,3)]  (index,value)
        d = d/2+1;
        for(int i = 0;i<countArray.size();i++) {
            getCumulativeFrequency(cumulativeFreq,i);
            if(d<=cumulativeFreq[i])
                return 2*i;
        }
         
    }
    
    return a+b;
}

int activityNotifications(vector<int> expenditure, int d) {
    
    //using countsort method
    //first create a fixed length array as constraints define 0<=expenditure[i]<=200 and initialize with 0
    vector<int> countArray (201,0);
    //now count frequency of first D elements in countArray 
    for(int i=0;i<d;i++) {
        countArray[expenditure[i]]++;
    }
    //now we traverse the rest of expenditure elements
    int notify=0;
    
    for(int i = d;i<expenditure.size();i++) {
        
        int median = getTwiceMedian(countArray,d);
        if(median <= expenditure[i]) {
            notify++;
        }
        removeOldValueFromCountArray(countArray,expenditure[i-d]);
        UpdateNewValueToCountArray(countArray,expenditure[i]);
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
