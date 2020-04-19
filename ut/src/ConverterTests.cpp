#include "gtest/gtest.h"
#include "../../inc/Converter.hpp"
#include <sstream>
#include <iostream>


TEST( ToRoman, SingleDigit )
{
  EXPECT_EQ( std::string("I")   , toRoman( 1 ) );
  EXPECT_EQ( std::string("II")  , toRoman( 2 ) );
  EXPECT_EQ( std::string("III") , toRoman( 3 ) );
  EXPECT_EQ( std::string("IV")  , toRoman( 4 ) );
  EXPECT_EQ( std::string("V")   , toRoman( 5 ) );
  EXPECT_EQ( std::string("VI")  , toRoman( 6 ) );
  EXPECT_EQ( std::string("VII") , toRoman( 7 ) );
  EXPECT_EQ( std::string("VIII"), toRoman( 8 ) );
  EXPECT_EQ( std::string("IX")  , toRoman( 9 ) );
}

TEST( ToRoman, TensDigit )
{
  EXPECT_EQ( std::string("X")  , toRoman( 10 ) );
  EXPECT_EQ( std::string("XX") , toRoman( 20 ) );
  EXPECT_EQ( std::string("XXX"), toRoman( 30 ) );
  EXPECT_EQ( std::string("XL") , toRoman( 40 ) );
  EXPECT_EQ( std::string("L")  , toRoman( 50 ) );
}

TEST( ToRoman, ComplexNumbers )
{
  EXPECT_EQ( std::string( "XIX" )      , toRoman( 19 ) );
  EXPECT_EQ( std::string( "XLIX" )     , toRoman( 49 ) );
  EXPECT_EQ( std::string( "XCIX" )     , toRoman( 99 ) );
  EXPECT_EQ( std::string( "CLX" )      , toRoman( 160 ) );
  EXPECT_EQ( std::string( "CMXCIX" )   , toRoman( 999 ) );
  EXPECT_EQ( std::string( "MMMCMXCIX" ), toRoman( 3999 ) );
}

TEST( FromRoman, SingleDigit )
{
  EXPECT_EQ( 1  , fromRoman( "I" ) );
  EXPECT_EQ( 2  , fromRoman( "II" ) );
  EXPECT_EQ( 3  , fromRoman( "III" ) );
  EXPECT_EQ( 4  , fromRoman( "IV" ) );
  EXPECT_EQ( 5  , fromRoman( "V" ) );
  EXPECT_EQ( 6  , fromRoman( "VI" ) );
  EXPECT_EQ( 7  , fromRoman( "VII" ) );
  EXPECT_EQ( 8  , fromRoman( "VIII" ) );
  EXPECT_EQ( 9  , fromRoman( "IX" ) );
}

TEST( FromRoman, ComplexNumbers )
{
  EXPECT_EQ( 3999, fromRoman( "MMMCMXCIX" ) );
  EXPECT_EQ( 1234, fromRoman( "MCCXXXIV" ) );
  EXPECT_EQ( 900,  fromRoman( "CM" ) ); 
}

TEST( FromRoman, WrongNumbers )
{
  EXPECT_FALSE( hasValidRomanDigits( "MMMK" ) );
  EXPECT_TRUE( hasValidRomanDigits( "MMM" ) );
  EXPECT_THROW( fromRoman( "MMMKMM" ), std::logic_error );
  EXPECT_THROW( fromRoman( "MMMM" ), std::logic_error );
  EXPECT_THROW( fromRoman( "XM" ), std::logic_error );
  EXPECT_THROW( fromRoman( "" ), std::logic_error );
  EXPECT_THROW( fromRoman( "IXII" ), std::logic_error );
  EXPECT_THROW( fromRoman( "XCX" ), std::logic_error );
  EXPECT_THROW( fromRoman( "B" ), std::logic_error );
  EXPECT_THROW( fromRoman( "IIIM" ), std::logic_error );
  EXPECT_THROW( fromRoman( "VV" ), std::logic_error );
}