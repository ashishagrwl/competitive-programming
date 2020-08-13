package codechef.aug20b;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Chefwars {
    public static void main(String[] args) {
        FastReader in = new FastReader();
        int t = in.nextInt();
        while (t-- != 0) {
            double h = in.nextInt();
            double p = in.nextInt();
            while (p!=0) {
                h-=p;
                if (h<=0) {
                    h = 0;
                    break;
                }
                p=Math.floor(p/2);
            }
            if (h==0) {
                System.out.println(1);
            } else {
                System.out.println(0);
            }
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
