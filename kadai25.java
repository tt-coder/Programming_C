import java.util.Scanner;

public class Kadai25 {
		int N;
		int[] A;
		
		Kadai25(){
			Scanner scan = new Scanner(System.in);
			N = scan.nextInt();
			A = new int[N];
			for(int i=0; i<N; i++){
				A[i] = scan.nextInt();
			}
			scan.close();
		}
		
		// Aの引き数の添え字の要素同士を交換する
		public void swap(int i, int j){
			int a = A[i];
			A[i] = A[j];
			A[j] = a;
		}
		
		public int partition(int l, int r){
			int x = A[l];
			int i = l;
			for(int j=l+1; j<=r; j++){
				if(A[j] < x){
					i++;
					swap(i, j);
				}
				//print();
			}
			swap(i, l);
			return i;
		}
		
		public void print(){
			for(int i=0; i<N; i++){
				if(i==N-1) System.out.println(A[i]);
				else System.out.print(A[i] + " ");
			}
		}
		
		public static void main(String[] args) {
			Kadai25 a = new Kadai25();
			int ans = a.partition(0, a.N-1);
			a.print();
			System.out.println(ans+1);  // ansは配列の配列の添え字(0から始まる)なので1から始まるのに合わせるために+1
		}
	}