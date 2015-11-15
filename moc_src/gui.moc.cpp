/****************************************************************************
** Meta object code from reading C++ file 'gui.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gui/gui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_color_range[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   13,   12,   12, 0x08,
      32,   13,   12,   12, 0x08,
      47,   13,   12,   12, 0x08,
      62,   13,   12,   12, 0x08,
      77,   13,   12,   12, 0x08,
      92,   13,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_color_range[] = {
    "color_range\0\0val\0set_h_min(int)\0"
    "set_h_max(int)\0set_s_min(int)\0"
    "set_s_max(int)\0set_v_min(int)\0"
    "set_v_max(int)\0"
};

void color_range::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        color_range *_t = static_cast<color_range *>(_o);
        switch (_id) {
        case 0: _t->set_h_min((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->set_h_max((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->set_s_min((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->set_s_max((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->set_v_min((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->set_v_max((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData color_range::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject color_range::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_color_range,
      qt_meta_data_color_range, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &color_range::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *color_range::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *color_range::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_color_range))
        return static_cast<void*>(const_cast< color_range*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int color_range::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
static const uint qt_meta_data_camera_settings[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   17,   16,   16, 0x08,
      53,   17,   16,   16, 0x08,
      83,   17,   16,   16, 0x08,
     115,   17,   16,   16, 0x08,
     140,   17,   16,   16, 0x08,
     166,   17,   16,   16, 0x08,
     196,   17,   16,   16, 0x08,
     228,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_camera_settings[] = {
    "camera_settings\0\0val\0"
    "set_brightness_hardware(double)\0"
    "set_contrast_hardware(double)\0"
    "set_saturation_hardware(double)\0"
    "set_hue_hardware(double)\0"
    "set_gain_hardware(double)\0"
    "set_exposure_hardware(double)\0"
    "set_brightness_software(double)\0"
    "set_contrast_software(double)\0"
};

void camera_settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        camera_settings *_t = static_cast<camera_settings *>(_o);
        switch (_id) {
        case 0: _t->set_brightness_hardware((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->set_contrast_hardware((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->set_saturation_hardware((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->set_hue_hardware((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->set_gain_hardware((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->set_exposure_hardware((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->set_brightness_software((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->set_contrast_software((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData camera_settings::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject camera_settings::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_camera_settings,
      qt_meta_data_camera_settings, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &camera_settings::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *camera_settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *camera_settings::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_camera_settings))
        return static_cast<void*>(const_cast< camera_settings*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int camera_settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
static const uint qt_meta_data_gui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,    5,    4,    4, 0x0a,
      26,    4,    4,    4, 0x0a,
      49,    4,    4,    4, 0x0a,
      76,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_gui[] = {
    "gui\0\0image\0redraw(QImage)\0"
    "call_color_range_win()\0"
    "call_camera_settings_win()\0"
    "call_camera_settings_save_win()\0"
};

void gui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        gui *_t = static_cast<gui *>(_o);
        switch (_id) {
        case 0: _t->redraw((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->call_color_range_win(); break;
        case 2: _t->call_camera_settings_win(); break;
        case 3: _t->call_camera_settings_save_win(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData gui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject gui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_gui,
      qt_meta_data_gui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gui))
        return static_cast<void*>(const_cast< gui*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int gui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
