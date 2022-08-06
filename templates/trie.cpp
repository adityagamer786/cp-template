
// Trie: https://github.com/shuvam07/CP-Algorithms/blob/master/Trie.cpp
const int ALPHABET_SIZE = 26;

struct TrieNode{
  struct TrieNode *children[ALPHABET_SIZE];
  bool isEndOfWord;
};

struct TrieNode *getNode(void){
  struct TrieNode *pNode = new TrieNode;
  pNode->isEndOfWord = false;
  for(int i = 0; i < ALPHABET_SIZE; i++)
    pNode->children[i] = NULL;
  return pNode;
};

void insert(struct TrieNode *root, string key){
  struct TrieNode *pCrawl = root;

  for(int i = 0; i < key.length(); i++){
    int index = key[i]-'a';
    if(!pCrawl->children[index])
      pCrawl->children[index] = getNode();
      pCrawl = pCrawl->children[index];
  }
  pCrawl->isEndOfWord = true;
}

struct TrieNode *search(struct TrieNode *root, string key){
  struct TrieNode *pCrawl = root;
  for(int i = 0; i < key.length(); i++){
    int index = key[i]-'a';
    if(!pCrawl->children[index]) return NULL;
    pCrawl = pCrawl->children[index];
  }
  return pCrawl;
};

void dfs(struct TrieNode *curNode, string curString, vector<string> &res){
  for(int letter = 0; letter < ALPHABET_SIZE; letter++){
    if(curNode->children[letter] != NULL){
      string tmp = curString;
      tmp.push_back(letter+'a');
      dfs(curNode->children[letter], tmp, res);
    }
  }
  if(curNode->isEndOfWord) res.push_back(curString);
}

void solve(){
  int k,i, j, q, x, y;
  k = i = j = q = x = y = n = m = -1;
  cin >> n >> q;
  struct TrieNode *root = getNode();
  while(n--){
    string s;
    cin >> s;
    insert(root, s);
  }
  while(q--){
    string s;
    cin >> s;
    struct TrieNode *p = search(root, s);
    if(p == NULL){
      print("No suggestions");
      insert(root, s);
    } else{
      vector<string> res;
      dfs(p,s,res);
      each(a, res) print(a);
    }
  }
}