/****************************************************************************
** Meta object code from reading C++ file 'drawmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../testPixel/drawmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DrawModel_t {
    QByteArrayData data[7];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawModel_t qt_meta_stringdata_DrawModel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DrawModel"
QT_MOC_LITERAL(1, 10, 23), // "userGivenWidthAndHeight"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "changePenSize"
QT_MOC_LITERAL(4, 49, 14), // "changePenColor"
QT_MOC_LITERAL(5, 64, 11), // "changeTools"
QT_MOC_LITERAL(6, 76, 11) // "std::string"

    },
    "DrawModel\0userGivenWidthAndHeight\0\0"
    "changePenSize\0changePenColor\0changeTools\0"
    "std::string"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x0a /* Public */,
       3,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       5,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void DrawModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DrawModel *_t = static_cast<DrawModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->userGivenWidthAndHeight((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->changePenSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changePenColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->changeTools((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DrawModel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DrawModel.data,
      qt_meta_data_DrawModel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DrawModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawModel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DrawModel.stringdata0))
        return static_cast<void*>(const_cast< DrawModel*>(this));
    return QWidget::qt_metacast(_clname);
}

int DrawModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
