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
        void dfs_rec_aux(TrieNode *curr, float &strokes, float &sum){
            curr->visited = true;
            curr->aux = curr->children_idx;
            if(curr != &root && curr->children_idx.size() > 1 && !curr->end_of_word){
                strokes++;
            }
            if(curr->end_of_word){
                strokes++;
                sum += strokes;
            }
            while(!curr->aux.empty()){
                if(!curr->children[curr->aux.top()]->visited){
                    dfs_rec_aux(curr->children[curr->aux.top()], strokes, sum);
                }
                curr->aux.pop();
            }
            if(curr->end_of_word || curr->children_idx.size() > 1){
                strokes--;
            }
        }

        int dfs_rec(int N){
            TrieNode *aux = &root;
            if(aux == NULL){
                return 0;
            }           
            float strokes = 0.000, sum = 0.000;
            dfs_rec_aux(aux, strokes, sum);
            if(sum == 0) return 0;
            printf("%.2lf\n", static_cast<double>(sum)/(double)N);
            return 1;
        }
};


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int N;
    string s;
    while(cin>>N){
        Trie trie;
        for(int i = 0; i < N; i++){
            cin>>s;
            trie.Insert(s);
        }
        trie.dfs_rec(N);
    }
    return 0;
}