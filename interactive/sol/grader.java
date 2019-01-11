import java.util.Arrays;
import java.util.Scanner;

public class grader {
    private final static int maxn = 100;
    private final static int maxq = 200;
    private static int numq = 0;
    private static int n;
    private static int[] a;

    private static void wrong_answer(String MSG) {
        System.out.println("-1");
        System.exit(0);
    }

    private static void query() {
        numq++;
        if (numq > maxq) {
            wrong_answer("Number of queries exceeded");
        }
    }
    public static int ask(int position) {
        query();

        if (position < 1 || position > n) {
            wrong_answer("Not correct position");
        }
        return a[position - 1];
    }


    public static int[] get_pairwise_xor(int[] positions) {
        query();
        if (positions.length == 0 || positions.length > n) {
            wrong_answer("Not correct size");
        }

        for (int i = 0; i < positions.length; i++) {
            if (positions[i] < 1 || positions[i] > n) {
                wrong_answer("Not correct position");
            }
        }
        Arrays.sort(positions);

        for (int i = 1; i < positions.length; i++) {
            if (positions[i] == positions[i - 1]) {
                wrong_answer("Not unique");
            }
        }
        int k = positions.length
        int[] pairwise_xor = new int[k*k];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                int posI = positions[i];
                int posJ = positions[j];

                pairwise_xor[i * positions.length + j] = (a[posI - 1] ^ a[posJ - 1]);
            }
        }

        Arrays.sort(pairwise_xor);

        return pairwise_xor;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            a[i] = x;
        }
        int[] answer = interactive.guess(n);
		if (answer.length != n) {
			wrong_answer("Answer not equal to n");
			exit(0);
		}
        System.out.println(n);
        for (int i = 0; i < answer.length; i++) {
            System.out.print(answer[i] + " ");
        }
        System.out.println();
        System.out.println(numq);
    }
}
