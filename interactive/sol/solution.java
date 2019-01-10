class interactive {
    public static int[] guess(int n) {
        int[] ans = new int[n];
        for (int i = 1; i <= n; i++) {
            ans[i - 1] = grader.ask(i);
        }
        return ans;
    }
}
