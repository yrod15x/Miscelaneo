let diario = [];
 
function ponerEntrada(eventos, soyArdilla)
{
    diario.push({eventos, soyArdilla})
}

function phi(table)
{
    return (table[3] * table[0] - table[2] * table[1]) /
    Math.sqrt((table[2] + table[3]) *
              (table[0] + table[1]) *
              (table[1] + table[3]) *
              (table[0] + table[2]));

} 

function tablaPorEventos(evento, journal)
{
    let table = [0, 0 , 0 , 0];
    for(let i = 0; i < journal.length; i++)
    {
        let dia = journal[i], index = 0;
        if(dia.eventos.includes(evento)) index++;
        if(dia.soyArdilla) index += 2;
        table[index] += 1;
    }
    return table;
}

function eventosOcurridos(journal)
{
    let eventos = [];
    for(let dias of journal)
    {
        for(let evento of dias.eventos)
        {
            if(!eventos.includes(evento))
            {
                eventos.push(evento);
            }
        }
    }
    return eventos;
}

ponerEntrada(["trabajar", "tocar arbol", "pizza", "correr",
    "television"], false);
ponerEntrada(["trabajar", "helado", "coliflor", "lasagna",
    "tocar arbol", "cepillarse"], false);
ponerEntrada(["fin de semana", "montar bicicleta", "descanso", "manis",
    "cerveza"], true);

//console.log(phi([76, 9, 4, 1]));
//console.log(tablaPorEventos("correr", diario));
//console.log(eventosOcurridos(diario));

for(let evento of eventosOcurridos(diario))
{
    let correlacion = phi(tablaPorEventos(evento, diario));
    if(correlacion > 0.1)
    {
        console.log(evento + ": ", correlacion);
    }  
}