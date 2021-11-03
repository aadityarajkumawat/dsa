package programs;

import java.util.Scanner;

public class arrdel {
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
        for (int i = pos; i < size - 1; i++) {
            a[i] = a[i + 1];
        }
        size = size - 1;
        System.out.println("Deletion successful");
        System.out.println("Array after deletion");
        printArray(a, size);
    }
}
