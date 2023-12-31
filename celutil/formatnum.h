// formatnum.h
//
// Copyright (C) 2003, Chris Laurel <claurel@shatters.net>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

#pragma once

#include <fmt/ostream.h>

class FormattedNumber
{
public:
    FormattedNumber() = default;
    FormattedNumber(double, unsigned int _precision, unsigned int _flags);
    double getValue() const;
    double getRoundedValue() const;

    enum
    {
        GroupThousands    = 0x1,
        SignificantDigits = 0x2,
    };

    friend std::ostream& operator<<(std::ostream& out, const FormattedNumber& num);

private:
    double value;
    unsigned int precision;
    unsigned int flags;
};

#if FMT_VERSION >= 90000
template <> struct fmt::formatter<FormattedNumber> : ostream_formatter {};
#endif
