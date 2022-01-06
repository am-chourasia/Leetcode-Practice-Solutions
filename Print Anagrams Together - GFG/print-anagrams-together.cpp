// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        unordered_map<string, int> mapping; // string with the index in the answer array
        vector<vector<string>> ans;
        
        for(int i = 0; i < string_list.size(); i++){
            string str = string_list[i];
            sort(str.begin(), str.end());
            if(mapping.count(str) != 0) { // if its anagram is already present;
                int index = mapping[str];
                ans[index].push_back(string_list[i]);
            }
            else {
                mapping[str] = ans.size();
                ans.push_back(vector<string>({string_list[i]}));
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends