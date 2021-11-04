package array;

import java.util.Scanner;

public class maxelem {
    /**
     * input: size: N, array: a Time Complexity: O(N) | Space Complexity: O(N)
     * ********* Algorithm for finding max element ********* START max = 0 for(0 to
     * N-1) if(a[i] > max) max = a[i] END OF IF END OF FOR print(max)
     * ****************************************************
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
        int maxElement = 0;
        for (int i = 0; i < size; i++) {
            if (a[i] > maxElement) {
                maxElement = a[i];
            }
        }
        System.out.println("\nMax element in array is:\n" + maxElement);
    }
}
