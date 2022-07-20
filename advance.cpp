
// Online IDE - Code Editor, Compiler, Interpreter

#include<bits/stdc++.h>

using namespace std;

int main()
{
    // Vector container
    std::vector<int> vec;
 
    // Initialising vector
    for (int i = 0; i < 10; i++)
        vec.push_back(i * 10);
 
    // Printing the vector elements
    for (int i = 0; i < 10; i++) {
        std::cout << vec[i] << " ";
    }
 
    std::cout << std::endl;
 
    // Declaring the vector iterator
    std::vector<int>::iterator it = vec.begin();
 
    // Printing alternate elements
    while (it < vec.end()) {
        std::cout << *it << " ";
        std::advance(it, 2);
    }
    int ser=20;
    it = std::find (vec.begin(), vec.end(), ser);
    if (it != vec.end())
    {
        std::cout << "Element " << ser <<" found at position : " ;
        std::cout << it - vec.begin() << " (counting from zero) \n" ;
    }
    else
        std::cout << "Element not found.\n\n";
    return 0;
}
