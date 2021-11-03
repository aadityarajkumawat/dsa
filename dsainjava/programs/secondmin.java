package programs;

import java.util.Scanner;

public class secondmin {
    /**
     * input: size: N, array: a Time Complexity: O(N) | Space Complexity: O(N)
     * ********* Algorithm for finding second min element ********* START min =
     * MAX_INT second_min = MAX_INT for(0 to N-1) if(a[i] < min) second_min = min
     * min = a[i] END OF IF else if (a[i] < second_min and a[i] > min) second_min =
     * a[i] END OF ELSE IF END OF FOR
     *
     * print(second_min) ****************************************************
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
        int min = Integer.MAX_VALUE;
        int second_min = Integer.MAX_VALUE;
        for (int i = 0; i < size; i++) {
            if (a[i] < min) {
                second_min = min;
                min = a[i];
            } else if (a[i] < second_min && a[i] > min) {
                second_min = a[i];
            }
        }
        System.out.println("\nSecond min element in array is:\n" + second_min);
    }
}
