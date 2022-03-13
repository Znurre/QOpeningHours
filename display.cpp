/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "display.h"
#include "interval.h"
#include "openinghours.h"

#include <cmath>

using namespace QOpeningHours;

QString Display::currentState(const OpeningHours &oh)
{
    if (oh.error() != OpeningHours::NoError) {
        return {};
    }

    const auto now = QDateTime::currentDateTime();
    const auto i = oh.interval(now);
    if (i.hasOpenEnd()) {
        switch (i.state()) {
            case Interval::Open:
                return i.comment().isEmpty() ? QStringLiteral("Open") : QStringLiteral("Open (%1)").arg(i.comment());
            case Interval::Closed:
                return i.comment().isEmpty() ? QStringLiteral("Closed") : QStringLiteral("Closed (%1)").arg(i.comment());
            case Interval::Unknown:
            case Interval::Invalid:
                return {};
        }
    }

    const auto next = oh.nextInterval(i);
    // common transitions we have texts for
    if ((i.state() == Interval::Closed && next.state() == Interval::Open)
     || (i.state() == Interval::Open && next.state() == Interval::Closed)
    ) {

        // time to change is 90 min or less
        const auto timeToChange = now.secsTo(i.end());
        if (timeToChange < 90 * 60) {
            const int minDiff = std::ceil(timeToChange / 60.0);
            switch (i.state()) {
                case Interval::Open:
                    return i.comment().isEmpty()
                        ? QStringLiteral("Open for %1 more minutes").arg(minDiff)
                        : QStringLiteral("Open for %1 more minutes (%2)").arg(minDiff).arg(i.comment());
                case Interval::Closed:
                    return i.comment().isEmpty()
                        ? QStringLiteral("Currently closed, opens in %1 minutes").arg(minDiff)
                        : QStringLiteral("Currently closed (%2), opens in %1 minutes").arg(minDiff).arg(i.comment());
                case Interval::Unknown:
                case Interval::Invalid:
                    return {};
            }
        }

        // time to change is 24h or less
        if (timeToChange < 24 * 60 * 60) {
            const int hourDiff = std::round(timeToChange / (60.0 * 60.0));
            switch (i.state()) {
                case Interval::Open:
                    return i.comment().isEmpty()
                        ? QStringLiteral("Open for %1 more hours").arg(hourDiff)
                        : QStringLiteral("Open for %1 more hours (%2)").arg(hourDiff).arg(i.comment());
                case Interval::Closed:
                    return i.comment().isEmpty()
                        ? QStringLiteral("Currently closed, opens in %1 hours").arg(hourDiff)
                        : QStringLiteral("Currently closed (%2), opens in %1 hours").arg(hourDiff).arg(i.comment());
                case Interval::Unknown:
                case Interval::Invalid:
                    return {};
            }
        }

        // time to change is 7 days or less
        if (timeToChange < 7 * 24 * 60 * 60) {
            const int dayDiff = std::round(timeToChange / (24.0 * 60.0 * 60.0));
            switch (i.state()) {
                case Interval::Open:
                    return i.comment().isEmpty()
                        ? QStringLiteral("Open for %1 more days").arg(dayDiff)
                        : QStringLiteral("Open for %1 more days (%2)").arg(dayDiff).arg(i.comment());
                case Interval::Closed:
                    return i.comment().isEmpty()
                        ? QStringLiteral("Currently closed, opens in %1 days").arg(dayDiff)
                        : QStringLiteral("Currently closed (%2), opens in %1 days").arg(dayDiff).arg(i.comment());
                case Interval::Unknown:
                case Interval::Invalid:
                    return {};
            }
        }
    }

    // next change is further ahead than one week, or we are transitioning in a way we don't handle above
    switch (i.state()) {
        case Interval::Open:
            return i.comment().isEmpty() ? QStringLiteral("Currently open") : QStringLiteral("Currently open (%1)").arg(i.comment());
        case Interval::Closed:
            return i.comment().isEmpty() ? QStringLiteral("Currently closed") : QStringLiteral("Currently closed (%1)").arg(i.comment());
        case Interval::Unknown:
            return i.comment();
        case Interval::Invalid:
            return {};
    }

    return {};
}
