#include <iostream>
#include <string>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

ZZ mod(ZZ n, ZZ mod){
    ZZ q = n / mod;
    ZZ r = n - (mod*q);
    if (r >= 0) {
    	return r;
    }
    return mod + r;
}
ZZ mcd(ZZ x, ZZ y) {
        if (x < y) {
            ZZ temp = x;
            x = y;
            y = temp;
        }
        ZZ r = mod(x, y);

        while (r != 0) {

            x = y;
            y = r;
            r = mod(x, y);

        }
        return y;
    }

void mcdext(ZZ &inv,ZZ n1,ZZ n2){

       ZZ x=ZZ(0),y=ZZ(0),d=ZZ(0),x2 = ZZ(1),x1 = ZZ(0),y2 = ZZ(0),y1 = ZZ(1),q = ZZ(0), r = ZZ(0);

       while(n2>0)
          {
         q = (n1/n2);
          r = n1 - q*n2;
          x = x2-q*x1;
          y = y2 - q*y1;
          n1 = n2;
          n2 = r;
          x2 = x1;
          x1 = x;
          y2 = y1;
          y1 = y;
          }
          //cadena[0] = n1;   // mcd (n1,n2)
          //cadena[1] = x2;   // x
          inv = y2;   // y
    }

ZZ inversa(ZZ mod , ZZ a)
    {
         ZZ inv;
        mcdext(inv, mod , a);
         ZZ inver =  inv;
         if (inver < 0)
         {
            inver = mod + inver;
            return inver;
         }
         else return inver;
    }
ZZ expmod(ZZ a, ZZ exp, ZZ m){
        ZZ r = ZZ(1);
        while(exp>ZZ(0)){
            if((exp&1)==1){
                r = mod(r*a,m);
            }
            a = mod(a*a,m);
            exp>>=1;
        }
        return r;
    }
