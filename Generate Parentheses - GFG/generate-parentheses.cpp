// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    vector<string> ans;
    int total;
    void construct(int opened, int closed, string s = ""){
        if(opened == total and closed == total){
            ans.push_back(s);
            return;
        }
        if(opened == closed){
            construct(opened + 1, closed, s + "(");
        } else if(opened < total){
            construct(opened + 1, closed, s + "(");
            construct(opened, closed + 1, s + ")");
        } else {
            construct(opened, closed + 1, s + ")");
        }
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        total = n;
        construct(0, 0);
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends