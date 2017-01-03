package proC12;

import java.util.Scanner;

public class Kadai26 {
	int[] A;
	int n, INFTY = 1000000, cntall = 0;
	
	Kadai26(){
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		A = new int[n];
		for(int i=0; i<n; i++)
			A[i] = scan.nextInt();
		scan.close();
	}
	
	public int merge(int l, int m, int r){
		int n1 = m - l, n2 = r - m;
		int cnt = 0;
		// L[0...n1], R[0...n2] を生成
		int[] L = new int[n1+1];
		int[] R = new int[n2+1];
		for(int i=0; i<n1; i++)
			L[i] = A[l + i];
		for(int i=0; i<n2; i++)
			R[i] = A[m + i];
		// 番兵
		L[n1] = INFTY;
		R[n2] = INFTY;
		
		int i = 0, j = 0;
		//System.out.print("L ");
		//print(L, n1);
		for(int k=l; k<r; k++){
			if(L[i]<=R[j]){
				A[k] = L[i];
				i++;
			}else{
				A[k] = R[j];
				if(L[i]!=INFTY){
					cnt += (n1+j-(k-l));
				}
				j++;
			}
		}
		cntall += cnt;
		return cnt;
	}

	public void mergeSort(int l, int r){
		if(l+1 < r){
			int m = (l+r) / 2;
			//System.out.println("l:" + l + " m:" +m + " r:"+r);
			mergeSort(l, m);
			mergeSort(m, r);
			merge(l, m, r);
			System.out.println(cntall);
		}
	}
	
	public void print(int[] C, int N){
		for(int i=0; i<N; i++){
			if(i!=N-1)
				System.out.print(C[i] + " ");
			else
				System.out.println(C[i]);
		}
	}
	
	public static void main(String[] args) {
		Kadai26 a = new Kadai26();
		a.mergeSort(0, a.n);
	}
}
