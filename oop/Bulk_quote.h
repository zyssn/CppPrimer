#pragma once
#include "Quote.h"
#include "Disc_quote.h"

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double price, size_t qty, double discount) :
        Quote(book, price), min_qty(qty), discount(discount) {}
    double net_price(size_t n) const override;
    virtual void debug() override final;
    Bulk_quote* clone() const& { return new Bulk_quote(*this); }
    Bulk_quote* clone()&& { return new Bulk_quote(std::move(*this)); }
    double print_total(ostream& os, size_t n) override;

private:
    size_t min_qty = 0;         // �����ۿ����ߵ���͹�����
    double discount = 0.0;      // ��С����ʾ���ۿ۶�
};

