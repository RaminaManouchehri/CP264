/**
 * -------------------------------------
 * @file  bst_linked.c
 * Linked BST Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-03-01
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "bst_linked.h"
#include <math.h>

// Macro for comparing node heights
#define MAX_HEIGHT(a,b) ((a) > (b) ? a : b)

//--------------------------------------------------------------------
// Local Static Helper Functions

/**
 * Initializes a new BST node with a copy of item.
 *
 * @param source - pointer to a BST source
 * @param item - pointer to the item to assign to the node
 * @return a pointer to a new BST node
 */
static bst_node* bst_node_initialize(const data_ptr item) {
	// Base case: add a new node containing a copy of item.
	bst_node *node = malloc(sizeof *node);
	node->item = malloc(sizeof *node->item);
	data_copy(node->item, item);
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/**
 * Helper function to determine the height of node - handles empty node.
 * @param node - The node to process.
 * @return The height of the current node.
 */
static int bst_node_height(const bst_node *node) {
	int height = 0;

	if (node != NULL) {
		height = node->height;
	}
	return height;
}

/**
 * Updates the height of a node. Its height is the max of the heights of its
 * child nodes, plus 1.
 * @param node The node to process.
 */
static void bst_update_height(bst_node *node) {
	int left_height = bst_node_height(node->left);
	int right_height = bst_node_height(node->right);

	node->height = MAX_HEIGHT(left_height, right_height) + 1;
	return;
}

/**
 * Inserts item into a BST. Insertion must preserve the BST definition.
 * item may appear only once in source.
 *
 * @param source - pointer to a BST
 * @param node - pointer to a node
 * @param item - the item to insert
 * @return - TRUE if item inserted, FALSE otherwise
 */
static BOOLEAN bst_insert_aux(bst_linked *source, bst_node **node,
		const data_ptr item) {
	BOOLEAN inserted = FALSE;

	if (*node == NULL) {
		// Base case: add a new node containing the item.
		*node = bst_node_initialize(item);
		source->count += 1;
		inserted = TRUE;
	} else {
		// Compare the node data_ptr against the new item.
		int comp = data_compare(item, (*node)->item);

		if (comp < 0) {
			// General case: check the left subsource.
			inserted = bst_insert_aux(source, &(*node)->left, item);
		} else if (comp > 0) {
			// General case: check the right subsource.
			inserted = bst_insert_aux(source, &(*node)->right, item);
		}
	}
	if (inserted) {
		// Update the node height if any of its children have been changed.
		bst_update_height(*node);
	}
	return inserted;
}

//--------------------------------------------------------------------
// Functions

// Initializes a BST.
bst_linked* bst_initialize() {
	bst_linked *source = malloc(sizeof *source);
	source->root = NULL;
	source->count = 0;
	return source;
}

// frees a BST.
void bst_free_aux(const bst_node *node) {
	if (node == NULL) {
		return;
	}

	bst_free_aux(node->left);
	bst_free_aux(node->right);
	data_free(&(node->item));

	free(node);
}
void bst_free(bst_linked **source) {
	if (source == NULL || *source == NULL) {
		return;
	}

	bst_free_aux((*source)->root);
	free(*source);
	*source = NULL;
}

// Determines if a BST is empty.
BOOLEAN bst_empty(const bst_linked *source) {
	return (source->count == 0);
}

// Determines if a BST is full.
BOOLEAN bst_full(const bst_linked *source) {
	return FALSE;
}

// Returns number of items in a BST.
int bst_count(const bst_linked *source) {
	return source->count;
}
static void bst_inorder_aux(const bst_linked *source, const bst_node *node,
		data_ptr *items, int *index) {
	if (node != NULL) {
		if (node->left != NULL) {
			bst_inorder_aux(source, node->left, items, index);
		}
		items[*index] = node->item;
		(*index)++;
		if (node->right != NULL) {
			bst_inorder_aux(source, node->right, items, index);
		}
	}
	return;
}

// Copies the contents of a BST to an array in inorder.
void bst_inorder(const bst_linked *source, data_ptr *items) {

	// your code here
	int index = 0;
	bst_inorder_aux(source, source->root, items, &index);

	return;
}
void bst_preorder_aux(const bst_linked *source, const bst_node *node,
		data_ptr *items, int *index) {
	if (node != NULL) {
		items[*index] = node->item;
		(*index)++;
		if (node->left != NULL) {
			bst_preorder_aux(source, node->left, items, index);
		}
		if (node->right != NULL) {
			bst_preorder_aux(source, node->right, items, index);
		}
	}

}

// Copies the contents of a BST to an array in preorder.
void bst_preorder(const bst_linked *source, data_ptr *items) {

	// your code here
	int index = 0;
	bst_preorder_aux(source, source->root, items, &index);

	return;
}
static void bst_postorder_aux(const bst_linked *source, const bst_node *node,
		data_ptr *items, int *index) {
	if (node != NULL) {
		if (node->left != NULL) {
			bst_postorder_aux(source, node->left, items, index);

		}
		if (node->right != NULL) {
			bst_postorder_aux(source, node->right, items, index);

		}
		items[*index] = node->item;
		(*index)++;
	}
	return;
}

// Copies the contents of a BST to an array in postorder.
void bst_postorder(const bst_linked *source, data_ptr *items) {

	// your code here
	int index = 0;
	bst_postorder_aux(source, source->root, items, &index);

	return;
}

// Inserts a copy of an item into a BST.
BOOLEAN bst_insert(bst_linked *source, const data_ptr item) {
	return bst_insert_aux(source, &(source->root), item);
}

// Retrieves a copy of a value matching key in a BST.
BOOLEAN bst_retrieve(bst_linked *source, const data_ptr key, data_ptr item) {

	// your code here
	bst_node *curr = source->root;
	BOOLEAN returned = FALSE;
	while (curr != NULL && (!returned)) {
		int comp = data_compare(curr->item, key);
		if (comp == 0) {
			data_copy(item, curr->item);
			returned = TRUE;
		} else if (comp < 0) {
			curr = curr->right;
		} else {
			curr = curr->left;
		}
	}

	return returned;
}

// Removes a value matching key in a BST.
BOOLEAN bst_remove(bst_linked *source, const data_ptr key, data_ptr item) {

	// your code here

	return FALSE;
}

// Copies source to target.
void bst_copy(bst_linked **target, const bst_linked *source) {

	// your code here

}

// Finds the maximum item in a BST.
BOOLEAN bst_max(const bst_linked *source, data_ptr item) {

	// your code here
	BOOLEAN found = FALSE;
	if (source != NULL) {
		bst_node *curr = source->root;
		while (curr->right != NULL) {
			curr = curr->right;
			found = TRUE;
		}
		data_copy(item, curr->item);
	}

	return found;
}

// Finds the minimum item in a BST.
BOOLEAN bst_min(const bst_linked *source, data_ptr item) {

	// your code here
	BOOLEAN found = FALSE;
	if (source != NULL) {
		bst_node *curr = source->root;
		while (curr->left != NULL) {
			curr = curr->left;
			found = TRUE;
		}
		data_copy(item, curr->item);
	}

	return found;
}

// Finds the number of leaf nodes in a tree.
static void bst_leaf_count_aux(const bst_node *node, int *count) {
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL) {
			(*count)++;
		}
		bst_leaf_count_aux(node->right, count);
		bst_leaf_count_aux(node->left, count);

	}
	return;
}
int bst_leaf_count(const bst_linked *source) {

	// your code here
	int count = 0;
	bst_leaf_count_aux(source->root, &count);

	return count;
}
static void bst_one_child_count_aux(const bst_node *node, int *count) {
	if (node != NULL) {
		if ((node->left == NULL && node->right != NULL)
				|| (node->left != NULL && node->right == NULL)) {
			(*count)++;

		}
		bst_one_child_count_aux(node->right, count);
		bst_one_child_count_aux(node->left, count);
	}
	return;
}
// Finds the number of nodes with one child in a tree.
int bst_one_child_count(const bst_linked *source) {

	// your code here
	int count = 0;
	bst_one_child_count_aux(source->root, &count);

	return count;
}

