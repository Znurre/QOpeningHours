######################################################################
# Automatically generated by qmake (3.1) Sun Mar 13 10:30:21 2022
######################################################################

TEMPLATE = lib
TARGET = QOpeningHours
INCLUDEPATH += .

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += display.h \
           easter_p.h \
           interval.h \
           intervalmodel.h \
           openinghours.h \
           openinghours_p.h \
           rule_p.h \
           selectors_p.h \
           qopeninghours_export.h \
           logging.h \
           openinghoursscanner_p.h \
           openinghoursparser_p.h \
           Display \
           Interval \
           IntervalModel \
           OpeningHours

SOURCES += display.cpp \
           easter.cpp \
           evaluator.cpp \
           interval.cpp \
           intervalmodel.cpp \
           openinghours.cpp \
           rule.cpp \
           selectors.cpp \
           logging.cpp \
           openinghoursparser.cpp \
           openinghourslexer.cpp

headers.files = $${HEADERS}
headers.path = $$[QT_INSTALL_HEADERS]/QOpeningHours

target.path = $$[QT_INSTALL_LIBS]

features.files = openinghours.prf
features.path = $$[QMAKE_MKSPECS]/features

INSTALLS += headers target features
