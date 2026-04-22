export function suma(num1, num2)
{
    return num1 + num2;
}

export function resta(num1, num2)
{
    return num1 - num2;
}

export function producto(num1, num2)
{
    return num1 * num2;
}

export function divison(num1, num2)
{
    if(num2 != 0) return num1 / num2;
    throw new Error("El numero es cero.");
}