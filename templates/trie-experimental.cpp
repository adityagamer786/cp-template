struct Trie {
	Trie* child[2];
	int cnt;
	Trie () {
		child[0] = child[1] = nullptr;
		cnt = 0;
	}
};
 
void insert (Trie* node, int val) {
	for (int i = 34; i >= 0; --i) {
		int c = (val >> i) & 1;
		if (!node->child[c]) node->child[c] = new Trie ();
		node = node->child[c];
		if (c) {
			node->cnt++;
			return; // dont need to go any further
		}
	}
}
 
int query (Trie* node, int val) {
	int ans = 0;
	set< int > s;
	for (int i = 34; i >= 0; --i) {
		int c = (val >> i) & 1;
		if (!node->child[c]) return ans;
		node = node->child[c];
		if (c) {
			ans += node->cnt;
			return ans;
		}
	}
	return ans;
}
