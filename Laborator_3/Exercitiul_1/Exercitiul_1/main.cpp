#include "Math.h"
#include <iostream>
#include <cstring>
int main()
{
    Math math;
    std::cout << math.Add(4, 94) << std::endl;
    std::cout << math.Add(6, 1, 3) << std::endl;
    std::cout << math.Add(4.5, 1.5) << std::endl;
    std::cout << math.Add(4.1, 1.2, 4.3) << std::endl << std::endl;
    
    std::cout << math.Mul(4, 94) << std::endl;
    std::cout << math.Mul(6, 1, 3) << std::endl;
    std::cout << math.Mul(4.5, 1.5) << std::endl;
    std::cout << math.Mul(4.1, 1.2, 4.3) << std::endl << std::endl;

    std::cout << math.Add(4, 1, 3, 4, 5 ) << std::endl;
    std::cout << math.Add("Ana are", " mere") << std::endl;
}

