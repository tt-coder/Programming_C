import java.util.Scanner;

public class Kadai44 {
	char[][] board;
	
	Kadai44(){
		Scanner scan = new Scanner(System.in);
		board = new char[8][8];
		
		for(int i=0; i<8; i++){
			String line = scan.next();
			for(int j=0; j<8; j++){
				board[i][j] = line.charAt(j);
			}
		}
		scan.close();
	}
	
	public boolean isPuttable(int i, int j){
		for(int vy=-1; vy<=1; vy++){
			for(int vx=-1; vx<=1; vx++){
				if(vy==0 && vx==0) continue;
				int y = i, x = j;
				while(true){
					y += vy;
					x += vx;
					if(y<0 || y>=8 || x<0 || x>=8) break;
					if(board[y][x]=='Q') return false;
				}
			}
		}
		return true;
	}
	
	public boolean dfs(int i){
		// ����8�s�ڂ̏ꍇ�́`
		if(i==8) return true;
		
		// ���Y�s�ɂ������łɋ�`�A����ɂ���2�ȏ�̋�`
		int qj = -1;
		for(int j=0; j<8; j++){
			if(board[i][j]=='Q') {
				if(qj!=-1) return false;
				else qj = j;
			}
		}
		
		// ���Y�s�ɂ����������Ă����ꍇ�́A�`
		if(qj != -1){
			if(isPuttable(i, qj)){
				if(dfs(i+1)) return true;
			}
		
		// ���Y�s�ɋ������Ă��Ȃ��ꍇ�́`
		}else{
			for(int j=0; j<8; j++){
				if(isPuttable(i, j)){
					board[i][j] = 'Q';
					if(dfs(i+1)) return true;
					else board[i][j] = '.';
				}
			}
		}
		return false;
	}
	
	public void print(){
		for(int i=0; i<8; i++){
			for(int j=0; j<8; j++){
				System.out.print(board[i][j]);
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		Kadai44 a = new Kadai44();
		if(a.dfs(0)) System.out.println("Yes");
		else System.out.println("No");
	}
}
