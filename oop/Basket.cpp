#include "Basket.h"

double Basket::total_receipt(ostream& os) const
{
    double res = 0.0;
    os << "isbn" << "\tcount" << "\tprice" << endl;
    for (auto it = items.begin(); it != items.end(); it = items.upper_bound(*it)) {
        res += print_total(os, **it, items.count(*it));
    }
    os << "\tTotal Sale: " << res << endl;

    return res;
}
