let contexto = document.querySelector("canvas").getContext("2d");

function branch(length, angle, scale)
{
    contexto.fillRect(0, 0, 1, length);
    if(length < 8) return;
    contexto.save();
    contexto.translate(0, length);
    contexto.rotate(-angle);
    branch(length * scale, angle, scale);
    contexto.rotate(2 * angle);
    branch(length * scale, angle, scale);
    contexto.restore();
}

contexto.translate(150, 0);
branch(36, 0.5, 0.8);