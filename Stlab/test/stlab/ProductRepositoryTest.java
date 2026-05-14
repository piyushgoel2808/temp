/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit4TestClass.java to edit this template
 */
package stlab;

// test/ProductRepositoryTest.java
import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;

public class ProductRepositoryTest {

    private ProductRepository repo;

    @Before
    public void setup() {
        repo = new ProductRepository();
    }

    @Test
    public void testAddProduct() {
        repo.addProduct(new Product(1, "Laptop", 50000));
        assertEquals(1, repo.size());
    }

    @Test
    public void testGetProduct() {
        repo.addProduct(new Product(1, "Laptop", 50000));
        Product p = repo.getProduct(1);
        assertEquals("Laptop", p.getName());
    }

    @Test
    public void testUpdateProduct() {
        repo.addProduct(new Product(1, "Laptop", 50000));
        repo.updateProduct(1, "Gaming Laptop", 70000);

        Product p = repo.getProduct(1);
        assertEquals("Gaming Laptop", p.getName());
        assertEquals(70000, p.getPrice(), 0.001);
    }

    @Test
    public void testDeleteProduct() {
        repo.addProduct(new Product(1, "Laptop", 50000));
        repo.deleteProduct(1);
        assertNull(repo.getProduct(1));
    }

    @Test
    public void testProductNotFound() {
        assertNull(repo.getProduct(99));
    }
}