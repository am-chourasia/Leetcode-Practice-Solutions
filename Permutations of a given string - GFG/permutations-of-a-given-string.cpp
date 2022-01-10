// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    bool n(string& s){
        int n = s.length();
        if(n == 1)
            return false;
        int left = n-2;
        while(left >= 0 && s[left] >= s[left + 1])
            left--;
        if(left == -1)
            return false;
        int right = n-1;
        while(s[right] <= s[left])
            right--;
        swap(s[right], s[left]);
        reverse(s.begin() + left + 1, s.end());
        return true;
    }
	public:
	vector<string>find_permutation(string S)
	{
	    sort(S.begin(), S.end());
	    vector<string> ans;
	    do{
	        ans.push_back(S);
	    }while(next_permutation(S));
	    return ans;
	}
};


// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends