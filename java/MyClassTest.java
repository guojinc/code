/*************************************************************************
	> File Name: MyClassTest.java
	> Author: dascard
	> Mail: dascard601@gmail.com 
	> Created Time: Wed Sep 11 16:36:01 2024
 ************************************************************************/
import org.junit.Test;
import static org.junit.Assert.*;

public class MyClassTest {
    @Test
    public void testAdd() {
        MyClass myClass = new MyClass();
        assertEquals(5, myClass.add(2, 3));
    }
}

