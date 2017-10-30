package com.hackerearth.codemonk.binarysearchtree;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class MonkWatchingFight {

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);

        int t = in.nextInt();
        BinarySearchTree tree = new BinarySearchTree();

        List<Integer> array = new ArrayList<>();

        while (0 != t--) {
            array.add(in.nextInt());
        }

        int max_depth = 0;

        for (Integer item : array) {
            int current_depth = tree.insertNode(item);
            if (current_depth > max_depth) max_depth = current_depth;
        }

        System.out.println(max_depth);

    }

    static class BinarySearchTree {

        private Node head;

        private class Node {

            private int value;
            public Node left;
            public Node right;

            Node(int value) {
                this.value = value;
            }

            public int getValue() {
                return value;
            }
        }

        public int insertNode(int item) {
            if (null == head) {
                head = new Node(item);
                return 1;
            }
            return insert(item, head);
        }

        private int insert(int item, Node node) {

            if (item <= node.getValue()) {
                if (null == node.left) {
                    node.left = new Node(item);
                    return 2;
                }
                return 1 + insert(item, node.left);
            }
            if (item > node.getValue()) {
                if (null == node.right) {
                    node.right = new Node(item);
                    return 2;
                }
                return 1 + insert(item, node.right);
            }

            return 0;
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
