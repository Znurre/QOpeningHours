
#ifndef QOPENINGHOURS_EXPORT_H
#define QOPENINGHOURS_EXPORT_H

#ifdef QOPENINGHOURS_STATIC_DEFINE
#  define QOPENINGHOURS_EXPORT
#  define QOPENINGHOURS_NO_EXPORT
#else
#  ifndef QOPENINGHOURS_EXPORT
#    ifdef QOpeningHours_EXPORTS
        /* We are building this library */
#      define QOPENINGHOURS_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define QOPENINGHOURS_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef QOPENINGHOURS_NO_EXPORT
#    define QOPENINGHOURS_NO_EXPORT __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef QOPENINGHOURS_DEPRECATED
#  define QOPENINGHOURS_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef QOPENINGHOURS_DEPRECATED_EXPORT
#  define QOPENINGHOURS_DEPRECATED_EXPORT QOPENINGHOURS_EXPORT QOPENINGHOURS_DEPRECATED
#endif

#ifndef QOPENINGHOURS_DEPRECATED_NO_EXPORT
#  define QOPENINGHOURS_DEPRECATED_NO_EXPORT QOPENINGHOURS_NO_EXPORT QOPENINGHOURS_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef QOPENINGHOURS_NO_DEPRECATED
#    define QOPENINGHOURS_NO_DEPRECATED
#  endif
#endif

#endif /* QOPENINGHOURS_EXPORT_H */
