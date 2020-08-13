package codechef.aug20b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Crdgame3 {

    public static void main(String[] args) {
        FastReader in = new FastReader();
        int t = in.nextInt();
        while (t-- != 0) {
            int pc = in.nextInt();
            int pr = in.nextInt();
            int ac = pc/9;
            if (pc%9 != 0) ac++;
            int ar = pr/9;
            if (pr%9 != 0) ar++;
            int res1 = (ac < ar) ? 0:1;
            int res2 = (ac < ar) ? ac:ar;
            System.out.println(res1 + " " + res2);
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
