import tkinter as tk


def click(value):
    current = entry_var.get()
    entry_var.set(current + str(value))


def clear_all():
    entry_var.set("")


def calculate():
    try:
        result = eval(entry_var.get())
        entry_var.set(str(result))
    except Exception:
        entry_var.set("Error")


root = tk.Tk()
root.title("Simple Calculator")
root.geometry("300x380")

entry_var = tk.StringVar()
entry = tk.Entry(root, textvariable=entry_var, font=("Arial", 18), justify="right")
entry.pack(fill="both", padx=10, pady=10)

frame = tk.Frame(root)
frame.pack(expand=True, fill="both")

buttons = [
    ["7", "8", "9", "/"],
    ["4", "5", "6", "*"],
    ["1", "2", "3", "-"],
    ["0", ".", "=", "+"],
]

for row in buttons:
    row_frame = tk.Frame(frame)
    row_frame.pack(expand=True, fill="both")
    for char in row:
        if char == "=":
            cmd = calculate
        else:
            cmd = lambda c=char: click(c)

        tk.Button(row_frame, text=char, font=("Arial", 14), command=cmd).pack(
            side="left", expand=True, fill="both", padx=2, pady=2
        )

tk.Button(root, text="Clear", font=("Arial", 14), command=clear_all).pack(
    fill="both", padx=10, pady=8
)

root.mainloop()
