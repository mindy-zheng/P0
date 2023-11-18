For P0, I will be implementing my code in C++. 

__How To Compile P0__
I have created a Makefile for this project. Here's how you run it: 
1. run 'make' 
2. To test out the keyboard: ./P0 
	When you are finished typing your data, make sure to exit with Ctrl+D. 
3. To test out file (input.f23): ./P0 input
	The program will automatically append .f23 extension. 
4. If you enter ./P0 input.f23, this will also work. 
5. If the file is empty, know that there will be an error message.

** I have included error and validation checks for checking inputFile's content. The input data should all be strings made up of letters and digits only. ** 

**Structure**
For the project, I have my main function (P0.cpp), tree functions (tree.cpp), tree header files (tree.h) and your node type defintion (node.h)

My tree.cpp file  will have the functions: buildTree(), printInorder(), printPreorder(), and printPostorder(). 

My main function, P0.cpp, will read data from an input file or my keyboard, insert them into the Binary Search Tree functions and output three files corresponding to the three different tree traversals. 

For keyboard input: 
Traversals will be printed as out.[traversaltype]

For files: 
Traversals will be printed as [filename].[traversaltype]
