/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package stlab;

// src/ProductRepository.java
import java.util.*;

public class ProductRepository {

    private Map<Integer, Product> repo = new HashMap<>();

    // CREATE
    public void addProduct(Product p) {
        repo.put(p.getId(), p);
    }

    // READ
    public Product getProduct(int id) {
        return repo.get(id);
    }

    // UPDATE
    public void updateProduct(int id, String name, double price) {
        Product p = repo.get(id);
        if (p != null) {
            p.setName(name);
            p.setPrice(price);
        }
    }

    // DELETE
    public void deleteProduct(int id) {
        repo.remove(id);
    }

    // HELPER
    public int size() {
        return repo.size();
    }
}