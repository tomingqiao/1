package myproject;

public class A1002 {

	public static void main(String[] args) {
		int i=0;
		char [][] s= {{'*'},{'*','*','*'},{'*','*','*','#','*'},{'*','*','*','*','*','*','*'} };
		for(int a=0;a<s.length;a++) {
			for(int b=0;b<s[a].length;b++)
			{
				if(s[a][b]=='#')
					System.out.println("在二维数组的下标："+a+','+b);
			}
		}
	}
}
