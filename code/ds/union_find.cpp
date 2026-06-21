// Time complexity: ˜= O(1)
// Memory complexity: O(n)

class UnionFind{
    vector<int> parent;
    vector<int> setSize;
public:
    UnionFind(int size){
        parent.resize(size);
        setSize.assign(size, 1);
        iota(parent.begin(), parent.end(), 0); // If needed to index by 1, size = size+1
    }

    int find(int i){
        return parent[i] == i ? i : parent[i] = find(parent[i]);
    }

    bool join(int I, int J){
    int i = find(I), j = find(J);
    if(i == j) return false;
    
    if(setSize[i] < setSize[j]) swap(i, j);
    
    parent[j] = i; 
    
    setSize[i] += setSize[j]; 
    return true;
}

    int size(int i){ return setSize[find(i)]; }
};
