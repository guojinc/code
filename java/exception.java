import javax.lang.model.type.NullType;

/*************************************************************************
	> File Name: exception.java
	> Author: dascard
	> Mail: dascard601@gmail.com 
	> Created Time: Mon Sep 30 18:55:17 2024
 ************************************************************************/
class exception
{
	public static void main(String[] args)	
	{
		try{
			NullType a = null;
		} catch (NullPointerException nlp){
			System.out.println("NullPointerException");
		}
	}
}
