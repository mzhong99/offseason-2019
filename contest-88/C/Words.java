import java.util.*

public class Words {

    class Pair {
        int r, c;
        
        Pair() {
            r = 0;
            c = 0;
        }

        Pair(int _x, int _y) {
            r = _r;
            c = _c;
        }

        Pair up() {
            return new Pair(r - 1, c);
        }

        Pair down() {
            return new Pair(r + 1, c);
        }

        Pair left() {
            return new Pair(r, c - 1);
        }

        Pair right() {
            return new Pair(r, c + 1);
        }
    }
    
    static int R, C, W;
    static int MAX_WORD_LENGTH = 0;

    static char[][] board;
    static Set<String> set = new HashSet<String>();
    static Set<Set<Integer>> used = new HashSet<Set<Integer>>();
    
    public static void main(String[] args) {
        
        Scanner in = new Scanner(System.in);
        
        R = in.nextInt();
        C = in.nextInt();
        
        board = new char[R][C];

        for (int r = 0; r < R; r++) {
            String line = in.next();
            board[r] = line.toCharArray();
        }

        W = in.nextInt();

        for (int w = 0; w < W; w++) {
            
            String word = in.next();
            set.add(word);
            
            if (MAX_WORD_LENGTH < word.length()) {
                MAX_WORD_LENGTH = word.length();
            }
        }

        validate();
    }

    public void validate() {
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                
                List<Character> search = new ArrayList<Character>();
                Stack<Pair> dfs = new Stack<Pair>();

                search.add(board[r][c]);
                dfs.push(new Pair(r, c));

                while (!dfs.empty()) {
                    
