size(1200, 1200)
noStroke()
background(51)

bands = ["#ff0000", "#ff9900", "#ffff00", "#00ff00", "#0099ff", "#6633ff"]
bwidth = 150

translate(0, 150)
for index, band in enumerate(bands):
    fill(band)
    rect(0, 0, width, bwidth)
    fill("#ffffff")
    textSize(75)
    text(index + 1, 60, 100)
    translate(0, bwidth)
  
