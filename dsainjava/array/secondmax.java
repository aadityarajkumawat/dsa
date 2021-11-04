package array;

import java.util.Scanner;

public class secondmax {
    /**
     * input: size: N, array: a Time Complexity: O(N) | Space Complexity: O(N)
     * ********* Algorithm for finding second max element ********* START max = 0
     * second_max = 0 for(0 to N-1) if(a[i] > max) second_max = max max = a[i] END
     * OF IF else if (a[i] > second_max and a[i] < max) second_max = a[i] END OF
     * ELSE IF END OF FOR
     *
     * print(second_max) ****************************************************
     */
    @SuppressWarnings({ "resource" })
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        System.out.println("Enter size of array:");
        int size = ip.nextInt();
        System.out.println("Enter array elements:");
        int[] a = new int[size];
        for (int i = 0; i < size; i++) {
            int x = ip.nextInt();
            a[i] = x;
        }
        System.out.println("Entered Array:");
        for (int i = 0; i < size; i++) {
            System.out.print(a[i] + " ");
        }
        int max = 0;
        int second_max = 0;
        for (int i = 0; i < size; i++) {
            if (a[i] > max) {
                second_max = max;
                max = a[i];
            } else if (a[i] > second_max && a[i] < max) {
                second_max = a[i];
            }
        }
        System.out.println("\nSecond max element in array is:\n" + second_max);
    }
}
