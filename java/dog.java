/*************************************************************************
	> File Name: dog.java
	> Author: dascard
	> Mail: dascard601@gmail.com 
	> Created Time: Tue Sep  3 17:26:50 2024
 ************************************************************************/

public class dog{
	public int weight;
	public dog(int init_weight)
	{
		this.weight = init_weight;
	}
	public void makenoise()
	{
		if (weight > 50) {
			System.out.println("arooooo");	
		} else {
			System.out.println("Bark");
		}
	}
	public static void Makenoise()
	{
		System.out.println("Bark!");
	}

	public static dog maxDog(dog a, dog b)
	{
		return  a.weight > b.weight ? a : b;
	}
	
}
