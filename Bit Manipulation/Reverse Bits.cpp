unsigned int Solution::reverse(unsigned int A) {
    unsigned int num = 0;
    for(int i = 0; i < 32; i++) {
        if((A >> i) & 1) {
            num |= 1 << (31 - i); // need a one here 
        } 
    }
    return num;
}

/*

    0000 0000 0000 0000 0000 0000 0000 0011 -> 3 (rep in binary)
    1100 0000 0000 0000 0000 0000 0000 0000 -> 3221225472 (rep in binary)
    
*/
