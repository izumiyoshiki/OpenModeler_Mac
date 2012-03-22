#-------------------------------------------------
#
# Project created by QtCreator 2012-03-22T19:02:00
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = OpenModeler_Mac
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    opengl.cpp \
    script.cpp

HEADERS  += mainwindow.h \
    opengl.h \
    include/squirrel.h \
    include/sqstdio.h \
    include/sqstdaux.h \
    script.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    lib/libsquirrel.a \
    lib/libsqstdlib.a \
    test.nut

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/release/ -lsqstdlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/debug/ -lsqstdlib
else:symbian: LIBS += -lsqstdlib
else:unix: LIBS += -L$$PWD/lib/ -lsqstdlib

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/release/sqstdlib.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/debug/sqstdlib.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/lib/libsqstdlib.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/release/ -lsquirrel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/debug/ -lsquirrel
else:symbian: LIBS += -lsquirrel
else:unix: LIBS += -L$$PWD/lib/ -lsquirrel

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/lib/release/squirrel.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/lib/debug/squirrel.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/lib/libsquirrel.a
