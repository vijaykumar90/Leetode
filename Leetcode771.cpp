class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> stonelen;
        for(int i=0; i<stones.size();i++){
            if(stonelen.find(stones[i]) != stonelen.end()){
                int count = stonelen[stones[i]];
                stonelen[stones[i]] = count+1;
            }else{
                stonelen[stones[i]] = 1;
            }
        }
        int res = 0;
        for(int i=0; i<jewels.size();i++){
            if(stonelen.find(jewels[i]) != stonelen.end()){
                int existingcount = stonelen[jewels[i]];
                res = res + existingcount;
            }
        }

        return res;
    }
};
