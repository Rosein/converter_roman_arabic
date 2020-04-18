#include "../inc/Converter.hpp"

std::string extractFromNthDigit( int digit, std::string fullSymbol, std::string halfSymbol, std::string stepSymbol )
{
    if( digit == 9 ) return stepSymbol + fullSymbol;
    if( digit == 8 ) return halfSymbol + stepSymbol + stepSymbol + stepSymbol;
    if( digit == 7 ) return halfSymbol + stepSymbol + stepSymbol;
    if( digit == 6 ) return halfSymbol + stepSymbol;
    if( digit == 5 ) return halfSymbol;
    if( digit == 4 ) return stepSymbol + halfSymbol;
    std::string roman {""};
    while( digit-- )
        roman += stepSymbol;
    return roman;
}

std::string toRoman( int arabic )
{
    std::string roman{""};
    int index_digit = 1000;
    int digit = arabic / index_digit;
    while( digit-- )
        roman += "M";
    
    digit = ( arabic % index_digit ) / ( index_digit / 10 );
    index_digit /= 10;
    roman += extractFromNthDigit( digit, { "M" }, { "D" },  { "C" } );
    digit = ( arabic % index_digit ) / ( index_digit / 10 );
    index_digit /= 10;
    roman += extractFromNthDigit( digit, { "C" }, { "L" },  { "X" } );
    digit = ( arabic % index_digit ) / ( index_digit / 10 );
    roman += extractFromNthDigit( digit, { "X" }, { "V" },  { "I" } );
    return roman;
}