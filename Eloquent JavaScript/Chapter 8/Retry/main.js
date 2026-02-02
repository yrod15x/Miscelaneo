/*Retry
Say you have a function primitiveMultiply that in 20 percent of cases multiplies 
two numbers and in the other 80 percent of cases raises an exception of type 
MultiplicatorUnitFailure. Write a function that wraps this clunky function and 
just keeps trying until a call succeeds, after which it returns the result.
*/

class MultiplicatorUnitFailure extends Error {}

function primitiveMultiplication(num1, num2)
{
    let posiblilidad = Math.random();
    if(posiblilidad < 0.2)
    {
        console.log(num1 * num2);
        return;
    }
    throw new MultiplicatorUnitFailure("Imposible Multiplicar" + posiblilidad);
}

function enhancedMultiplication()
{
    for(;;)
    {
        let num1 = Math.floor(Math.random() * 10) + 1;
        let num2 = Math.floor(Math.random() * 10) + 1;
        try
        {
            primitiveMultiplication(num1, num2);
            break;
        }
        catch(e)
        {
            if(e instanceof MultiplicatorUnitFailure)
            {
                console.log("Posibilidad fuera de rango. Vuelva a intentar");
            }
            else
            {
                throw(e);
            }
        }
    }
    
}

enhancedMultiplication();