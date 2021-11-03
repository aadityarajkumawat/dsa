package programs;

import java.util.Scanner;

public class arrinsnewarray {
    @SuppressWarnings({ "resource" })
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        int[] a = new int[10];
        System.out.println("Enter size of array");
        int size = ip.nextInt();
        System.out.println("Enter values in your array");
        for (int i = 0; i < size; i++) {
            a[i] = ip.nextInt();
        }
        System.out.println("Array values are");
        for (int i = 0; i < size; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
        System.out.println("Enter the value you want to insert");
        int val = ip.nextInt();
        System.out.println("Enter the position index wise");
        int pos = ip.nextInt();

        int[] newarr = new int[10];
        int j = 0;
        for (int i = 0; i < size + 1; i++) {
            if (i == pos) {
                newarr[i] = val;
            } else {
                newarr[i] = a[j];
                j++;
            }
        }

        System.out.println("Insertion Successful");
        System.out.println("After insertion array values are");
        for (int i = 0; i < size + 1; i++) {
            System.out.print(newarr[i] + " ");
        }
    }
}
