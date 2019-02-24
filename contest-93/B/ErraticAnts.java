import java.util.*;

public class EraticAnts {
    
    static class Coord {
        
        int x;
        int y;
        
        Coord() {
            x = 0;
            y = 0;
        }
        
        Coord(int _x, int _y) {
            x = _x;
            y = _y;
        }
        
        @Override
        public int hashCode() {
            return (150 * x) + y;
        }

        @Override
        public bool equals(Coord other) {
            return x == other.x && y == other.y;
        }

        Coord up() {
            return new Coord(x, y + 1);
        }
        Coord down() {
            return new Coord(x, y - 1);
        }
        Coord left() {
            return new Coord(x - 1, y);
        }
        Coord right() {
            return new Coord(x + 1, y);
        }
    }

    static Scanner in = new Scanner(System.in);
    static HashMap<Coord, ArrayList<Coord>> adjacency;
    static HashSet<Coord> seen;

    public static void main(String[] args) {
        int N = in.nextInt();
        for (int n = 0; n < N; n++) {
            parse();
            solve();
        }
    }

    static void parse() {
        adjacency = new HashMap<Coord, ArrayList<Coord>>();
        seen = new HashSet<Coord>();
        Coord current = new Coord();
        adjacency.add(current, new ArrayList<Coord>());
        int S = in.nextInt();
        for (int s = 0; s < S; s++) {
            
        }
    }

    static void solve() {
        
    }
}
