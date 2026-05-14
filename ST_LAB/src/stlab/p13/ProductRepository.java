package stlab.p13;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ProductRepository {
    private final Map<String, Product> storage = new HashMap<>();

    public void add(Product product) {
        storage.put(product.getId(), product);
    }

    public Product getById(String id) {
        return storage.get(id);
    }

    public void update(Product product) {
        storage.put(product.getId(), product);
    }

    public void delete(String id) {
        storage.remove(id);
    }

    public List<Product> listAll() {
        return new ArrayList<>(storage.values());
    }
}
