/**
 * Author:
 * Date:
 * License:
 * Source:
 * Time: O(mk) memory, O(m) complexity.
 * Description: Basic trie.
 * Status: 
 */
const int K = 26;
struct Vertex {
    int next[K];
    bool output = false;
    Vertex() { fill(begin(next), end(next), -1); }
};
void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        } v = trie[v].next[c];
    } trie[v].output = true;
}
vector<Vertex> trie(1);
