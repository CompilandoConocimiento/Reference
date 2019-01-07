template <typename integer, typename unsignedInteger>
integer RecursiveBinaryExp (integer x, unsignedInteger n) {
    if (n == 0) return 1;                                         
    if (n == 1) return x;                                           

    if (n % 2 == 0) return RecursiveBinaryExp(x * x,  n / 2);           
    else return (x * RecursiveBinaryExp(x * x, (n-1) / 2));  
}

template <typename integer, typename unsignedInteger>
integer SimpleBinaryExponentation (integer base, unsignedInteger exponent) {                  
    integer solution {1};                                               

    while (exponent > 0) {
        if (exponent % 2) {
            solution = base * solution;
            base = base * base;                            
        }                                
        else base = base * base;                            

        exponent = exponent / 2;                    
    }

    return solution;                              
}

template <typename integer, typename unsignedInteger>
integer BinaryExponentation (integer base, unsignedInteger exponent) {                  
    integer solution {1};                                               

    while (exponent > 0) {                                
        if (exponent & 1) solution = base * solution; 

        base = base * base;                            
        exponent = exponent >> 1;                    
    }

    return solution;                              
}

template <typename integer, typename uinteger>
integer ModularBinaryExponentation(integer base, uinteger exponent, uinteger n) {     
    integer solution {1};                                               
    base = base % n;                                            

    while (exponent > 0) {                                          
        if (exponent & 1) solution = (base * solution) % n;         
        
        base = (base * base) % n;                                   
        exponent = exponent >> 1;                                   
    }

    return solution;                                                
}
