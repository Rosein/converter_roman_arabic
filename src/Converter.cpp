#include "../inc/Converter.hpp"

constexpr int BEGIN_COUNTING = 1;
constexpr int TWO_OCCURANCE = 2;
constexpr int THREE_OCCURANCE = 3;


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
    return  extractRomanFromNthDigit [ 3 ] [ arabic        / 1000 ] +
            extractRomanFromNthDigit [ 2 ] [ arabic % 1000 / 100  ] +
            extractRomanFromNthDigit [ 1 ] [ arabic % 100  / 10   ] +
            extractRomanFromNthDigit [ 0 ] [ arabic % 10          ];
}


bool hasValidRomanDigits( std::string roman )
{
    if( roman.size() == 0 )
        return false;
    std::set<char> valid_roman_letters{ 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
    std::set<char> in_roman ( std::begin( roman ), std::end( roman ) );
    if( !std::includes( std::begin( valid_roman_letters ), std::end( valid_roman_letters ),
                        std::begin( in_roman ), std::end( in_roman ) ) )
                       return false;
    return true;
}


std::unordered_map<char, int> lum {
    { 'M', 1000 },
    { 'D', 500 },
    { 'C', 100 },
    { 'L', 50 },
    { 'X', 10 },
    { 'V', 5 },
    { 'I', 1 }
};

bool isHalfSymbol( int cur )
{
    return cur == lum [ 'D' ] ||
           cur == lum [ 'L' ] ||
           cur == lum [ 'V' ];
}


int fromRoman( std::string roman )
{
    if( !hasValidRomanDigits( roman )  )
        throw std::logic_error("Some character in input isn't a roman digit");
    int arabic {};
    int cur {};
    int next {};
    int counter_occurence { BEGIN_COUNTING };
    bool is_next {};
    for( unsigned int i = 0, roman_size = roman.size(); i < roman_size; ++i )
    {
        cur = lum [ roman [ i ] ];
        is_next = i + 1 < roman_size;
        if( is_next )
        {
            next = lum [ roman [ i + 1 ] ];
            if( cur >= next )
            {
                if( cur == next )
                    counter_occurence++;
                else
                    counter_occurence = BEGIN_COUNTING;
                if( counter_occurence == TWO_OCCURANCE && isHalfSymbol( cur ) )
                    throw std::logic_error("D, L, V can not be together");
                if( counter_occurence > THREE_OCCURANCE )
                    throw std::logic_error("M, C, X, I can not stay in 4-el seq.");
                arabic += cur;
            }
            else
            {
                if( next == 10 * cur || next == 5 * cur )
                {
                    arabic += - cur  + next;
                    if( i + 2 < roman_size && 
                      ( lum [ roman [ i + 2 ] ] == cur || lum [ roman [ i + 2 ] ]  == 5 * cur ) )
                        throw std::logic_error("Detect broken math rule.");
                    ++i;
                }
                else
                    throw std::logic_error("Detect broken math rule.");
            }
        }
        else
           arabic += cur;
    }
    return arabic;
}