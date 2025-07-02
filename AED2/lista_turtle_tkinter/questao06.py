import tkinter as tk

window = tk.Tk()
window.geometry("800x600")
canvas = tk.Canvas(window, width=800, height=600)
canvas.pack()
canvas.create_polygon([150,200,300,200,225,320], fill="red", outline="black")
canvas.create_polygon([330,200,405,320,255,320], fill="green", outline="black")
canvas.create_polygon([360,200,510,200,435,320], fill="blue", outline="black")

window.mainloop()