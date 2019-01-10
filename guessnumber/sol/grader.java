import java.util.Scanner;

public class grader {
    private final static int maxn = 1000;
    private final static int maxq = 1000;
    private static int numq = 0;
    private static int n;
    private static int hidden_number;

    private static void wrong_answer(String MSG) {
        System.out.println("-1");
        System.exit(0);
    }

    public static char ask(int x) {
        ++numq;
        if (numq > maxq) wrong_answer("-1");
        if (x < 1 || x > n) wrong_answer("-1");
        if (x < hidden_number) return '<';
        else if (x > hidden_number) return '>';
        else return '=';
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        hidden_number = scanner.nextInt();

        int g = guessnumber.guess_number(n);

        System.out.println(g);
        System.out.println(numq);

    }
}
