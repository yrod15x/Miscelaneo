function deepEqual(item1, item2)
{
    
    if(typeof(item1) == "object" && item1 != null
     && typeof(item2) == "object" && item2 != null)
    {
        let props1 = Object.keys(item1);
        let props2 = Object.keys(item2);
        if(props1.length != props2.length)
        {
            return false;
        }
        else
        {
            for(let i = 0; i < props1.length; i++)
            {
                if(props1[i] != props2[i]) return false;
            }
        }
        return true;
    }
    else
    {
        return (item1 === item2);
    }
    
    
}

let obj1 = {
    prop1 : 1,
    prop2 : 2,
};

let obj2 = {
    prop1 : 1,
    prop2 : 2,
};

console.log(deepEqual(obj1, obj2));