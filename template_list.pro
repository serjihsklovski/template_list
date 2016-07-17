TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -std=c11

SOURCES += main.c \
    test/list_double.c \
    lib/cexception/CException.c

HEADERS += \
    template_list.h \
    error_codes.h \
    test/list_double.h \
    lib/cclasses/cclasses.h \
    lib/cexception/CException.h

DISTFILES += \
    lib/cexception/LICENSE.txt \
    .gitignore
