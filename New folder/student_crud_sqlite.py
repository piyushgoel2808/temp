import sqlite3


DB_NAME = "student.db"
TABLE_SQL = """
CREATE TABLE IF NOT EXISTS students (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    age INTEGER
)
"""


def create_table(conn):
    conn.execute(TABLE_SQL)
    conn.commit()
    print("Table ready.")


def insert_record(conn):
    sid = int(input("Enter id: "))
    name = input("Enter name: ").strip()
    age = int(input("Enter age: "))

    conn.execute("INSERT INTO students (id, name, age) VALUES (?, ?, ?)", (sid, name, age))
    conn.commit()
    print("Record inserted.")


def update_record(conn):
    sid = int(input("Enter id to update: "))
    new_name = input("Enter new name: ").strip()
    new_age = int(input("Enter new age: "))

    cur = conn.execute(
        "UPDATE students SET name = ?, age = ? WHERE id = ?",
        (new_name, new_age, sid),
    )
    conn.commit()
    if cur.rowcount == 0:
        print("No record found with that id.")
    else:
        print("Record updated.")


def delete_record(conn):
    sid = int(input("Enter id to delete: "))
    cur = conn.execute("DELETE FROM students WHERE id = ?", (sid,))
    conn.commit()
    if cur.rowcount == 0:
        print("No record found with that id.")
    else:
        print("Record deleted.")


def display_records(conn):
    cur = conn.execute("SELECT id, name, age FROM students ORDER BY id")
    rows = cur.fetchall()

    if not rows:
        print("No records found.")
        return

    print("\nID\tName\tAge")
    for row in rows:
        print(f"{row[0]}\t{row[1]}\t{row[2]}")


if __name__ == "__main__":
    conn = sqlite3.connect(DB_NAME)

    while True:
        print("\n1. Create Table")
        print("2. Insert Record")
        print("3. Update Record")
        print("4. Delete Record")
        print("5. Display Records")
        print("6. Exit")

        choice = input("Enter choice: ").strip()

        try:
            if choice == "1":
                create_table(conn)
            elif choice == "2":
                insert_record(conn)
            elif choice == "3":
                update_record(conn)
            elif choice == "4":
                delete_record(conn)
            elif choice == "5":
                display_records(conn)
            elif choice == "6":
                print("Exiting...")
                break
            else:
                print("Invalid choice")
        except sqlite3.IntegrityError:
            print("ID already exists. Use a different ID.")
        except ValueError:
            print("Invalid input type.")

    conn.close()
