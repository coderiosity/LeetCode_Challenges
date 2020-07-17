class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> temp;
         temp.insert(1);
             long k = 0;
        while(n){
            
            set<long> :: iterator itr=temp.begin();
            k = *itr;
            temp.erase(k);
            temp.insert(k*2);
            temp.insert(k*3);
            temp.insert(k*5);
            n--;
        }
        return k;
    }
};
