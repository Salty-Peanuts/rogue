#ifndef MERCHANT_HOARD_H
#define MERCHANT_HOARD_H

#include "treasure.h"

using namespace std;


class MerchantHoard : public Treasure
{   
    public:
        MerchantHoard(int x, int y);
        string identify() override;
};

#endif

