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

    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->childeren[index]!=NULL){
            child = root->childeren[index];
        }
        else{
            return false;
        }
        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root,word);
    }
};

int main(){
    Trie* t = new Trie();
    t->insertWord("ABCD");
    if(t->searchWord("ABCD")) cout<<"'ABCD' is present."<<endl;
    else cout<<"'ABCD' is not present.";
    t->insertWord("TIME");
    if(t->searchWord("TIME")) cout<<"'TIME' is present."<<endl;
    else cout<<"'TIME' is not present.";
    if(t->searchWord("TIM")) cout<<"'TIM' is present."<<endl;
    else cout<<"'TIM' is not present.";
}