#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node{
    Node* links[26];
    bool flag;
    Node(){
        for(int i = 0; i < 26; i++) links[i] = NULL;
        flag = false;
    }
    bool contains(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void end(){
        flag = true;
    }
    bool isend(){
        return flag;
    }
};

class Trie{
private: Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0 ; i<word.length() ; i++){
            if(!(node->contains(word[i]))){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->end();
    }

    bool search(string word){
        Node* node = root;
        for(int i=0 ; i<word.length() ; i++){
            if(!(node->contains(word[i]))){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isend();
    }

    bool startwith(string prefix){
        Node* node = root;
        for(int i=0 ; i<prefix.length() ; i++){
            if(!node->contains(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }

};