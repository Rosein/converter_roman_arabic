#include "../inc/Converter.hpp"

std::string extractFromNthDigit( int & arabic, int n, std::string fullSymbol, std::string halfSymbol, std::string stepSymbol )
{
    std::string roman {""};
    std::string right {""};

    int powerOfTenth = 1;
    for( int i = 1; i < n; i++ )
        powerOfTenth *= 10;

    if( arabic % (9*powerOfTenth) == 0 && arabic >= powerOfTenth )
    {
        roman += stepSymbol+fullSymbol;
        arabic -= (9*powerOfTenth); 
    }

    while( arabic % (5*powerOfTenth) > 0 && arabic >= (5*powerOfTenth)  )
    {
        right += stepSymbol;
        arabic -= powerOfTenth;
    }

    if( arabic % (5*powerOfTenth) == 0 && arabic >= powerOfTenth )
    {
        roman += halfSymbol;
        arabic -= (5*powerOfTenth); 
    }

    roman += right;

    if( arabic / (4*powerOfTenth) == 1 &&  arabic >= powerOfTenth  )
    {
        roman += stepSymbol+halfSymbol;
        arabic -= (4*powerOfTenth); 
    }

    while( arabic / powerOfTenth > 0 &&  arabic >= powerOfTenth )
    {
        roman += stepSymbol;
        arabic -= powerOfTenth;
    }
    return roman;
}

std::string toRoman( int arabic )
{
    std::string roman{""};
    // // roman += extractFromNthDigit( arabic, 4, { "" }, { "" },  { "M" } );
    // roman += extractFromNthDigit( arabic, 3, { "M" }, { "D" },  { "C" } );
    // roman += extractFromNthDigit( arabic, 2, { "C" }, { "L" },  { "X" } );
    // roman += extractFromNthDigit( arabic, 1, { "X" }, { "V" },  { "I" } );

    return roman;
}