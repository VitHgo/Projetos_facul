import turtle as t

NumTriangulos = int(input("Insira o numero de triangulos que deseja:"))
LadoTriangulo = 60
EspacoTriangulos = (800/5)-(LadoTriangulo/2)

t.lt(180)
t.up()
t.fd(450)
t.lt(180)
t.down()

for contT in range(NumTriangulos):
    t.fd(EspacoTriangulos)
    t.lt(60)
    t.fd(LadoTriangulo)
    t.rt(120)
    t.fd(LadoTriangulo)
    t.lt(60)
t.fd(EspacoTriangulos)
    
t.mainloop()