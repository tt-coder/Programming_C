import java.util.Scanner;

public class Kadai36 {
	int M, N;
	int[][] memo;
	
	Kadai36(){
		Scanner scan = new Scanner(System.in);
		M = scan.nextInt();
		N = scan.nextInt();
		memo = new int[M+1][];
		for(int i=0; i<=M; i++){
			memo[i] = new int[N+1];
			for(int j=0; j<=N; j++){
				memo[i][j] = -1;
			}
		}
		scan.close();
	}
	
	// mŒÂ‚Ì–â‘è‚ðnl‚Å‰ð‚­
	public int calc(int m, int n){
		if(n==1){
			memo[m][n] = 1;
			return memo[m][n];
		}
		if(memo[m][n]!=-1) return memo[m][n];
		
		memo[m][n] = 0;
		for(int i=0; i<=m; i++)
			memo[m][n] += calc(i, n-1);
		return memo[m][n];
	}
	
	public void print(){
		
	}
	
	public static void main(String[] args) {
		Kadai36 a = new Kadai36();
		System.out.println(a.calc(a.M, a.N));
	}
}
