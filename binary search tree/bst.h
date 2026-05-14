#ifndef BINARY_SEARCH_TREE_AARONK9005_H
#define BINARY_SEARCH_TREE_AARONK9005_H

typedef int T;

typedef struct node_t {
    T value;
    struct node_t* left;
    struct node_t* right;
} node_t;

node_t* node_create(T value);

void node_destroy(node_t* node);

node_t* node_insert(node_t* root, T value);

node_t* node_search(node_t* root, T value);

#endif