/****************************************************************************
** Meta object code from reading C++ file 'tohelpothers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../assistance/tohelpothers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tohelpothers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tohelpothers_t {
    QByteArrayData data[16];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tohelpothers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tohelpothers_t qt_meta_stringdata_Tohelpothers = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Tohelpothers"
QT_MOC_LITERAL(1, 13, 10), // "sendTomain"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 16), // "sendTomaincancel"
QT_MOC_LITERAL(4, 42, 16), // "sendTodisconnect"
QT_MOC_LITERAL(5, 59, 6), // "initUI"
QT_MOC_LITERAL(6, 66, 8), // "QWidget*"
QT_MOC_LITERAL(7, 75, 10), // "connection"
QT_MOC_LITERAL(8, 86, 12), // "connectflase"
QT_MOC_LITERAL(9, 99, 11), // "connecttrue"
QT_MOC_LITERAL(10, 111, 11), // "mainconnect"
QT_MOC_LITERAL(11, 123, 11), // "getLineEdit"
QT_MOC_LITERAL(12, 135, 11), // "mainycancel"
QT_MOC_LITERAL(13, 147, 11), // "connecttype"
QT_MOC_LITERAL(14, 159, 14), // "mainDisconnect"
QT_MOC_LITERAL(15, 174, 10) // "newconnect"

    },
    "Tohelpothers\0sendTomain\0\0sendTomaincancel\0"
    "sendTodisconnect\0initUI\0QWidget*\0"
    "connection\0connectflase\0connecttrue\0"
    "mainconnect\0getLineEdit\0mainycancel\0"
    "connecttype\0mainDisconnect\0newconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tohelpothers[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   82,    2, 0x0a /* Public */,
       7,    0,   83,    2, 0x0a /* Public */,
       8,    0,   84,    2, 0x0a /* Public */,
       9,    0,   85,    2, 0x0a /* Public */,
      10,    0,   86,    2, 0x0a /* Public */,
      11,    0,   87,    2, 0x0a /* Public */,
      12,    0,   88,    2, 0x0a /* Public */,
      13,    0,   89,    2, 0x0a /* Public */,
      14,    0,   90,    2, 0x0a /* Public */,
      15,    0,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    0x80000000 | 6,
    0x80000000 | 6,
    0x80000000 | 6,
    0x80000000 | 6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tohelpothers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tohelpothers *_t = static_cast<Tohelpothers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendTomain(); break;
        case 1: _t->sendTomaincancel(); break;
        case 2: _t->sendTodisconnect(); break;
        case 3: { QWidget* _r = _t->initUI();
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 4: { QWidget* _r = _t->connection();
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 5: { QWidget* _r = _t->connectflase();
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 6: { QWidget* _r = _t->connecttrue();
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = std::move(_r); }  break;
        case 7: _t->mainconnect(); break;
        case 8: _t->getLineEdit(); break;
        case 9: _t->mainycancel(); break;
        case 10: _t->connecttype(); break;
        case 11: _t->mainDisconnect(); break;
        case 12: _t->newconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Tohelpothers::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tohelpothers::sendTomain)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Tohelpothers::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tohelpothers::sendTomaincancel)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Tohelpothers::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Tohelpothers::sendTodisconnect)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tohelpothers::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tohelpothers.data,
      qt_meta_data_Tohelpothers,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tohelpothers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tohelpothers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tohelpothers.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Tohelpothers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Tohelpothers::sendTomain()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tohelpothers::sendTomaincancel()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Tohelpothers::sendTodisconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
