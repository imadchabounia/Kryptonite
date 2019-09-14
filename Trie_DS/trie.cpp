#include<bits/stdc++.h>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TreeNode{
  unordered_map<char, TreeNode*> children;
  bool isEndOfWord;
};

typedef TreeNode node;

class Trie{
public:

  node* getNode(void){
    node* tmp = new node;
    for(int i = 0; i < ALPHABET_SIZE; i++){
      tmp->children['a'+i] = NULL;
    }
    tmp->isEndOfWord = false;
    return tmp;
  }

  node* insert(node* root, string s){
    int n = s.length();
    node* current = root;
    for(int i = 0; i < n; i++){
      if(current->children[s[i]] == NULL){
        current->children[s[i]] = getNode();
      }
      current = current->children[s[i]];
    }
    current->isEndOfWord = true;

    return root;
  }

  bool find(node* root, string s){
    int n = s.length();
    bool flag = false;
    //insert char per char
    int i = 0;
    while(root->children[s[i]] != NULL && i < n){
      flag = root->children[s[i]]->isEndOfWord;
      root = root->children[s[i]];
      i++;
    }
    return (i == n) && (flag);
  }

  node* erase(node* root, string s){
    //to erase we just make NULL
    bool exists = find(root, s);
    if(exists){
      int n = s.length();
      node* current = root;
      int i = 0;
      node* prev;
      while(current != NULL && i < n){
        prev = root;
        root = root->children[s[i]];
        i++;
      }
      prev->isEndOfWord = false;
    }
    return root;
  }

  node* make_trie(vector<string> dict){
    int n = dict.size();
    node* root = getNode();
    for(int i = 0; i < n; i++){
      root = insert(root, dict[i]);
    }
    return root;
  }
};


int main(int argc, char const *argv[]) {
  Trie trie;
  node* root = trie.make_trie({"foo", "bar", "kryptonie", "flash", "dynamic", "dog", "cat"});
  return 0;
}
