#include<iostream>
#include<string>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode**children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data=data;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

class Trie{
TrieNode *root;

public:
    Trie()
    {
        root= new TrieNode('\0');
    }

    void insert(TrieNode*root, string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        TrieNode*child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL)
            child=root->children[index];
        else
        {
            child= new TrieNode(word[0]);
            root->children[index]=child;
        }

        insert(child,word.substr(1));

    }

    void insert(string word)
    {
        insert(root,word);
    }

};

int main()
{
    Trie obj;
    obj.insert("and");
}
