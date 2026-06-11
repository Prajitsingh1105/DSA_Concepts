#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* childeren[26];
        bool isTerminal;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            childeren[i]=NULL;
        }
        isTerminal = false;
    }
};


class Trie{
    public: 
        TrieNode* root;
    
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;
        if(root->childeren[index]!=NULL){
            child = root->childeren[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->childeren[index] = child;
        }
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }
};

int main(){
    Trie* t = new Trie();
    t->insertWord("ABCD");
}