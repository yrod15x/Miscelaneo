from ameba import Ameba

amoebas = []
cont = 0
while cont < 8:
    diametro = random(50, 200)
    vel = 1000 / (diametro * 50)
    x, y = random(1200), random(800)
    amoebas.append(Ameba(x, y, diametro, vel, vel))        
    cont += 1  
        
malba = Ameba(600, 400, 100, 0.3, -0.1)
corriente = PVector(0.1, -0.2)

def setup():
    size(1200, 800)
    frameRate(120)
    
def draw():
    background(51)
    puntero = PVector(mouseX, mouseY)
    ##Atraer la ameba al mouse
    for ameba in amoebas:
        diferencia = puntero - ameba.location
        #malba.location += diferencia
        ameba.propulsion += diferencia.limit(ameba.maxpropulsion/100)
        ameba.location += ameba.propulsion.limit(ameba.maxpropulsion)
        ameba.location += corriente
        ameba.display()
        rad = ameba.diametro / 2
        if ameba.location.x - rad > width:
            ameba.location.x = 0 - rad
        if ameba.location.x + rad < 0:
            ameba.location.x = width + rad
        if ameba.location.y - rad > height:
            ameba.location.y = 0 - rad
        if ameba.location.y + rad < 0:
            ameba.location.y = height + rad
        #detectar colisiones
        for b in amoebas:
            if ameba is b:
                continue
            rad2 = b.diametro / 2
            if(dist(ameba.location.x, ameba.location.y, b.location.x, b.location.y) - (rad + rad2) < 0):
                ameba.propulsion *= -1
    
    
