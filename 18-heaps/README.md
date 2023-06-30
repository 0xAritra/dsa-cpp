# Heaps / Priority Queue

- Eg: Vaccination drive - priority is given to aged people etc!
- TOP k elements out of N elements
- insert: O(logN)
- popMax, popMin: O(logN)
- getMax, getMin: O(1)

## Heaps - as CBT

- Binary Tree
- Complete Binary Tree (CBT) - tree w/ nodes at same level except leaf but filled L to R
- Heap order property (root >= children)

* tree has relationship b/w parent and children
* insertion - first find the place to insert by level order traversal - O(N) - so bad choice!

## Heaps - as Arrays

```
            ______100_______
           /                \
       __40__              __50__
      /      \            /      \
    20        30         15       X
---
       ______1_______
      /              \
    _2_             __3__
   /   \           /     \
  4     5         6       X

```

```
{X, 100, 40, 50, 20, 30, 15}
- Children = 2*i, 2*i + 1
- Parent: i / 2
```
