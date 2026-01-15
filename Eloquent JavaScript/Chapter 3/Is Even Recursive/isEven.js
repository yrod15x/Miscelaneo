function isEven(number)
{
    if(number < 0)
    {
        console.log("El dato es incorrecto.")
        return undefined;
    }
    if(number == 0)
    {
        return true;

    }
    else if(number == 1)
    {
        return false;
    }
    else
    {
        return isEven(number - 2)
    }
}

console.log(isEven(-1));