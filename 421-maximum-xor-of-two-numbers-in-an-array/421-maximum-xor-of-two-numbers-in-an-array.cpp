class Node {
public:
    Node* left;
    Node* right;
};
class Tree {
    bool isSet(int n, int i){
        return (n & (1 << i));
    }
public:
    Node* root;
    Tree(){
        root = new Node();
    }
    void add(int n){
        Node* node = root;
        for(int i = 31; i >= 0; i--){
            if(isSet(n, i)){
                if(node->right == nullptr)
                    node->right = new Node();
                node = node->right;
            } else {
                if(node->left == nullptr)
                    node->left = new Node();
                node = node->left;
            }
        }
    }
    int maxXOR(int n){
        Node* node = root;
        int tempAns = 0;
        for(int i = 31; i >= 0; i--){
            tempAns = tempAns << 1;
            if(isSet(n, i)){
                if(node -> left != nullptr)
                    node = node->left;
                else {
                    node = node->right;
                    tempAns++;
                }
            } else {
                if(node -> right != nullptr){
                    node = node->right;
                    tempAns++;
                }
                else 
                    node = node -> left;
            }
        }
        return tempAns xor n;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Tree tree;
        for(int& num : nums)
            tree.add(num);
        int ans = 0;
        for(int& num : nums){
            cout << tree.maxXOR(num) << " " ;
            ans = max(ans, tree.maxXOR(num));
        }
        cout << endl;
        return ans;
    }
};