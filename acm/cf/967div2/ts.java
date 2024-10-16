import java.util.Scanner;

public class ts {
    // public static void main(String[] args) {
    //     System.out.println("Hello, World!");
    // }
    

    public static void main(String[] args) {
        ts cout = new ts();
        cout.print("Hello, World!").println().print("Hello, World!").println();
        
    }

    public ts print(Object obj) {
        System.out.print(obj);
        return this;
    }

    

    public ts println(Object obj) {
        System.out.println(obj);
        return this;
    }

    public ts println()
    {
        System.out.println();
        return this;
    }
}