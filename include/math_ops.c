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

float sin(int x, int steps)
{
    float sum = 0.0;
    float term = x;
    int sign = 1;

    for(int n = 0; n < steps; n++){
        if (n > 0) {
            term = term * (-1) * x * x / ((2 * n) * (2 * n + 1));
        }
        sum += term;
    }
    return sum;

}

float cos(int x, int steps)
{
    //Impliment soon
}