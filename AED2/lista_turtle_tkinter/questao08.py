import tkinter as tk

NumT = int(input("Insira um valor:"))

window = tk.Tk()
window.geometry("800x600")
canvas = tk.Canvas(window, width=800, height=600, bg="white")
canvas.pack()

canvas.create_line(200,300,600,300, width=2, fill="black")
canvas.create_line(400,500,400,100, width=2, fill="black")

canvas.create_oval(210,310,390,490, fill='#FF6347' , outline="red")

window.mainloop()