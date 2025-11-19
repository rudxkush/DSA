string Solution::findDigitsInBinary(int A) {
    if(A == 0) return "0";
    string binary = "";
    while(A >= 0) {
        if(A == 1) {
           binary.push_back('1'); 
           break;
        }
        int temp = A%2;
        binary.push_back(temp + '0');
        A = A/2;
    }   
    reverse(binary.begin(), binary.end());
    return binary;
}
