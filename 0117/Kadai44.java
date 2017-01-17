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
		// ‚à‚µ8s–Ú‚Ìê‡‚Í`
		if(i==8) return true;
		
		// “–ŠYs‚É‚à‚µ‚·‚Å‚É‹î‚ª`A‚³‚ç‚É‚à‚µ2ŒÂˆÈã‚Ì‹î‚ª`
		int qj = -1;
		for(int j=0; j<8; j++){
			if(board[i][j]=='Q') {
				if(qj!=-1) return false;
				else qj = j;
			}
		}
		
		// “–ŠYs‚É‚à‚µ‹î‚ª‚¨‚©‚ê‚Ä‚¢‚½ê‡‚ÍA`
		if(qj != -1){
			if(isPuttable(i, qj)){
				if(dfs(i+1)) return true;
			}
		
		// “–ŠYs‚É‹î‚ª‚¨‚©‚ê‚Ä‚¢‚È‚¢ê‡‚Í`
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
