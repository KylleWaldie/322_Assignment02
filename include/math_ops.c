float multiply(float x, float y) 
{
    return x * y;
}

float add(float x, float y) 
{
    return x + y;
}

float square(float x) 
{
    return x * x;
}

float cube(float x) 
{
    return x * x * x;
}

float pow(float base, int exponent ) 
{
    float res = 1;
    for(int i = 0; i < exponent; i++) 
    {
        res *= base;
    }
    return res;
}

float factorial(int n)
{
    float result = 1.0;
    for(int i =2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

float sin(int x, int steps)
{
    // Change applied inside of dummy function body
}

float cos(int x, int steps)
{
    //Impliment soon
}