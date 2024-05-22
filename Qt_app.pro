QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# INCLUDEPATH += C:\Cpp_Enternal\curl-8.6.0\include
# # LIBS += -LC:\Cpp_Enternal\curl-8.6.0\lib -lcurl
# LIBS += -LC:/Cpp_Enternal/curl-8.6.0/lib -lcurl



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aftersearch.cpp \
    detailrecipe.cpp \
    loguser.cpp \
    main.cpp \
    mainwindow.cpp \
    recipewindow.cpp \
    searchhistory.cpp

HEADERS += \
    aftersearch.h \
    detailrecipe.h \
    loguser.h \
    mainwindow.h \
    recipewindow.h \
    searchhistory.h

FORMS += \
    aftersearch.ui \
    detailrecipe.ui \
    loguser.ui \
    mainwindow.ui \
    recipewindow.ui \
    searchhistory.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
