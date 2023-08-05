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

     private:
     bool search(TrieNode*root, string word) {
        // Write your code here
        if(word.size()==0)
        {
            if(root->isTerminal)
            return true;

            else
            return false;
        }


          int index = word[0] - 'a';
          if( root->children[index] && root->children[index]->data==word[0])
            return search(root->children[index],word.substr(1));

          else
          return false;


    }

    public:

    bool search(string word) {
        // Write your code here
          return search(root,word);

    }

    private:
        void remove(TrieNode*root,string word)
        {
            if(word.size()==0)
            {
                root->isTerminal=false;
                return;
            }
            int index=word[0]-'a';
            if(root->children[index] && root->children[index]->data==word[0])
                remove(root->children[index],word.substr(1));

            return;
        }


    public:
        void remove(string word)
        {
            remove(root,word);
        }

};

int main()
{
    Trie obj;
    obj.insert("and");
    obj.insert("are");
    obj.insert("pei");
    obj.insert("shugj");
    obj.insert("ijei");

    cout<<obj.search("shugj");
    obj.remove("shugj");
    cout<<obj.search("shugj");
}
