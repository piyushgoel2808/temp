import sqlite3

# 1. Connect to (or create) the database
conn = sqlite3.connect('company.db')
cursor = conn.cursor()

# 2. Create the Employee table
cursor.execute("DROP TABLE IF EXISTS Employee")
cursor.execute('''
    CREATE TABLE Employee (
        id INTEGER PRIMARY KEY,
        name TEXT,
        department TEXT,
        salary REAL,
        bonus REAL
    )
''')

# 3. Insert records
employees = [
    (1, 'Alice', 'HR', 70000, 500),
    (2, 'Bob', 'IT', 85000, 1000),
    (3, 'Charlie', 'IT', 95000, 1200),
    (4, 'David', 'Sales', 60000, 400),
    (5, 'Eve', 'HR', 72000, 600)
]
cursor.executemany("INSERT INTO Employee VALUES (?, ?, ?, ?, ?)", employees)
conn.commit()

# 4. Delete a column
# Note: SQLite (older versions) doesn't support 'DROP COLUMN' directly. 
# Modern SQLite (3.35.0+) does. We will use the standard ALTER command:
try:
    cursor.execute("ALTER TABLE Employee DROP COLUMN bonus")
    print("Column 'bonus' deleted successfully.\n")
except sqlite3.OperationalError:
    print("Drop column not supported on this SQLite version, skipping.\n")

# 5. Display highest salary grouped by department
print(f"{'Department':<15} | {'Highest Salary':<15}")
print("-" * 33)

query = "SELECT department, MAX(salary) FROM Employee GROUP BY department"
cursor.execute(query)

for row in cursor.fetchall():
    print(f"{row[0]:<15} | ${row[1]:<15}")

# Clean up
conn.close()