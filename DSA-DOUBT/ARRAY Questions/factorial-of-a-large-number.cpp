class Solution {
  public:
    vector<int> factorial(int n) {
        /* prblem with factorials is that they are too big. To solve this we need to store them into a vector. 
        So a vector fact will store the factorial of the last number in reverse order. 
        Reverse order helps as the least significant bit is at the start so multiplying a new 
        digit if we want factorial of n+1 suppose,  becomes easy 
        eg) if vector has 021 (120) and we need factorial of 6 which is 720 we will traverse the vector
        and do 6*0 = 0 (store it) then 6*2 = 12 so we store 2 and carry one and then 6*1 + carry = 7
        so vector becomes 027. 
        */
        if (n<=1)
            return {n}; 
        vector<int> fact; 
        fact.push_back(1); //factorial of 0 needs to be in. 
        for (int i = 1 ; i<=n ; i++){
            //calculating factorial of ith number 
            int carry = 0; 
            int size = fact.size(); //we need to save it as in the loop we keep adding digits so size changes. 
            for (int j = 0 ; j<size ; j++){
                int ans = fact[j]*i + carry; //ans doesnt represent the entire factorial, only the digit which is supposed to go at the current place. 
                fact[j]= (ans%10); //the digit which goes into the array. It replaces the old digit
                carry = ans/10; 
            }
            while (carry){
                fact.push_back(carry%10);
                carry /= 10; 
            }
        }
        reverse (fact.begin(), fact.end()); 
        return fact; 
        
            
    }
};