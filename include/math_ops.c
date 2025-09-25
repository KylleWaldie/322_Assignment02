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
    float result = 0.0;

    for (int n = 0; n < steps; ++n) {
        int exponent = 2 * n + 1;
        double term = (pow(-1, n) * pow(x, exponent)) / factorial(exponent);
        result += term;
    }
    return result;

}

float cos(float x, int steps)
{
    float result = 0.0;

    for (int n = 0; n < steps; n++)
    {
        // (-1)^n
        float sign = (n % 2 == 0) ? 1.0 : -1.0;

        // x^(2n)
        float numerator = pow(x, 2 * n);

        // (2n)!
        float denominator = factorial(2 * n);

        // Add term
        result += sign * (numerator / denominator);
    }

    return result;
}