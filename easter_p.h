/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef QOPENINGHOURS_EASTER_P_H
#define QOPENINGHOURS_EASTER_P_H

class QDate;

namespace QOpeningHours {

/** Basic easter holiday in Gregorian calendar computation.
 *  This should be provided by KHolidays, but is tricky to expose there due to its
 *  internal outdated QCalendarSystem copy.
 */
namespace Easter
{
    QDate easterDate(int year);
}

}

#endif // QOPENINGHOURS_EASTER_P_H
