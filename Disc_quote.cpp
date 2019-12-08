#include "Disc_quote.h"

Disc_quote::Disc_quote() = default;

Disc_quote::Disc_quote(const std::string &book,
                       double p,
                       std::size_t qty,
                       double disc)
    : Quote(book, p), quantity(qty), discount(disc) {}
