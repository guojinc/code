/*************************************************************************
	> File Name: dog_main.java
	> Author: dascard
	> Mail: dascard601@gmail.com 
	> Created Time: Tue Sep  3 17:26:41 2024
 ************************************************************************/
public class dog_main{
	public static void main(String[] args)
	{
		
		
		dog a = new dog(100);
		dog b = new dog(50);
		dog lagerDog = dog.maxDog(a, b);
		lagerDog.makenoise();
	}
}
