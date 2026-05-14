#include <stdlib.h>

#include "bst.h"

node_t *node_create(T value) {
    node_t *new = malloc(sizeof(node_t));
    if (!new) return NULL;

    new->value = value;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void node_destroy(node_t *node) {
    if (!node) return;

    node_destroy(node->left);
    node_destroy(node->right);
    free(node);
}

node_t *node_insert(node_t *root, T value) {
    if (!root) {
        return node_create(value);
    }

    if (value < root->value) {
        root->left = node_insert(root->left, value);
    } else if (value > root->value) {
        root->right = node_insert(root->right, value);
    }

    return root;
}

node_t *node_search(node_t *root, T value);
