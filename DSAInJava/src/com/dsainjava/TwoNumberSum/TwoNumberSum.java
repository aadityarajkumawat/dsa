package com.dsainjava.TwoNumberSum;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class TwoNumberSum {
    public static ArrayList<Integer> twoNumberSum(ArrayList<Integer> nums, int target) {
        ArrayList<Integer> twoNums = new ArrayList<>();
        HashMap<Integer, Boolean> hashMap = new HashMap<>();
        for (int current : nums) {
            int otherHalf = target - current;
            if (hashMap.containsKey(otherHalf)) {
                twoNums.add(current);
                twoNums.add(otherHalf);
                return twoNums;
            }
            hashMap.put(current, true);
        }

        return twoNums;
    }

    public static void main(String[] args) {
        ArrayList<Integer> nums = new ArrayList<>(List.of(1, 4, 7, -1, 0, -2, 2));
        int target = 11;
        ArrayList<Integer> twoNums = twoNumberSum(nums, target);
        System.out.println(twoNums);
    }
}
