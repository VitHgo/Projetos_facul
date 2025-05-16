import tkinter as tk

NumT = int(input("Insira um valor:"))

window = tk.Tk()
window.geometry("800x600")
canvas = tk.Canvas(window, width=800, height=600, bg="white")
canvas.pack()

canvas.create_line(10+NumT,10,10+NumT,2*NumT+10, width=2, fill="black")
canvas.create_line(10,10+NumT,2*NumT+10,10+NumT, width=2, fill="black")

canvas.create_oval(10,10,(9/10*NumT),(9/10*NumT) , fill='#FF6347' , outline="red")

window.mainloop()