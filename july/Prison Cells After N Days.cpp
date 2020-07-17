class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    unordered_map<string, int>mp;
        for(int i = 0; i<N; ++i){
            string s(cells.begin(),cells.end());
            if(mp.find(s)!= mp.end()){
                int l_len = i - mp[s];
                int res = (N-1)% l_len;
                return prisonAfterNDays(cells,res);
            }
            
            mp.insert({s,i});
                int prev = cells[0];
            for (int j=1; j<7; ++j) {
                int next = cells[j+1];
                int curr = cells[j];
                cells[j] = prev == next;
                prev = curr;
        }
        cells[0]=0;
        cells[7]=0;
        
    }
    return cells;
    }
};
