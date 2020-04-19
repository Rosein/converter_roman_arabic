#include "../inc/Converter.hpp"

std::vector<std::vector<std::string>> extractRomanFromNthDigit {
   { { "" }, { "I" }, { "II" }, { "III" }, { "IV" }, { "V" }, { "VI" }, { "VII" }, { "VIII" }, { "IX" } },
   { { "" }, { "X" }, { "XX" }, { "XXX" }, { "XL" }, { "L" }, { "LX" }, { "LXX" }, { "LXXX" }, { "XC" } },
   { { "" }, { "C" }, { "CC" }, { "CCC" }, { "CD" }, { "D" }, { "DC" }, { "DCC" }, { "DCCC" }, { "CM" } },
   { { "" }, { "M" }, { "MM" }, { "MMM" } }
};

constexpr int MAX_ROMAN_NUMERAL { 3999 };
constexpr int MIN_ROMAN_NUMERAL { 1 };

std::string toRoman( int arabic )
{
    if( arabic > MAX_ROMAN_NUMERAL || MIN_ROMAN_NUMERAL > arabic )
        throw std::logic_error( "Invalid input" );
    return  extractRomanFromNthDigit [ 3 ] [ arabic        / 1000 ] +
            extractRomanFromNthDigit [ 2 ] [ arabic % 1000 / 100  ] +
            extractRomanFromNthDigit [ 1 ] [ arabic % 100  / 10   ] +
            extractRomanFromNthDigit [ 0 ] [ arabic % 10          ];
}

int extractFromRomanDigit( char romanDigit )
{
  switch( romanDigit )
  {
    case 'M': return 1000;
    case 'D': return 500;
    case 'C': return 100;
    case 'L': return 50;
    case 'X': return 10;
    case 'V': return 5;
    case 'I': return 1;
    default:
        throw std::logic_error( "Invalid input");
  }
}


int fromRoman( std::string roman )
{
    int arabic {};
    int cur {};

    for( unsigned int i = 0, roman_size = roman.size(); i < roman_size; ++i )
    {
        cur = extractFromRomanDigit( roman [ i ] );
        if( i + 1 < roman_size )
            arabic += ( cur >= extractFromRomanDigit( roman [ i + 1 ] ) ? cur : -cur );
        else
            arabic += cur;
    }

    if( roman != toRoman( arabic ) || roman.size() == 0 )
        throw std::logic_error( "Invalidate input" );

    return arabic;
}