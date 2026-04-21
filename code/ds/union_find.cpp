int find(vector<int>& union_find, int a) {
    vector<int> path;

    while(union_find[a] >= 0){
        path.push_back(a);
        a = union_find[a];
    }

    for(int vertice : path)
        union_find[vertice] = a;

    return a;
}

void unite(vector<int>& union_find, int a, int b) {
    a = find(union_find, a);
    b = find(union_find, b);

    if(a == b) return;

    if(abs(union_find[a]) < abs(union_find[b])) swap(a, b);

    union_find[a]+=union_find[b];
    union_find[b] = a;
}

// Example usage for Hamming distance problem

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        vector<int> union_find(source.size(), -1);
        unordered_map<int, unordered_map<int, int>> count;
        for(int i = 0; i < allowedSwaps.size(); i++){
            int a = allowedSwaps[i][0];
            int b = allowedSwaps[i][1];
            unite(union_find, a, b);
        }
        for(int i = 0; i < source.size(); i++){
            int group = find(union_find, i);
            count[group][source[i]]++;
            count[group][target[i]]--;
        }
        int ans = 0;
        for(auto& pair : count)
            for(auto& freq : pair.second)
                ans+=abs(freq.second);
        return ans/2;
    }
};