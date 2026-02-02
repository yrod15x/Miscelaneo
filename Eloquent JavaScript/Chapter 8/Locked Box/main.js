/* It is a box with a lock. There is an array in the box, but you can get at it only
 when the box is unlocked. Write a function called withBoxUnlocked that takes a 
 function value as argument, unlocks the box, runs the function, and then ensures 
 that the box is locked again before returning, regardless of whether the argument 
 function returned normally or threw an exception.*/

const box = new class
{
    locked =true;
    #content = [];

    unlock() {this.locked = false};
    lock() {this.locked = true};
    get content()
    {
        if(this.locked) throw new Error("Locked");
        return this.#content;
    }
    withboxUnlocked(password)
    {
        try
        {
            (password === true) ? this.unlock() : this.lock();
            console.log(this.content);
        }
        catch(error)
        {
            console.log("Locked " + error);
        }
        finally
        {
            this.lock();
        }
    }
};

function getKey(number)
{
    let pass = Math.floor(Math.random() * 9) + 1;
    console.log(number, pass); 
    if(number % pass === 0)
    {
        return true;
    }
    return false;
}

box.withboxUnlocked(getKey(4));