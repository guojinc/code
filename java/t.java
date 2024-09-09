/*************************************************************************
	> File Name: t.java
	> Author: dascard
	> Mail: dascard601@gmail.com 
	> Created Time: Sun Sep  1 17:52:49 2024
 ************************************************************************/
public class t{
	public static void change(object a,int x,int y)
	{
		a.x = x;
		a.y = y;
	}
	public static void main(String args[])
	{
		object k = new object(3, 4);
			
		change(k, 0, 0);
		System.out.println(k.x + " " + k.y);

		// for (int i = 0; i < 10; i++)
		// {
			// System.out.println(i);
		// }
	}
}
