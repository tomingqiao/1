package myproject;
import java.util.*;
public class A1001 {
	public static void main(String args[]) {
		double a=0;
		a=Math.random()*100;
		a=(int)a;
		Scanner s=new Scanner(System.in);
		while(0==0){
			System.out.println("���������Ĳ²⣺");
			int m=s.nextInt();
			if(m<a)
				System.out.println("��С��");
			else if(m>a)
				System.out.println("�´���");
			else if(m==a)
			{
				System.out.println("�¶���");
				break;
			}
				
		}
		s.close();
	}
}
