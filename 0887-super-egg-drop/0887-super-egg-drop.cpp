class Solution {
public:
    int findTotalMoves(int eggs, int moves) {
        if(eggs == 0 || moves == 0)
        return 0;

        if(eggs == 1)
        return moves;

        return 1+findTotalMoves(eggs-1, moves-1)+findTotalMoves(eggs, moves-1);
    }
    int superEggDrop(int k, int n) {
        int moves = 0;
        while(findTotalMoves(k, moves)<n){
            moves++;
        }
        return moves;
    }
};