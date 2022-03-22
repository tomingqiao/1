package myproject;
import java.util.*;
public class A1001 {
	public static void main(String args[]) {
		double a=0;
		a=Math.random()*100;
		a=(int)a;
		Scanner s=new Scanner(System.in);
		while(0==0){
			System.out.println("请输入您的猜测：");
			int m=s.nextInt();
			if(m<a)
				System.out.println("猜小了");
			else if(m>a)
				System.out.println("猜大了");
			else if(m==a)
			{
				System.out.println("猜对了");
				break;
			}
				
		}
		s.close();
	}
}
