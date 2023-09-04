/*

What type of conversion happens in each of the following cases? 
Valid answers are: No conversion needed, numeric promotion, numeric conversion, won’t compile due to narrowing conversion. 
Assume int and long are both 4 bytes.

*/

void question1()
{
    int a{ 5 };                     // 1a - no conversion
    int b{ 'a' };                   // 1b - char->int - promotion
    //int c{ 5.4 };                   // 1c - double->int - wont compile (narrowing conversion)
    int d{ true };                  // 1d - bool->int - promotion
    int e{ static_cast<int>(5.4) }; // 1e - double->int - (explicit) conversion
    double f{ 5.0f };               // 1f - float->double - promotion
    double g{ 5 };                  // 1g - int->double - conversion

    // Extra credit section
    long h{ 5 };                    // 1h - int->long - conversion
    //float i{ f };                   // 1i - double->float - wont compile (narrowing conversion because f is not constexpr)
    float j{ 5.0 };                 // 1j - double->float - (wrong) wont compile (narrowing conversion)
                                    // conversion double->float (this is allowed since 5.0 is constexpr and fits in the range of the float)
}