import java.util.Scanner;

public class Kadai38 {
	int W, H;
	int[][] memo;
	char[][] area;
	
	Kadai38(){
		Scanner scan = new Scanner(System.in);
		W = scan.nextInt();
		H = scan.nextInt();
		
		area = new char[H][];
		memo = new int[H][];
		
		for(int i=0; i<H; i++){
			area[i] = new char[W];
			memo[i] = new int[W];
			
			String line = scan.next();
			
			for(int j=0; j<W; j++){
				area[i][j] = line.charAt(j);
				memo[i][j] = -1;
			}
		}
		
		scan.close();
	}
	
	public int calc(){
		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				if(i==0 && j==0)
					memo[i][j] = 1;
				else if(area[i][j]=='X')
					memo[i][j] = 0;
				else{
					if(i==0)
						memo[i][j] = memo[i][j-1];
					else if(j==0)
						memo[i][j] = memo[i-1][j];
					else
						memo[i][j] = memo[i-1][j] + memo[i][j-1];
					
				}
				//System.out.print(area[i][j] + " ");
			}
			//System.out.println();
		}
		return memo[H-1][W-1];
	}
	
	public static void main(String[] args) {
		Kadai38 a = new Kadai38();
		System.out.println(a.calc());
	}
}
