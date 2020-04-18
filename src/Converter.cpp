#include "../inc/Converter.hpp"

std::vector<std::vector<std::string>> extractRomanFromNthDigit {
   { { "" }, { "I" }, { "II" }, { "III" }, { "IV" }, { "V" }, {  "VI" }, { "VII" }, { "VIII" }, { "IX" } },
   { { "" }, { "X" }, { "XX" }, { "XXX" }, { "XL" }, { "L" }, {  "LX" }, { "LXX" }, { "LXXX" }, { "XC" } },
   { { "" }, { "C" }, { "CC" }, { "CCC" }, { "CD" }, { "D" }, {  "DC" }, { "DCC" }, { "DCCC" }, { "CM" } },
   { { "" }, { "M" }, { "MM" }, { "MMM" } }
};

std::string toRoman( int arabic )
{
    if( arabic > 3999 || 0 > arabic )
        throw std::range_error("Cannot be represented as roman numeral.");
    std::string roman{""};
    return  extractRomanFromNthDigit [ 3 ] [ arabic        / 1000 ] +
            extractRomanFromNthDigit [ 2 ] [ arabic % 1000 / 100  ] +
            extractRomanFromNthDigit [ 1 ] [ arabic % 100  / 10   ] +
            extractRomanFromNthDigit [ 0 ] [ arabic % 10          ];
}