#include "Disc_quote.h"

Disc_quote::Disc_quote() = default;

Disc_quote::Disc_quote(const std::string &book,
                       double p,
                       std::size_t qty,
                       double disc)
    : Quote(book, p), quantity(qty), discount(disc) {}

Disc_quote::Disc_quote(const Disc_quote &other) = default;

Disc_quote::Disc_quote(Disc_quote &&other) = default;

Disc_quote &Disc_quote::operator=(const Disc_quote &other) = default;

Disc_quote &Disc_quote::operator=(Disc_quote &&other) = default;

Disc_quote::~Disc_quote() = default;
