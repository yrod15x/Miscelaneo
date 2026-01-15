from organizarLineas import *

texto = """ Terms such as the Internet, which were unfamiliar just 20 years ago are now common.
Students in elementary school regularly surf  the Internet and use computers to design their
classroom projects. Many people use the Internet to look for information and to communicate with others. 
This is all made possible by the availability of different software, also known as computer programs. 
Without software, a computer is useless. Software is developed by using programming languages."""

text_organizar = OrgLineas(texto)

text_organizar.info()
text_organizar.ordenar_lineas()
text_organizar.ordenar_alfabetica()
text_organizar.impimir_texto()

