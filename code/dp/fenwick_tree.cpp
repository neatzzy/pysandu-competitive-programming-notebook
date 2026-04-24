// Fenwick Tree to efficiently calculate and update prefix sums of an array of values.
// Time complexity: O(log N) for queries and updates

int sum(int i) {
  int sum = 0;
  while(i > 0) {
    sum += T[i];
    i -= i & -i; // flip the last bit
  }
  return sum;
}

void add(int i, int k) {
  while (i < T.size()) {
    T[i] += k;
    i += i & -i; // add last set bit
  }
}

vi make(vi arr) {
  vi tree = arr;

  for(int i = 0 ; i < tree.size() ; i++) {
    int p = i + (i & -i) // index to parent
    if (p < t.size()) {
        tree[p] = tree[p] + tree[i];
      }
  }
  return tree;
}
