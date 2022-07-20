
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
    return 0;
}
