import java.util.Scanner;

public class minelem {
    /**
     * input: size: N, array: a
     * Time Complexity: O(N) | Space Complexity: O(N)
     * ********* Algorithm for finding min element *********
     * START
     * min = MAX_INT
     * for(0 to N-1)
     * if(a[i] < min)
     * min = a[i]
     * END OF IF
     * END OF FOR
     * print(min)
     * ****************************************************
     */
    @SuppressWarnings({"resource"})
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
        int minElement = Integer.MAX_VALUE;
        for (int i = 0; i < size; i++) {
            if (a[i] < minElement) {
                minElement = a[i];
            }
        }
        System.out.println("\nMin element in array is:\n" + minElement);
    }
}
