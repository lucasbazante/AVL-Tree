#include <iostream>
#include "../include/avl_tree.h"

#define QUIT   0
#define INSERT 1
#define REMOVE 2
#define SEARCH 3
#define PRINT  4
#define FLUSH  5

int main() {
    AVLTree tree;
    int entry = -1, key;
    
    while(entry != QUIT) {
        std::cout << "[QUIT   = 0]" << std::endl;
        std::cout << "[INSERT = 1]" << std::endl;
        std::cout << "[REMOVE = 2]" << std::endl;
        std::cout << "[SEARCH = 3]" << std::endl;
        std::cout << "[PRINT  = 4]" << std::endl;
        std::cout << "[FLUSH  = 5]" << std::endl;
        std::cout << "--------> "   << std::endl;
        std::cin >> entry;

        switch(entry) {
            case QUIT: {
                break;
            }
            
            case INSERT: {
                std::cout << std::endl;
                std::cout << "[KEY    = ?]" << std::endl;
                std::cout << "--------> " << std::endl;
                std::cin >> key;
                tree.insert(key);
                break;
            }
            
            case REMOVE: {
                std::cout << std::endl;
                std::cout << "[KEY    = ?]" << std::endl;
                std::cout << "--------> " << std::endl;
                std::cin >> key;
                tree.remove(key);
                break;
            }

            case SEARCH: {
                std::cout << "[KEY    = ?]" << std::endl;
                std::cout << "--------> " << std::endl;
                std::cin >> key;
                auto res = tree.search(key);
                
                if(res != nullptr)
                    std::cout << "[KEY " << res->key << " FOUND]" << std::endl;
                else
                    std::cout << "[KEY NOT FOUND]" << std::endl;

                break;
            }
            
            case PRINT: {
                std::cout << std::endl;
                tree.pretty_print();
                break;
            }

            case FLUSH: {
                std::cout << "\033[2J\033[1;1H";
                break;
            }

            
            default: {
                std::cout << std::endl;
                std::cout << "[INVALID ENTRY]" << std::endl;
                break;
            }
        }

        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
