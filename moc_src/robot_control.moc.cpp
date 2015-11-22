/****************************************************************************
** Meta object code from reading C++ file 'robot_control.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../robot_control/robot_control.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robot_control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_robot_control_t[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      31,   16,   16,   16, 0x0a,
      48,   44,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_robot_control_t[] = {
    "robot_control_t\0\0start_robot()\0"
    "stop_robot()\0x,y\0get_robot_pos(double,double)\0"
};

void robot_control_t::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        robot_control_t *_t = static_cast<robot_control_t *>(_o);
        switch (_id) {
        case 0: _t->start_robot(); break;
        case 1: _t->stop_robot(); break;
        case 2: _t->get_robot_pos((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData robot_control_t::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject robot_control_t::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_robot_control_t,
      qt_meta_data_robot_control_t, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &robot_control_t::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *robot_control_t::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *robot_control_t::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_robot_control_t))
        return static_cast<void*>(const_cast< robot_control_t*>(this));
    return QObject::qt_metacast(_clname);
}

int robot_control_t::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
