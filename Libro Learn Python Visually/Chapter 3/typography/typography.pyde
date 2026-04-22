size(1000, 640)
background("#004477")
fill("#ffffff")
stroke("#0099ff")
strokeWeight(3)

pangram = "Quartz jock vends BMW glyph fix"

text(pangram, 50, 100)

textSize(20)
text(pangram, 50, 150)

line(textWidth(pangram) + 50, 0, textWidth(pangram) + 50, height)

fuente = createFont('Dejavu Sans', 16)
textFont(fuente)
text(pangram, 50, 200)

textLeading(10)
text(pangram, 50, 250, 300, 100)
textAlign(RIGHT)
text(pangram, 50, 300, 300, 100)
