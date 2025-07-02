import tkinter as tk

window = tk.Tk()
window.geometry("800x600")
canvas = tk.Canvas(window, width=800, height=600, bg="white")
canvas.pack()

def criar_circulo(coordX, coordY, raio, cor):
    canvas.create_oval(coordX, coordY, coordX + 2*raio, coordY + 2*raio, width=10, outline=cor)

criar_circulo(10, 10, 100, "#0885c2")
criar_circulo(110,110, 100, '#fbb132')
criar_circulo(240,10, 100, 'black')
criar_circulo(340,110, 100, '#1c8b3c')
criar_circulo(470,10, 100, '#ed334e')


window.mainloop()