class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> arr;
        
        long long b = 1;
        while(n){
            int base = n % 10;
            if(base > 0){
                arr.push_back(base * b);
            }
            
            n /= 10;
            b *= 10;
        }
        reverse(arr.begin(), arr.end());
        return arr;
    }
};