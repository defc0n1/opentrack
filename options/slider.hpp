/* Copyright (c) 2016 Stanislaw Halik
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 */

#pragma once

#include "export.hpp"
#include <QMetaType>
#include <QDataStream>
#include <QDebug>

namespace options
{
    class OPENTRACK_OPTIONS_EXPORT slider_value final
    {
        float cur_, min_, max_;
    public:
        slider_value(float cur, float min, float max);

        template<typename t, typename u, typename v> slider_value(t cur, u min, v max) :
            cur_(float(cur)),
            min_(float(min)),
            max_(float(max))
        {}

        slider_value(const slider_value& v);
        slider_value();
        slider_value& operator=(const slider_value& v);
        bool operator==(const slider_value& v) const;
        operator float() const { return cur_; }
        double cur() const { return double(cur_); }
        double min() const { return double(min_); }
        double max() const { return double(max_); }
        slider_value update_from_slider(int pos, int q_min, int q_max) const;
        int to_slider_pos(int q_min, int q_max) const;
    };
}

QT_BEGIN_NAMESPACE

QDebug operator << (QDebug dbg, const options::slider_value& val);
QDataStream& operator << (QDataStream& out, const options::slider_value& v);
QDataStream& operator >> (QDataStream& in, options::slider_value& v);

QT_END_NAMESPACE

Q_DECLARE_METATYPE(options::slider_value)
