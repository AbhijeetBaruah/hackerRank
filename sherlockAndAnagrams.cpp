#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    
    map<string,int> hashstring;
    int output = 0;
    int n = s.length();
    
    //creating substring ==> sorting ==> adding to map and keeping the count of anagrams
     for (int len = 1; len <= n; len++) 
    {    
        for (int i = 0; i <= n - len; i++) 
        { 
            int j = i + len - 1; 
            string subst;           
            for (int k = i; k <= j; k++) 
                subst +=s[k];
            
            sort(subst.begin(),subst.end());
            if(hashstring.count(subst)>0)
            {
                hashstring[subst]++;
            }
            else {
                hashstring.insert(pair<string,int>(subst,1));
            }
        }
    }
    
    for(auto i:hashstring)
    {
        if(i.second>1)
        {
            output += (i.second*(i.second-1))/2;
        }
    }
    
    return output;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
