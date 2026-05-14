## Assignment: Implement a Binary Search Tree (BST) in C

### Difficulty

Intermediate

### Goal

Implement a **Binary Search Tree** library in C that supports:

* insertion
* deletion
* search
* traversals
* min/max lookup
* tree height calculation

This assignment teaches:

* pointers
* recursion
* dynamic memory management
* tree algorithms
* modular C design

---

# Project Structure

```text id="v3jqcf"
bst.h
bst.c
main.c
Makefile
```

---

# Data Structure

## Node Definition

```c id="3m6tmg"
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;
```

---

# Required Functions

## Create a Node

```c id="slqg2k"
Node* create_node(int value);
```

Allocates memory and initializes fields.

---

## Insert

```c id="vt5ofw"
Node* insert(Node* root, int value);
```

Rules:

* values smaller go left
* larger values go right
* ignore duplicates

---

## Search

```c id="mr91wj"
Node* search(Node* root, int value);
```

Return:

* pointer to node if found
* `NULL` otherwise

---

## Delete

```c id="lnfm4l"
Node* delete(Node* root, int value);
```

Handle all 3 cases:

1. leaf node
2. one child
3. two children

For case 3:

* replace with inorder successor

---

## Traversals

### Inorder

```c id="aq1tyu"
void inorder(Node* root);
```

Output should be sorted.

---

### Preorder

```c id="9qit2s"
void preorder(Node* root);
```

---

### Postorder

```c id="0w59kw"
void postorder(Node* root);
```

---

## Find Minimum

```c id="31f3rz"
Node* find_min(Node* root);
```

---

## Find Maximum

```c id="m3d9ng"
Node* find_max(Node* root);
```

---

## Height of Tree

```c id="gn6fxq"
int height(Node* root);
```

---

## Free Memory

```c id="mewzyd"
void free_tree(Node* root);
```

Must free all allocated nodes.

---

# Example Usage

```c id="1c7trf"
Node* root = NULL;

root = insert(root, 50);
root = insert(root, 30);
root = insert(root, 70);
root = insert(root, 20);
root = insert(root, 40);

inorder(root);
```

Expected output:

```text id="6nrn0x"
20 30 40 50 70
```

---

# Required Tests

## Test Cases

### Insert + Search

* insert several values
* verify search works

### Traversals

Verify correct order.

### Delete

Test deleting:

* leaf
* node with one child
* node with two children

### Edge Cases

* empty tree
* duplicate insertion
* deleting missing value

---

# Build System

Your `Makefile` should support:

```bash id="swf5t6"
make
make run
make clean
```

---

# Complexity Analysis

Document time complexity for:

* insert
* search
* delete

Explain:

* best case
* average case
* worst case

---

# Bonus Features (Optional)

Choose one:

## 1. Iterative Traversal

Use a stack instead of recursion.

---

## 2. Pretty Print Tree

Example:

```text id="vw0w3g"
      50
     /  \
   30    70
```

---

## 3. Save/Load Tree from File

---

## 4. AVL Tree Upgrade

Balance the tree automatically.

---

# Deliverables

* source code
* Makefile
* README
* sample output

---

# Learning Outcomes

After this assignment you should understand:

* recursive data structures
* dynamic allocation
* pointer manipulation
* tree algorithms
* modular C programming

If you want, I can also give:

* an easier linked-list assignment
* a harder AVL/red-black tree assignment
* starter code
* test cases
* a full solution
* diagrams explaining BST operations
