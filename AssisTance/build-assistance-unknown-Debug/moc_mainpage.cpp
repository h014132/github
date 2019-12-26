/****************************************************************************
** Meta object code from reading C++ file 'mainpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../assistance/mainpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mainpage_t {
    QByteArrayData data[13];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mainpage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mainpage_t qt_meta_stringdata_Mainpage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Mainpage"
QT_MOC_LITERAL(1, 9, 6), // "initUI"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "Forhelp"
QT_MOC_LITERAL(4, 25, 10), // "helpothers"
QT_MOC_LITERAL(5, 36, 10), // "returnmain"
QT_MOC_LITERAL(6, 47, 9), // "askcancel"
QT_MOC_LITERAL(7, 57, 9), // "tohcancel"
QT_MOC_LITERAL(8, 67, 10), // "tohTcancel"
QT_MOC_LITERAL(9, 78, 14), // "tohTdisconnect"
QT_MOC_LITERAL(10, 93, 12), // "setMainTitle"
QT_MOC_LITERAL(11, 106, 12), // "leftsideicon"
QT_MOC_LITERAL(12, 119, 13) // "rightsideicon"

    },
    "Mainpage\0initUI\0\0Forhelp\0helpothers\0"
    "returnmain\0askcancel\0tohcancel\0"
    "tohTcancel\0tohTdisconnect\0setMainTitle\0"
    "leftsideicon\0rightsideicon"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mainpage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    2,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,

       0        // eod
};

void Mainpage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Mainpage *_t = static_cast<Mainpage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initUI(); break;
        case 1: _t->Forhelp(); break;
        case 2: _t->helpothers(); break;
        case 3: _t->returnmain(); break;
        case 4: _t->askcancel(); break;
        case 5: _t->tohcancel(); break;
        case 6: _t->tohTcancel(); break;
        case 7: _t->tohTdisconnect(); break;
        case 8: _t->setMainTitle((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mainpage::staticMetaObject = {
    { &DMainWindow::staticMetaObject, qt_meta_stringdata_Mainpage.data,
      qt_meta_data_Mainpage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Mainpage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mainpage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mainpage.stringdata0))
        return static_cast<void*>(this);
    return DMainWindow::qt_metacast(_clname);
}

int Mainpage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
