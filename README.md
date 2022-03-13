# QOpeningHours
Super sloppy port of KOpeningHours to only rely on Qt.

This port sacrifices the support for public holidays and words such as "dawn" and "sunrise" for the benefit of only relying on Qt.

See https://invent.kde.org/libraries/kopeninghours for original code.

# Installation

```
qmake
make
make install
```

# Usage

```
CONFIG += openinghours
```