static void bst_two_child_count_aux(const bst_node *node, int *count) {
	if (node != NULL) {
		if (node->left != NULL && node->right != NULL) {
			(*count)++;
		}
		bst_two_child_count_aux(node->left, count);
		bst_two_child_count_aux(node->right, count);

	}
	return;
}
// Finds the number of nodes with two children in a tree.
int bst_two_child_count(const bst_linked *source) {

	// your code here
	int count = 0;
	bst_two_child_count_aux(source->root, &count);

	return count;
}
static void bst_node_counts_aux(const bst_node *node, int *zero, int *one,
		int *two) {
	if (node != NULL) {
		if ((node->left == NULL && node->right != NULL)
				|| (node->left != NULL && node->right == NULL)) {
			(*one)++;
		}
		if (node->left == NULL && node->right == NULL) {
			(*zero)++;
		}
		if (node->left != NULL && node->right != NULL) {
			(*two)++;
		}
		bst_node_counts_aux(node->left, zero, one, two);
		bst_node_counts_aux(node->right, zero, one, two);
	}
	return;
}
// Determines the number of nodes with zero, one, and two children.
// (May not call bst_leaf_count, bst_one_child_count, or bst_two_child_count.)
void bst_node_counts(const bst_linked *source, int *zero, int *one, int *two) {

	// your code here
	bst_node_counts_aux(source->root, zero, one, two);
	return;
}
static void bst_balanced_aux(const bst_node *node, BOOLEAN *balanced) {
	if (node != NULL) {
		int heightl = 0;
		int heightr = 0;
		if (node->left != NULL) {
			heightl = bst_node_height(node->left);
		} else {
			heightl = 0;
		}
		if (node->right != NULL) {
			heightr = bst_node_height(node->right);
		} else {
			heightr = 0;
		}
		if (abs(heightl - heightr) <= 1) {
			*balanced = TRUE;
			bst_balanced_aux(node->left, balanced);
			bst_balanced_aux(node->right, balanced);
		} else {
			*balanced = FALSE;
			return;
		}

	}
}
// Determines whether or not a tree is a balanced tree.
BOOLEAN bst_balanced(const bst_linked *source) {

	// your code here]
	BOOLEAN balanced = TRUE;
	bst_balanced_aux(source->root, &balanced);

	return balanced;
}

