function tomarElemsPor(padre, tagHijo)
{
    if(typeof(padre) === undefined)
    {
        return undefined;
    }
    for(let item of Array.from(padre.childNodes))
    {
        if(item.nodeName.toLowerCase() === tagHijo) console.log(item);
    }
}

let padre = document.querySelector("ul");
tomarElemsPor(padres, "li");