package codechef.aug20b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Linchess {

    public static void main(String[] args) {
        FastReader in = new FastReader();
        int t = in.nextInt();
        while (t-- != 0) {
            int res = -1;
            int n = in.nextInt();
            int k = in.nextInt();
            int vacant = 5;
            while (n-- != 0) {
                int x = in.nextInt();
                if (x>=k)
                    continue;
                if (k%x != 0)
                    continue;
                if (x > res)
                    res = x;
            }
            System.out.println(res);
        }
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }

}

