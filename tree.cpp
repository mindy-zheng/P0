#include <iostream>
#include <set>
#include <string> 
#include <fstream> 
#include "node.h" 

using namespace std; 

// 1. Build the tree
Node* buildTree(Node* node, const string& str) { 
	// Assign node to root if tree is empty 
	if (node == nullptr) { 
		node = new Node(); // Root of tree 
		node->length = str.length(); // each node represents strings of diff lengths 
		node->unique_str.insert(str); // ensures uniqueness
		node->left = node->right = 0; 
	} else if (node->length > str.length()) {  // left subtree
		node->left = buildTree(node->left, str); 
	} else if (node->length < str.length()) { // Right subtree 
		node->right=buildTree(node->right, str); 
	} else { 
		node->unique_str.insert(str); //Insert string into node's set
	} 
	return node; 
} 

// Recursive function to print Pre-order tree traversals
// 1. visit 2. left 3. right 
void printPreorder(Node* node, ofstream& output, int level = 0) { 
	if (node == nullptr) { 
		return; 
	} 
	
	// Print level (indented by 2x level)
	for (int i = 0; i < level; ++i) {
		output << "  "; // 2 spaces or indentations 
	} 

	//Print the length 
	output << node->length << ": "; 

	//Print strings in node 
	for (const auto& str : node-> unique_str) { 
		output << str << " "; 
	} 
	output << "\n"; 

	// Recursively call left and right subtrees: 
	printPreorder(node->left, output, level + 1); 
	printPreorder(node->right, output, level + 1); 

}

// Recursive function to print Inorder tree traversals 
// 1. left 2. visit 3. right
void printInorder(Node *node, ofstream &output, int level = 0) { 
	if (node == nullptr) { 
		return; 
	} 
	// Print left subtree
	printInorder(node->left, output, level + 1); 
	
	// Depth
	for (int i = 0; i < level; ++i) { 
		output << "  "; // 2x indentation 
	} 

	// visit and length 
	output << node->length << ": "; 	

	for (const auto &str : node-> unique_str) { 
		output << str << " "; 
	} 
	
	output << "\n"; 
	
	// Print right subtree
	printInorder(node->right, output, level + 1); 

} 

// Recursive function to print postorder tree traversals 
// 1. left 2. right 3. visit 
void printPostorder(Node* node, ofstream& output, int level = 0) { 
	if (node == nullptr) {
        	return;
   	}

	// Print left subtree
	printPostorder(node->left, output, level + 1);
	// Print right subtree 
	printPostorder(node->right, output, level + 1);
	// Visit 
	for (int i = 0; i < level; ++i) {
                output << "  "; // 2x indentation
        }


        // visit and length
        output << node->length << ": ";
        for (const auto &str : node-> unique_str) {
        	output << str << " ";
        }
        output << "\n";
}






 
