# Introduction

This programming project provides an very basic implementation and a prompt-based testing suite for an AVL Tree.

An **AVL Tree** (named after inventors Adelson-Velsky-Landis) is a self-balancing **Binary Search Tree (BST)**, which is a node-based BST that automatically keeps its height in logarithmic size in relation to its number of nodes. It is the first kind of self-balancing tree to be invented.

Consider the balance factor of a given node $N$ to be defined as the difference between the height of its right subtree and its left subtree. The AVL Tree holds an invariant for the balance factor of every node in the tree, making it so that no node can have a balance factor that isn't in the set $\{-1, 0, 1 \}$.

Should any node ever get unbalanced from an insertion or deletion operation, the tree will reajust itself by performing a rebalancing operation. These are called rotations, and they'll change the structure of the tree in such a way that solves the unbalancing. There are four types: right rotation, left rotation, double right rotation and double left rotation, and these are performed accordingly to a set of rules based on the balance factor. The user cannot prompt a rotation by himself, as they are an internal mechanism, but you can cause a proposital unbalancing and print the tree if you want to see the final results of the rebalancing.

This implementation provides an AVL Tree with integer keys, and only for that, unfortunately. It provides implementation for: inserting a new integer key, deleting an existing integer, searching for an existing key and printing all the nodes in a tree-like fashion in the console, all of that via the testing suite in the prompt. It's very intuitive, so you can just run and test.

The tests are "not really tests". It's just a testing suite, a loop prompt that asks for the user for actions to perform on the tree, as per stated above. You can quit anytime by typing the exit code.

# Organization

The folders and files of this project are the following:

* `source/tests`: This folder has the file `main.cpp` that contains the testing suite. It's not using any testing lib, but instead asks from the user which operations to execute.
* `source/include`: This folder has the files `avl_tree.h` and `node.h`, which implements the AVL Tree and its Node.
* `source/CMakeLists.txt`: The CMake script file.
* `README.md`: This file.

# Compiling

This project may be compiled with [CMake](https://cmake.org). CMake is an open-source, cross-platform family of tools designed to build, test and package software. Basically, CMake reads a script (`CMakeLists.txt`) with meta-information on the project and **creates a Makefile automatically**, tailored to your system configuration.
After that, you may run the `make` command, as usual.
Alternatively, the same script might be used to create Xcode projects, Ninja, or Microsoft Visual Studio projects, for instance.

CMake supports **out-of-source** build. This means the _source code_ is stored in **one** folder and the _generated executable files_ should be stored in **another** folder: project should never mix-up the source tree with the build tree.

In particular, this project creates a single **target** (executable), called `test_suite`.

But don't worry, they are already set up in the `CMakeLists.txt` script.

To compile this project with [CMake](https://cmake.org) follow these steps (from the root folder):

1. `cmake -S source -B build`:  asks CMake to create the build directory and generate the Unix Makefile based on the script found in `source/CMakeLists.txt`, on the current level.
3. `cmake --build build`: triggers the compiling process that creates both targets (executable).D inside `build`.

The executable is created inside the `build` directory.

For further details, please refer to the [CMake documentation website](https://cmake.org/cmake/help/v3.14/manual/cmake.1.html).

# Running

From the project's root folder, run as usual (assuming `$` is the terminal prompt):

```
$ ./build/test_suite
```
