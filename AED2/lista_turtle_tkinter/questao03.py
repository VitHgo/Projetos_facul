import turtle as t
import random


NumRetangulos = int(input("Quantos retângulos você quer desenhar? "))

t.colormode(255)
for i in range(NumRetangulos):
    colorA = random.randint(0, 255)
    colorB = random.randint(0, 255)
    colorC = random.randint(0, 255)
    t.fillcolor(colorA, colorB, colorC)
    t.begin_fill()
    t.fd(300)
    t.lt(90)
    t.fd(30)
    t.lt(90)
    t.fd(300)
    t.lt(90)
    t.fd(30)
    t.end_fill()
    t.up()
    t.fd(60)
    t.down()
    t.lt(90)

t.mainloop()