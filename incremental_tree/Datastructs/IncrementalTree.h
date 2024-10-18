#include "Queue.h"

#define NodeList Queue


typedef struct TreeNode {
    int weight;
    struct TreeNode* parent;
    NodeList* children;
} TreeNode;

typedef struct IncrementalTree {
    TreeNode* root;
} IncrementalTree;