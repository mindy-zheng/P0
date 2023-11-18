#include <iostream> 
#include "node.h"
#include "tree.h" 
#include <fstream>
#include <sstream> 
#include <cctype> 

using namespace std; 
// Function prototypes
void outputPreorder(Node *root, std::string filename); 
void outputPostorder(Node *root, std::string filename); 
void outputInorder(Node* root, std::string filename); 

int main(int argc, char* argv[]) {
	ifstream inFile; 
	string file;  
	string line; 
	Node* root = nullptr; // Root 
	
	//Input file
	if (argc > 1) { 
		file = string(argv[1]); // stores command line argument 
		// If last 4 characters aren't .f23, then append .f23 
		if (file.substr(file.size()-4) != ".f23") {
			file += ".f23"; 
		} 
		inFile.open(file); 
		if (!inFile) {
			cout << "Unable to open " << file << endl; 
			return 1;  
		} 
		// If file is empty: 
		if (inFile.peek() == ifstream::traits_type::eof()) { 
			cout << "Error: file is empty." << endl;
			return 1; 
		}
	}
	
	// Tokenize line into words from file and keyboard 
	if (inFile.is_open()) { 
		while (getline(inFile, line)) { 
			istringstream iss(line); 
			string word; 
			while (iss >> word) { 
				bool valid = true; 
				for (int i = 0; i < word.length(); i++) { 
					char c = word[i]; 
					if (!isalnum(c)) { 
						valid = false; 
						break;
					}
				} 
				if (valid) {  		
					root = buildTree(root, word);  
		} else { 
			cout << "Your input file must have only letters and digits" << endl; 
			cout << "Invalid input here: " << word << endl; 
			return 1; 
		}
	}	
}
		inFile.close(); 
	} else { 
		while (getline(cin, line)) { 
			istringstream iss(line); 
			string word; 
			while (iss >> word) {
				bool valid = true;  
				for (int i = 0; i < word.length(); i++) {
					char c = word[i]; 
					if (!isalnum(c)) { 
						valid = false; 
						break; 
					} 
				}
				if (valid) { 
				root = buildTree(root, word); 
			} else { 
			cout << "Your input should only have letters and digits" << endl; 
			cout << "Invalid input here: " << word << endl; 
			return 1; 
			}
		}
	}
}
	string filename; 
	if (argc > 1) { 
		filename = argv[1]; 
	} else { 
		filename = "out"; 
	} 
	
	//write to files 
	outputPreorder(root, filename + ".preorder"); 
	outputInorder(root, filename + ".inorder"); 
	outputPostorder(root, filename + ".postorder"); 


	return 0; 
}


// Functions for outputting preorder, inorder, and postorder, with extensions
void outputPreorder(Node *root, string filename) { 
	ofstream preorder(filename);
        if (!preorder) {
                cout << "Unable to open .preorder for output" << endl;
                exit(1); 
        }

	printPreorder(root, preorder); 
	preorder.close(); 
} 

void outputInorder(Node *root, string filename) { 
	string inorderFile = filename;
        ofstream inorder(inorderFile);
        if (!inorder) {
                cout << "Unable to open .inorder for output" << endl;
                exit(1);
        }

        printInorder(root, inorder);
        inorder.close();
} 

void outputPostorder(Node *root, string filename) { 
	string postorderFile = filename;
        ofstream postorder(postorderFile);
        if (!postorder) {
                cout << "Unable to open .postorder for output" << endl;
                exit(1); 
        }

        printPostorder(root, postorder);
        postorder.close();

}	

