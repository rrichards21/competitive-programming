#include<iostream>
#include<vector>
#include <stack>
#include<string>
#include <queue>
#include<algorithm>

using namespace std;

class TrieNode {

    public:
        TrieNode * children[26];
        bool end_of_word;
        char letter;
        bool visited;
        priority_queue<int, vector<int>, greater<int>> children_idx;
        priority_queue<int, vector<int>, greater<int>> aux;
        TrieNode () {

            end_of_word = visited = false;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            letter = '\0';
        }
};

class Trie {

    private:
        TrieNode root;
    public:

        // Insert the word in the trie
        void Insert (string str) {

            TrieNode * current = &root;
            for (size_t i = 0; i < str.size(); i++) {
                if (current->children[str.at(i)-'a'] == NULL) {
                    current->children[str.at(i)-'a'] = new TrieNode;
                    current->children_idx.push(str.at(i)-'a');
                    current->children[str.at(i)-'a']->letter = str.at(i);
                }
                current = current->children[str.at(i)-'a'];
            }
            // current->aux = current->children_idx;
            current->end_of_word = true;
        }

        // Search the word in trie
        TrieNode *Search (string str) {
            TrieNode *current = &root;
            for (size_t i = 0; i < str.size(); i++) {
                if (current->children[str.at(i)-'a'] != NULL) {
                    current = current->children[str.at(i)-'a'];
                } else {
                    return NULL;
                }
            }
            if (current->end_of_word == true)
                return current;
            return current;
        }
        void dfs_rec_aux(string &curr_str, TrieNode *curr, int &depth){
            curr->visited = true;
            curr->aux = curr->children_idx;
            curr_str.push_back(curr->letter);
            if(curr->end_of_word){
                cout<<curr_str<<endl;
            }
            while(!curr->aux.empty()){
                if(!curr->children[curr->aux.top()]->visited){
                    depth++;
                    dfs_rec_aux(curr_str,curr->children[curr->aux.top()], depth);
                }
                curr->aux.pop();
            }
            //se eliminan los caracteres del string para continuar con
            //el siguiente string a imprimir del trie
            curr_str.pop_back();
            curr->visited = false;
        }

        int dfs_rec(string str){
            TrieNode *root = Search(str);
            if(root == NULL){
                return 0;
            }
            //string que se le añaden caracteres del trie por el dfs
            string curr_str = str;
           
            bool was_end = false;
            //para que no se imprima el string actual, ej input contiene set
            //y se busca set, este no se imprime
            if(root->end_of_word){
                root->end_of_word = false;
                was_end = true;
            }
            curr_str.pop_back();
            //para ver si el string actual es hoja
            int depth = 0;
            dfs_rec_aux(curr_str, root, depth);
            if(was_end) root->end_of_word = true;
            //Si string actual era hoja, se imprimirá No match.
            if(depth == 0) return 0;
            return 1;
        }
        //DFS iterativo, no funciona!
        int dfs(string str){
            TrieNode *root = Search(str);
            if(root == NULL){
                return -1;
            }
            stack<TrieNode*> visited;
            visited.push(root);
            string curr_str = str;
            while(!visited.empty()){
                TrieNode *current = visited.top();
                visited.pop();
                if(!current->visited){
                    curr_str.push_back(current->letter);
                    if(current->end_of_word){
                        cout<<curr_str<<endl;
                    }
                    current->visited = true;
                }
                while(!current->children_idx.empty()){
                    cout<<current->children_idx.top()<<endl;
                    if(!current->children[current->children_idx.top()]->visited)
                        visited.push(current->children[current->children_idx.top()]);
                    current->children_idx.pop();
                }
            }
        }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    string s;
    Trie trie;
    for(int i = 0; i < N; i++){
        cin>>s;
        trie.Insert(s);
    }
    cin>>N;
    for(int i = 1; i <= N; i++){
        cin>>s;
        cout<<"Case #"<<i<<":"<<endl;
        int found = trie.dfs_rec(s);
        if(found == 0){
            cout<<"No match."<<endl;
        }
    }
    return 0;
}