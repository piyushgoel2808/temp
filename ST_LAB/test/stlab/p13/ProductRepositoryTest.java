package stlab.p13;

import org.junit.Test;

import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;

public class ProductRepositoryTest {
    @Test
    public void addAndGetProduct() {
        ProductRepository repo = new ProductRepository();
        Product product = new Product("P1", "Book", 150.0);
        repo.add(product);
        assertEquals("Book", repo.getById("P1").getName());
    }

    @Test
    public void updateProduct() {
        ProductRepository repo = new ProductRepository();
        Product product = new Product("P2", "Pen", 10.0);
        repo.add(product);
        product.setPrice(12.0);
        repo.update(product);
        assertEquals(12.0, repo.getById("P2").getPrice(), 0.0001);
    }

    @Test
    public void deleteProduct() {
        ProductRepository repo = new ProductRepository();
        Product product = new Product("P3", "Pencil", 5.0);
        repo.add(product);
        repo.delete("P3");
        assertNull(repo.getById("P3"));
    }

    @Test
    public void listAllProducts() {
        ProductRepository repo = new ProductRepository();
        repo.add(new Product("P4", "A", 1.0));
        repo.add(new Product("P5", "B", 2.0));
        List<Product> products = repo.listAll();
        assertEquals(2, products.size());
    }
}
