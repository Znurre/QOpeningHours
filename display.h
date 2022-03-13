/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef QOPENINGHOURS_DISPLAY_H
#define QOPENINGHOURS_DISPLAY_H

#include "qopeninghours_export.h"

class QString;

namespace QOpeningHours {

class OpeningHours;

/** Utilities for displaying human-readable/localized opening hours information. */
namespace Display
{
    /** Localized description of the current opening state, and upcoming transitions. */
    QOPENINGHOURS_EXPORT QString currentState(const OpeningHours &oh);
}

}

#endif // QOPENINGHOURS_DISPLAY_H
