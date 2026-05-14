/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;
// test/MyArrayTest.java
import org.junit.Test;
import static org.junit.Assert.*;

public class MyArrayTest {

    MyArray obj = new MyArray();

    // PASS CASES
    @Test
    public void testNormalArray() {
        int[] arr = {1, 5, 3, 9, 2};
        assertEquals(9, obj.findLargest(arr));
    }

    @Test
    public void testAllNegative() {
        int[] arr = {-5, -2, -9, -1};
        assertEquals(-1, obj.findLargest(arr));
    }

    @Test
    public void testSingleElement() {
        int[] arr = {7};
        assertEquals(7, obj.findLargest(arr));
    }

    @Test
    public void testSortedArray() {
        int[] arr = {1, 2, 3, 4, 5};
        assertEquals(5, obj.findLargest(arr));
    }

    // FAIL CASE (intentional)
    @Test
    public void testFailCase() {
        int[] arr = {2, 4, 6};
        assertEquals(5, obj.findLargest(arr)); // actual = 6 → FAIL
    }

    // EXCEPTION CASE
    @Test(expected = IllegalArgumentException.class)
    public void testEmptyArray() {
        obj.findLargest(new int[]{});
    }
}