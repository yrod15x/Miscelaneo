function withTimeOut(promise, time)
{
    //Si se ingresa el numero correcto la respuesta demora. Se recheza la promesa
    return new Promise((resolve, reject) => 
    {
        promise.then(resolve, reject);
        setTimeout(() => reject("Timed out"), time);
    });
}

function crackPassCode(networkID)
{
    //Devuelve le código de la red
    function nextDigit(code, digit)
    {
        //Usa recursion para ir encontrando cada digito de acuerdo a la respuesta del 
        //del servidor
        let newCode = code + digit;
        return withTimeOut(joinWifi(networkID, newCode), 50)
        .then(() => newCode)
        .catch(failure => 
        {
            //Recursión
            if(failure == "Timed out")
            {
                return nextDigit(code, digit + 1);
            }
            else
            {
                throw failure;
            }
        });
        return nextDigit("", 0);
    }
}

console.log(crackPassCode("HANGAR 2"))
