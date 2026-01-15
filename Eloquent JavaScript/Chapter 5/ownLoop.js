function repetir(inicio, test, actualizar, accion)
{
    for(let i = inicio; test(i); i = actualizar(i))
    {
        accion(i);
    }
}

repetir(0, n => n < 10 , n => n + 1, console.log);
