/* Programa que expresa si un número es par o impar. Incluye funciones para
establecer si un texto tiene igualmente un número es par o impar de carácteres. */

function isEvenOdd(number)
{
    /*Programa que expresa si un número es par o impar. Args: number (int): número entero. Returns: bool: verdadero si par*/
    return (number % 2 === 0);
}

function printInfo()
{
    let number = Math.floor(Math.random() * 100000);
    if(isEvenOdd(number))
    {
        console.log(`${number} is an even number.`);
    }
    else
    {
        console.log(`${number} is an odd number.`);
    }
}

for(let i = 0; i < 5; i++)
{
    printInfo();
}
