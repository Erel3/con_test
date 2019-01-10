class guessnumber {
    public static int guess_number(int n) {
        int l = 1, r = n;
        while(true) {
            int m = (l + r) >> 1;
            char c = grader.ask(m);
            if(c == '=') break;
            if(c == '<') l = m + 1;
            if(c == '>') r = m - 1;
        }
        return (l + r) >> 1;
    }
}
