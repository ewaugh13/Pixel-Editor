/****************************************************************************
** Meta object code from reading C++ file 'setspritesize.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gixel/setspritesize.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setspritesize.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SetSpriteSize_t {
    QByteArrayData data[12];
    char stringdata0[214];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetSpriteSize_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetSpriteSize_t qt_meta_stringdata_SetSpriteSize = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SetSpriteSize"
QT_MOC_LITERAL(1, 14, 17), // "setHeightAndWidth"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 8), // "closeApp"
QT_MOC_LITERAL(4, 42, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(5, 64, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(6, 86, 29), // "on_heightSpinbox_valueChanged"
QT_MOC_LITERAL(7, 116, 4), // "arg1"
QT_MOC_LITERAL(8, 121, 28), // "on_widthSpinBox_valueChanged"
QT_MOC_LITERAL(9, 150, 27), // "on_heightSlider_sliderMoved"
QT_MOC_LITERAL(10, 178, 8), // "position"
QT_MOC_LITERAL(11, 187, 26) // "on_widthSlider_sliderMoved"

    },
    "SetSpriteSize\0setHeightAndWidth\0\0"
    "closeApp\0on_buttonBox_accepted\0"
    "on_buttonBox_rejected\0"
    "on_heightSpinbox_valueChanged\0arg1\0"
    "on_widthSpinBox_valueChanged\0"
    "on_heightSlider_sliderMoved\0position\0"
    "on_widthSlider_sliderMoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetSpriteSize[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       3,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   60,    2, 0x08 /* Private */,
       5,    0,   61,    2, 0x08 /* Private */,
       6,    1,   62,    2, 0x08 /* Private */,
       8,    1,   65,    2, 0x08 /* Private */,
       9,    1,   68,    2, 0x08 /* Private */,
      11,    1,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void SetSpriteSize::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetSpriteSize *_t = static_cast<SetSpriteSize *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setHeightAndWidth((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->closeApp(); break;
        case 2: _t->on_buttonBox_accepted(); break;
        case 3: _t->on_buttonBox_rejected(); break;
        case 4: _t->on_heightSpinbox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_widthSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_heightSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_widthSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SetSpriteSize::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetSpriteSize::setHeightAndWidth)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SetSpriteSize::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SetSpriteSize::closeApp)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SetSpriteSize::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SetSpriteSize.data,
      qt_meta_data_SetSpriteSize,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SetSpriteSize::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetSpriteSize::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SetSpriteSize.stringdata0))
        return static_cast<void*>(const_cast< SetSpriteSize*>(this));
    return QDialog::qt_metacast(_clname);
}

int SetSpriteSize::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SetSpriteSize::setHeightAndWidth(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SetSpriteSize::closeApp()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
