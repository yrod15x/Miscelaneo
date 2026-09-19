"""Web page routes"""

from flask import render_template, redirect, flash
from app import app
from app.forms import Form

color: str = "black"
board: list[list[str]] = [[color for _ in range(8)] for _ in range(8)]
row: int = -1
column: int = -1

@app.route('/')
@app.route('/index')
def index():
    """Home page route"""   
    row_cont: int = 0
    form = Form()
    for row in range(8):
        if row_cont % 2 == 0:
            color = "white"
        else:
            color = "black"   
        for col in range(8):
            board[row][col] = color
            if color == "white":
                color = "black"
            else:
                color = "white"  
        row_cont += 1     
    return render_template('index.html', board=board, form=form, row=row,
                           column=column)

@app.route("/find_color", methods=['GET', 'POST'])
def find_color():
    """Encuentra el color de la celda"""
    form = Form()
    cell_color = ''
    if form.validate_on_submit():
        row: int = form.row.data - 1
        column: int = form.column.data - 1
        if 0 < row > 64 or 0 < column > 64:           
           flash("Number out of range")
           return render_template('index.html', board=board, form=form)
        else:
            for r in range(8):
                for c in range(8):
                    if r == row and c == column:
                        if board[r][c] == 'white':
                            cell_color = 'black'
                        else:
                            cell_color = 'white'
                        return render_template('index.html', board=board, form=form,
                                    row=row, column=column, cell_color=cell_color) 
        #print(f"({row}, {column})")       
    return render_template('index.html', board=board, form=form)
   