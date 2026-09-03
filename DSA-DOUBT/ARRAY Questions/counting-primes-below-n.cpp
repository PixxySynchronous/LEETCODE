class Solution {
public:
    int countPrimes(int n) {
        if ( n <= 2) //base case. 
            return 0; 
        vector<bool> isPrime (n,true); //Maintains which number is prime which isnt. 
        isPrime[0] = false; 
        isPrime[1] = false; 
        int count = 0; 
        //Below for loop starts from 2 as 0 and 1 already processed. 
        //The thought process is this, instead of checking each number is prime or not, 
        //whenever we encounter a prime number, we mark all of its multiples as non prime. 
        //However, this will still lead to TLE. To furhter make this more effecient, we need to realise that For any composite n(non prime number), one of its factors will always be <= sqrt n. What this means is that if we are on 5, we only need to mark multiples of 5 g>= 25, as previous multiples of 5 have already been marked by lesser primes. 
        for (int i = 2; i*i < n; i++){
            //The for loop runs only till i sqr < n. This is because once i square becomes greater than n, we already have marked all the possible multiples of the primes as non primes. Eg if n= 30 and we are on i = 6, i sqr = 36, We don't need 6 because any composite number below 30 that has 6 as a factor already has a smaller factor that would have marked it.
            if (isPrime[i] == true){
                for (int j = i*i; j<n; j+=i)
                    isPrime[j] = false;
            }
        }
        //Since the above for loop only travels from i to i sqr<n, we need a separate loop to count the total number of primes. 
        for (int i = 2; i < n; i++) {
            if (isPrime[i])
            count++;
        }
        return count; 
    }
};