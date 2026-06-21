class Ameba():
    def __init__(self, x, y, diametro, xvel, yvel):
        self.location = PVector(x, y)
        self.diametro = diametro
        self.nucleo = {"fill": ["#ff0000", "#ff9900", "#ffff00", "#00ff00", "#0099ff"][int(random(5))],
                       "x": self.diametro * random(-0.15, 0.15),
                       "y": self.diametro * random(-0.15, 0.15),
                       "diametro": self.diametro / random(2.5, 4)
                      }
        self.propulsion = PVector(xvel, yvel)
        self.maxpropulsion = self.propulsion.mag()
    def circlePoint(self, angulo, radio):
        x = cos(angulo) * radio
        y = sin(angulo) * radio
        return [x, y]
    def display(self):
        #nucleo
        fill(self.nucleo["fill"])
        noStroke()
        circle(self.location.x + self.nucleo["x"], self.location.y + self.nucleo["y"], self.diametro / 2.5)
        #cuerpo
        fill(0x880099ff)
        stroke(255)
        strokeWeight(3)
        r = self.diametro / 2.0
        cpl = r * 0.55
        cpx, cpy = self.circlePoint(frameCount/(r/2), r/8)
        xp, xm = self.location.x+cpx, self.location.x-cpx
        yp, ym = self.location.y+cpy, self.location.y-cpy
        beginShape()
        vertex(self.location.x, self.location.y-r)
        bezierVertex(xp+cpl, yp-r, xm+r, ym-cpl,
                     self.location.x+r, self.location.y)
        bezierVertex(xp+r, yp+cpl, xm+cpl, ym+r,
                     self.location.x, self.location.y+r)
        bezierVertex(xp-cpl, yp+r, xm-r, ym+cpl,
                     self.location.x-r, self.location.y)
        bezierVertex(xp-r, yp-cpl, xm-cpl, ym-r,
        self.location.x, self.location.y-r)
        endShape()
