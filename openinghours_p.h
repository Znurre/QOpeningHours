/*
    SPDX-FileCopyrightText: 2020 Volker Krause <vkrause@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef QOPENINGHOURS_OPENINGHOURS_P_H
#define QOPENINGHOURS_OPENINGHOURS_P_H

#include "openinghours.h"
#include "rule_p.h"

#include <QSharedData>
#include <QTimeZone>

#include <cmath>
#include <memory>
#include <vector>

namespace QOpeningHours {
class OpeningHoursPrivate : public QSharedData {
public:
    void finalizeRecovery();
    void autocorrect();
    void simplify();
    void validate();
    void addRule(Rule *parsedRule);
    void restartFrom(int pos, Rule::Type nextRuleType);
    bool isRecovering() const;

    std::vector<std::unique_ptr<Rule>> m_rules;
    OpeningHours::Modes m_modes = OpeningHours::IntervalMode;
    OpeningHours::Error m_error = OpeningHours::NoError;

    float m_latitude = NAN;
    float m_longitude = NAN;
    int m_restartPosition = 0;
    Rule::Type m_initialRuleType = Rule::NormalRule;
    Rule::Type m_recoveryRuleType = Rule::NormalRule;
    bool m_ruleSeparatorRecovery = false;

    QTimeZone m_timezone = QTimeZone::systemTimeZone();
};

}

#endif
