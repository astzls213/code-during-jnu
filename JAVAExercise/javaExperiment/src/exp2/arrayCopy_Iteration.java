package exp2;

import java.util.Arrays;

public class arrayCopy_Iteration {
    public static void main(String[] args) {
        int[] array={1,2,3,4,5};

        int[] goal1=new int[5];
        for(int i=0;i<array.length;i++){
            goal1[i]=array[i];
        }

        int[] goal2=new int[5];
        System.arraycopy(array, 0, goal2, 0, 5);

        int[] goal3=Arrays.copyOf(array,5);

        for (int value : goal1) {
            System.out.print(value + " ");
        }
        System.out.println();
        for (int value : goal2) {
            System.out.print(value + " ");
        }
        System.out.println();
        for (int value : goal3) {
            System.out.print(value + " ");
        }
    }
}