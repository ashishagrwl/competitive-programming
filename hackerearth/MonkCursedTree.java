package com.hackerearth.codemonk.binarysearchtree;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class MonkCursedTree {

    private static int low, high;
    private static boolean lowAdded = false, highAdded = false;

    private static List<Integer> lowTrail = new ArrayList<>();
    private static List<Integer> highTrail = new ArrayList<>();

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);

        int t = in.nextInt();

        Tree tree = new MonkCursedTree().new Tree();
        List<Integer> array = new ArrayList<>();

        for (int i = 0; i < t; i++) {
            array.add(in.nextInt());
        }

        Queue<Integer> queue = new LinkedList<>();



        low = in.nextInt();
        high = in.nextInt();

        if (low > high) {
            int temp = low;
            low = high;
            high = temp;
        }

        if (low == high) {
            System.out.println(low);
            return;
        }

        int max = 0;

        boolean trailStarted = false;

        int result = high, leftBound = low, rightBound = Integer.MAX_VALUE;
        boolean firstHigherFound = false;

        for (int i : array) {
//            tree.insert(i);
//
//            if (highAdded && lowAdded) {
//
//                int len = highTrail.size();
//                for (int ii = 0; ii < len; ii++) {
////                    // This works too. But lowTrail is not needed.
////                    if (ii < lowTrail.size() && (lowTrail.get(ii).equals(highTrail.get(ii)))) {
////                        continue;
////                    }
//                    if (trailStarted == false && (highTrail.get(ii) > high || highTrail.get(ii) < low)) continue;
//                    trailStarted = true;
//                    if (highTrail.get(ii) > max) max = highTrail.get(ii);
//                }
//                System.out.println(max);
//                return;
//            }

            // Trying without using tree
            if (i >= low && i <= high) trailStarted = true;

            if (!trailStarted) {
                if (i > high && i < rightBound) rightBound = i;
            }

            if (trailStarted) {

                if (i == low) {
                    lowAdded = true;
                    if (highAdded && low > leftBound) {
                        System.out.println(high);
                        return;
                    }
                }

                if (i == high) {
                    highAdded = true;
                }

                if (highAdded && lowAdded) {
                    System.out.println(result);
                    return;
                }

                if (i < high && !highAdded && i > leftBound) leftBound = i;

                if (i > high && i < rightBound && !highAdded && !firstHigherFound) {
                    result = i;
                    firstHigherFound = true;
                }
            }
        }

        // tree.printInorder();
    }

    private class Tree {

        Node root;

        private class Node {

            Node(int value) {
                this.value = value;
            }

            int value;
            Node left;
            Node right;
        }

        public void insert(int value) {
            root = insertNode(value, root);
        }

        Node insertNode(int value, Node node) {
            if (null == node) {
                if (value == high) {
                    highTrail.add(value);
                    highAdded = true;
                }
                if (value == low) {
                    lowTrail.add(value);
                    lowAdded = true;
                }
                return new Node(value);
            }

            if (value == low) {
                if (node.value == high) {
                    System.out.println(high);
                    System.exit(0);
                }
                lowTrail.add(node.value);
            }

            if (value == high) highTrail.add(node.value);

            if (value > node.value) node.right = insertNode(value, node.right);
            else if (value < node.value) node.left = insertNode(value, node.left);

            return node;
        }

        void printInorder() {
            printInorder(root);
            System.out.println('\n');
        }

        void printInorder(Node node) {
            if (null == node) return;
            printInorder(node.left);
            System.out.println(node.value + " ");
            printInorder(node.right);
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

    }
}
