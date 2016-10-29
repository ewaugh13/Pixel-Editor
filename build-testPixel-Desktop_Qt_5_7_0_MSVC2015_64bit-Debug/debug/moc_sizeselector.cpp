/****************************************************************************
** Meta object code from reading C++ file 'sizeselector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../testPixel/sizeselector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sizeselector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SizeSelector_t {
    QByteArrayData data[11];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SizeSelector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SizeSelector_t qt_meta_stringdata_SizeSelector = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SizeSelector"
QT_MOC_LITERAL(1, 13, 17), // "setWidthAndHeight"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 28), // "on_widthSpinBox_valueChanged"
QT_MOC_LITERAL(4, 61, 4), // "arg1"
QT_MOC_LITERAL(5, 66, 26), // "on_widthSlider_sliderMoved"
QT_MOC_LITERAL(6, 93, 8), // "position"
QT_MOC_LITERAL(7, 102, 29), // "on_heightSpinBox_valueChanged"
QT_MOC_LITERAL(8, 132, 27), // "on_heightSlider_sliderMoved"
QT_MOC_LITERAL(9, 160, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(10, 182, 21) // "on_buttonBox_rejected"

    },
    "SizeSelector\0setWidthAndHeight\0\0"
    "on_widthSpinBox_valueChanged\0arg1\0"
    "on_widthSlider_sliderMoved\0position\0"
    "on_heightSpinBox_valueChanged\0"
    "on_heightSlider_sliderMoved\0"
    "on_buttonBox_accepted\0on_buttonBox_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SizeSelector[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   54,    2, 0x08 /* Private */,
       5,    1,   57,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x08 /* Private */,
       8,    1,   63,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SizeSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SizeSelector *_t = static_cast<SizeSelector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setWidthAndHeight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_widthSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_widthSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_heightSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_heightSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_buttonBox_accepted(); break;
        case 6: _t->on_buttonBox_rejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SizeSelector::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SizeSelector::setWidthAndHeight)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SizeSelector::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SizeSelector.data,
      qt_meta_data_SizeSelector,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SizeSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SizeSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SizeSelector.stringdata0))
        return static_cast<void*>(const_cast< SizeSelector*>(this));
    return QDialog::qt_metacast(_clname);
}

int SizeSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void SizeSelector::setWidthAndHeight(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
