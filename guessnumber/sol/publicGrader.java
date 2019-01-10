import java.util.Scanner;

public class publicGrader {
    private final static int maxn = 1000;
    private final static int maxq = 1000;
    private static int numq = 0;
    private static int n;
    private static int hidden_number;

    private static void wrong_answer(String MSG) {
        System.out.println(String.format("Wrong answer: %s", MSG));
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

        if (n > maxn) {
            System.out.println("Wrong constraints");
            System.exit(0);
        }

        int g = guessnumber.guess(n);

        if (g == hidden_number) {
            System.out.println(String.format("Correct: answer found in %d queries", numq));
            System.exit(0);
        } else {
            wrong_answer("answer not found");
        }
    }
}