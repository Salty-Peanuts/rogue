#ifndef MERCHANT_HOARD_H
#define MERCHANT_HOARD_H

#include "treasure.h"

using namespace std;


class MerchantHoard : public Treasure
{
    int value;
    
 public:
    MerchantHoard();
    ~MerchantHoard();
};

#endif

