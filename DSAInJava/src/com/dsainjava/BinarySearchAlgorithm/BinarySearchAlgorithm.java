package com.dsainjava.BinarySearchAlgorithm;

import java.util.ArrayList;
import java.util.List;

public class BinarySearchAlgorithm {
    public static boolean searchFor(ArrayList<Integer> nums, int target) {
        for(int x: nums) {
            if(x == target) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        ArrayList<Integer> nums = new ArrayList<>(List.of(6, 9, 0, 1, 5, 2, 3));
        boolean $2IsPresent = searchFor(nums, 99);

        if($2IsPresent) {
            System.out.println("Present!");
        }
        else {
            System.out.println("Not present");
        }
    }
}