// Determines whether or not a tree is a valid BST.
BOOLEAN bst_valid(const bst_linked *source) {

	// your code here

	return FALSE;
}
static void bst_equals_aux(const bst_node *tnode, const bst_node *snode,
		BOOLEAN *equals) {
	if (tnode != NULL && snode != NULL) {
		if (tnode == NULL || snode == NULL) {
			*equals = FALSE;
			return;
		} else {
			if (*snode->item == *tnode->item) {
				*equals = TRUE;
			} else {
				*equals = FALSE;
				return;
			}
		}
		bst_equals_aux(tnode->left, snode->left, equals);
		bst_equals_aux(tnode->right, snode->right, equals);

	}
	return;
}
// Determines if two trees contain same data in same configuration.
BOOLEAN bst_equals(const bst_linked *target, const bst_linked *source) {

	// your code here
	BOOLEAN equals = TRUE;
	bst_equals_aux(target->root, source->root, &equals);

	return equals;
}

/**
 * Private helper function to print contents of BS in preorder.
 *
 * @param to_string - function to print data_ptr
 * @param node - pointer to bst_node
 */
static void bst_print_aux(bst_node *node) {
	char string[DATA_STRING_SIZE];

	if (node != NULL) {
		printf("%s\n", data_string(string, DATA_STRING_SIZE, node->item));
		bst_print_aux(node->left);
		bst_print_aux(node->right);
	}
	return;
}

// Prints the items in a BST in preorder.
void bst_print(const bst_linked *source) {
	printf("  count: %d, height: %d, items:\n", source->count,
			source->root->height);
	bst_print_aux(source->root);
	printf("\n");
	return;
}
