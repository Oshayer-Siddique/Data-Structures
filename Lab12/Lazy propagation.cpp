#include <iostream>
#include <vector>

typedef long long i64;

class SegmentTree {
private:
    struct Node {
        i64 prop, sum;
    };

    std::vector<Node> tree;
    int mx;

    void update(int node, int b, int e, int i, int j, i64 x) {
        if (i > e || j < b)
            return;
        if (b >= i && e <= j) {
            tree[node].sum += ((e - b + 1) * x);
            tree[node].prop += x;
            return;
        }
        int Left = node * 2;
        int Right = (node * 2) + 1;
        int mid = (b + e) / 2;
        update(Left, b, mid, i, j, x);
        update(Right, mid + 1, e, i, j, x);
        tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
    }

public:
    SegmentTree(int size) : mx(size), tree(size * 3) {}

    void updateRange(int i, int j, i64 x) {
        update(1, 1, mx, i, j, x);
    }
};

int main() {
    // Example usage
    int mx = 10; // Adjust the size as needed
    SegmentTree segTree(mx);

    

    // Update the range [2, 5] with value 3
    segTree.updateRange(2, 5, 3);

    return 0;
}
