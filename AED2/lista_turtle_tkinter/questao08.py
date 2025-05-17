import tkinter as tk

NumT = int(input("Insira um valor:"))

window = tk.Tk()
window.geometry("800x600")
canvas = tk.Canvas(window, width=800, height=600, bg="white")
canvas.pack()

def criar_circulo(coordX, coordY, raio, cor, borda):
    canvas.create_oval(coordX, coordY, coordX + 2*raio, coordY + 2*raio, fill=cor, outline=borda)

def criar_retangulo(coordX, coordY, lado, cor, borda):
    canvas.create_rectangle(coordX, coordY, coordX+lado,coordY+lado, fill=cor, outline=borda)

def criar_triangulo(coordX, coordY, lado, cor, borda):
    canvas.create_polygon(coordX, coordY, coordX+lado, coordY, coordX+(lado/2), coordY-lado, fill=cor, outline=borda)

canvas.create_line(10+NumT,10,10+NumT,2*NumT+10, width=2, fill="black")
canvas.create_line(10,10+NumT,2*NumT+10,10+NumT, width=2, fill="black")

criar_circulo((5/100*NumT)+10, (105/100*NumT)+10, 45/100*NumT, '#FF6347', 'red')
criar_retangulo(10+(NumT*105/100), 10+(NumT*105/100), 9/10*NumT, '#6495ED', 'blue')
criar_triangulo(10+(NumT*105/100), 10+(NumT*95/100), 9/10*NumT, '#32CD32', 'green')

window.mainloop()