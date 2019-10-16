package chap5;

import java.util.Arrays;

public class Q15 {
    public static void main(String[] args) {
        int[][] A={
                {1,3,5},
                {-3,6,0},
                {13,-5,7},
                {-2,19,25}
            };
        int[][] B={
                {0,-1,-2},
                {7,-1,6},
                {-6,13,2},
                {12,-8,-13}
            };
        int[][] ans=new int[4][3];
        for(int row=0;row<4;row++){
            for(int col=0;col<3;col++){
                ans[row][col]=A[row][col]+B[row][col];
            }
        }
        System.out.println("A+B: "+ Arrays.deepToString(ans));

        for(int row=0;row<4;row++){
            for(int col=0;col<3;col++){
                ans[row][col]=A[row][col]-B[row][col];
            }
        }
        System.out.println("A-B: "+ Arrays.deepToString(ans));

        int[][] transpositionA=new int[3][4];
        for(int row=0;row<3;row++){
            for(int col=0;col<4;col++){
                transpositionA[row][col]=A[col][row];
            }
        }
        System.out.println("Transposition A: "+ Arrays.deepToString(transpositionA));
    }
}
