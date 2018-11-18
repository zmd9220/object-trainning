// Class BookData stores information.
#include <string>
#include "bookData.h"
using namespace std;

// default BookData constructor
BookData::BookData( int productNumberValue, const string &produckName, 
   int quantityValue, double priceValue )
   : ProductNumber( productNumberValue ), Quantity( quantityValue ),Price( priceValue )
{
   setProductName( produckName );
} // end BookData constructor

// get ProductNumber value
int BookData::getProductNumber() const
{
   return ProductNumber;
} // end function getProductNumber

// set ProductNumber value
void BookData::setProductNumber(  int productNumberValue )
{
   ProductNumber = productNumberValue; // should validate
} // end function setProductNumber

// get ProductName value
string BookData::getProductName() const
{
   return ProductName;
} // end function getProductName

// set ProductName value
void BookData::setProductName( const string &ProductNamString )
{
   // copy at most 15 characters from string to ProductName
   int length = ProductNamString.size();
   length = ( length < 15 ? length : 14 );
   strncpy_s(ProductName, ProductNamString.c_str(), length);
 //  ProductNamString.copy( ProductName, length );
   ProductName[ length ] = '\0'; // append null character to ProductName
} // end function setProductName

// get Quantity value
int BookData::getQuantity() const
{
   return Quantity;
} // end function getFirstName

// set Quantity value
void BookData::setQuantity( int quantityValue )
{
  Quantity = quantityValue;
} // end function setQuantity

// get Price value
double BookData::getPrice() const
{
   return Price;
} // end function getPrice

// set Price value
void BookData::setPrice( double priceValue )
{
   Price = priceValue;
} // end function setPrice

