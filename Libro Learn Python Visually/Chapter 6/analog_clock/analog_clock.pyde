def setup():
    size(1600, 1200)
    
def draw():
    segundos = second()
    minutos = minute()
    horas = hour()
    background(51)
    noFill()
    stroke("#ffffff")
    strokeWeight(4)
    translate(width //2, height // 2)
    circle(0, 0, 800)
    
    #Se rota antes para compensar el desafase
    rotate(-HALF_PI)
    #Horero
    pushMatrix()
    strokeWeight(12)
    rotate(TAU / 12 * horas)
    line(0, 0, 180, 0)
    popMatrix()
    
    rotate(-QUARTER_PI)
    #Minutero
    pushMatrix()
    strokeWeight(8)
    rotate(TAU / 24 * minutos)
    line(0, 0, 280, 0)
    popMatrix()
    
    #Segundero
    rotate(QUARTER_PI)
    pushMatrix()
    strokeWeight(4)
    rotate(TAU / 60 * segundos)
    line(0, 0, 370, 0)
    popMatrix()
    
