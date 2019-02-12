// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Jan 21, 2019

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    int getNumber(string& s){
        string num_str = "";
        int i;
        for(i=0; i < s.length(); i++){
            if(s[i] == ',') break;
            num_str.push_back(s[i]);
        }
        s = s.substr(i+1, s.length()-i-1);
        return std::stoi(num_str);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //preOrder traversal: root, left, right
        //','=break, '_'=null
        if(root == NULL) return "_,";
        string s = std::to_string(root->val) + ',';
        s.append(serialize(root->left));
        s.append(serialize(root->right));
        return s;
    }
    
    TreeNode* deserializeHelper(string& data){
        if(data.size() == 0) return NULL;
        if(data.substr(0,2) == "_,"){
            data = data.substr(2,data.size()-2);
            return NULL;
        }
        TreeNode* root = new TreeNode(this->getNumber(data));
        TreeNode* left = deserializeHelper(data);
        TreeNode* right = deserializeHelper(data);
        root->left = left;
        root->right = right;
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return this->deserializeHelper(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));