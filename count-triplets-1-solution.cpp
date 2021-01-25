
#include <bits/stdc++.h>

using namespace std;

// Complete the countTriplets function below.
long long countTriplets(vector<long> arr, long r) {

    map<long,int> RightHandSide;
    map<long,int> LeftHandSide;
    long long output=0;
    long i = 1;
    LeftHandSide.insert(pair<long,int>(arr[i-1],1));

    //cout<<"i = "<<i<<endl;
    for(long j = i+1;j<arr.size();j++)
    {
        if(RightHandSide.count(arr[j])>0)
           {
               RightHandSide[arr[j]]++;
           }
        else
            {
                RightHandSide.insert(pair<long,int>(arr[j],1));
            }
    }
    //cout<<RightHandSide.size();
    for(long j = i;j<arr.size();j++)
    {

        long ar = arr[j];
        if(j != i)
        {
             if(RightHandSide.count(ar) >0)
            {
                if(RightHandSide[ar] == 1)
                    RightHandSide.erase(ar);
                else
                    RightHandSide[ar]--;
            }
        }
        if(ar%r == 0)
        {
            long a = ar/r;
            long ar2 = ar*r;
            long count1=0,count2=0;
            if(LeftHandSide.count(a) >0)
            {
                count1 = LeftHandSide[a];
            }
            if(RightHandSide.count(ar2)>0)
            {
                count2 = RightHandSide[ar2];
            }
            output = output+count1*count2;
            //cout<<"iteration = "<<j<<" , "<<output<<endl;
        }
        if(LeftHandSide.count(ar) >0)
        {
            LeftHandSide[ar]++;
        }
        else{
            LeftHandSide.insert(pair<long,int>(ar,1));
        }
    }
    return output;
}

int main()
{
    // open file for test cases in my local machine
    ifstream inputFile("/hackerank/inputfull.txt");

    vector<long> arr;
    int i=0;
// test file open
    if (inputFile) {
        long value;

        // read the elements in the file into a vector
        while ( inputFile >> value) {
            arr.push_back(value);
            i++;
        }
    }
    //cout<<"i = "<<i<<endl;
    inputFile.close();
    //cout<<arr.size()<<endl;
    long long val = countTriplets(arr,3);
    cout<<val<<endl;
    return 0;
}


