import java.util.Scanner;

public class Kadai41 {
	int n;
	int[][] matrix;
	
	Kadai41(){
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		matrix = new int[n+1][];
		for(int i=1; i<=n; i++){
			matrix[i] = new int[n+1];
			for(int j=1; j<=n; j++)
				matrix[i][j] = scan.nextInt();
		}
		scan.close();
	}
	
	public void print(){
		for(int i=1; i<=n; i++){
			System.out.print(i);
			int sum = 0;
			for(int j=1; j<=n; j++)
				if(matrix[i][j]==1) sum++;
			System.out.print(" " + sum);
			for(int j=1; j<=n; j++){
				if(matrix[i][j]==1)
					System.out.print(" " + j);
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		Kadai41 a = new Kadai41();
		a.print();
	}
}
