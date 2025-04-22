//non-intuitive efficient solution

// recurrence:
// f(n,k)=(f(n-1,k)+k)%n
// watch neetcode's video. https://www.youtube.com/watch?v=PBBQgW_75e0&pp=ygUZam9zZXBodXMgcHJvYmxlbSBsZWV0Y29kZdIHCQl-CQGHKiGM7w%3D%3D

//recursive
class Solution {
public:
    int f(int n,int k){
        if(n==1) return 0;
        return (f(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        return f(n,k)+1;
    }
};

//iterative
class Solution {
public:

    int findTheWinner(int n, int k) {
        int ans=0;
        for(int N=2;N<=n;N++){
            ans=(ans+k)%N;
        }
        return ans+1;
    }
};

