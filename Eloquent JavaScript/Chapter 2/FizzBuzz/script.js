for(let i = 1; i < 130; i++)
{
    if(i % 3 == 0)
    {
        if(i % 5 == 0)
        {
            console.log(i, " = Fizz - Buzz");
            break;
        }
        console.log(i, " = Fizz");
    }
    else if((i % 5 == 0) && (i % 3 != 0))
    {
        console.log(i, " = Buzz");
    }
    
}