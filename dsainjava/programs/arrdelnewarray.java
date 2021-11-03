package programs;

import java.util.Scanner;

public class arrdelnewarray {
    @SuppressWarnings({ "resource" })
    public static void printArray(int[] arr, int size) {
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    @SuppressWarnings({ "resource" })
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        int[] a = new int[10];
        System.out.println("Enter size of array");
        int size = ip.nextInt();
        System.out.println("Enter numbers in array");
        for (int i = 0; i < size; i++) {
            a[i] = ip.nextInt();
        }
        System.out.println("Array entered is");
        printArray(a, size);
        System.out.println("Enter position to be removed");
        int pos = ip.nextInt();
        int[] newarr = new int[10];
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (i != pos) {
                newarr[j] = a[i];
                j++;
            }
        }
        System.out.println("Deletion successful");
        System.out.println("Array after deletion");
        printArray(newarr, size - 1);

    }
}
