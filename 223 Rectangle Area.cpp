class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C-A) *(D-B) + (G-E) * (H-F) - interSec(A,C,E,G) * interSec(B,D,F,H);
    }
    
    int interSec(int A, int C, int E, int G) {
        if (C<=E||A>=G) return 0;
        if (A>=E&&C<=G) return C-A;
        if (A<E&&C>G) return G-E;
        return C-A+G-E-((C<G?G:C)-(A<E?A:E));
    }
};
