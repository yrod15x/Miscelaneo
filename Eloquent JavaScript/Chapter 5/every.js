function every(nums, test)
{
    for(let i = 0; i < nums.length; i++)
    {
        if(test(i) == false) return false;
    }
    return true;
}

const nums = [2, 4, 5];
console.log(every(nums, n => n < 10));
console.log(!nums.some(n => n < 6 == false));