#include "gtest/gtest.h"
#include "../../inc/Converter.hpp"

TEST( ToRoman, SingleDigit )
{
  EXPECT_EQ( std::string("I"), toRoman( 1 ) );
  EXPECT_EQ( std::string("II"), toRoman( 2 ) );
  EXPECT_EQ( std::string("III"), toRoman( 3 ) );
  EXPECT_EQ( std::string("IV"), toRoman( 4 ) );
  EXPECT_EQ( std::string("V"), toRoman( 5 ) );
  EXPECT_EQ( std::string("VI"), toRoman( 6 ) );
  EXPECT_EQ( std::string("VII"), toRoman( 7 ) );
  EXPECT_EQ( std::string("VIII"), toRoman( 8 ) );
  EXPECT_EQ( std::string("IX"), toRoman( 9 ) );
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
  EXPECT_EQ( std::string( "XIX" ), toRoman( 19 ) );
  EXPECT_EQ( std::string( "XLIX" ), toRoman( 49 ) );
  EXPECT_EQ( std::string( "XCIX" ), toRoman( 99 ) );
  EXPECT_EQ( std::string( "CLX" ), toRoman( 160 ) );
  EXPECT_EQ( std::string( "CMXCIX" ), toRoman( 999 ) );
  EXPECT_EQ( std::string( "MMMCMXCIX" ), toRoman( 3999 ) );

}