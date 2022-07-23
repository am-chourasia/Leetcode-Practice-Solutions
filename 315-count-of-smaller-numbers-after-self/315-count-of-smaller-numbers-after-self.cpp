#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
    
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set o_set;
        int len = nums.size();
        vector<int> ans(len);
        for(int i = len - 1; i >= 0; i--){
            o_set.insert({nums[i], i});
            ans[i] = o_set.order_of_key({nums[i], INT_MIN});
        }
        return ans;
    }
};