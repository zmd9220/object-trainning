#ifndef CLIENTDATA_H
#define CLIENTDATA_H
//Product Number, ProductName, Quantity, Price
#include <string>
class BookData 
{
public:
   // default BookData constructor
  BookData( int = 0, const std::string & = "", 
      int = 0, double = 0.0 );

   // accessor functions for ProductNumber
   void setProductNumber( int );
   int getProductNumber() const;

   // accessor functions for ProductName
   void setProductName( const std::string & );
   std::string getProductName() const;

   // accessor functions for Quantity
   void setQuantity(  int );
    int getQuantity() const;

   // accessor functions for Price
   void setPrice( double );
   double getPrice() const;

private:
   int ProductNumber;
   char ProductName[ 15 ];
   int Quantity;
   double Price;
}; // end class BookData

#endif
