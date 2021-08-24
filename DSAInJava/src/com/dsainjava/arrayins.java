package com.dsainjava;

import java.util.*;

public class arrayins {
    @SuppressWarnings({"resource"})
    public static void main(String[] args) {
        int val, i, pos, n;
        int[] a = new int[10];
        Scanner ip = new Scanner(System.in);
        System.out.println("Enter size of array");
        n = ip.nextInt();
        System.out.println("Enter values in your array");
        for (i = 0; i < n; i++) {
            a[i] = ip.nextInt();
        }
        System.out.println("Array values are");
        for (i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println("Enter the value you want to insert");
        val = ip.nextInt();
        System.out.println("Enter the position index wise");
        pos = ip.nextInt();

        i = n - 1;
        while(i >= pos) {
            a[i + 1] = a[i];
            i--;
        }
        n = n + 1;
        a[pos] = val;
        System.out.println("Insertion Successful");
        System.out.println("After insertion array values are");
        for (i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
