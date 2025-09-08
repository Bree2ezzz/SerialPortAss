/****************************************************************************
** Meta object code from reading C++ file 'portsettingsmanager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../portsettingsmanager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'portsettingsmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPortSettingsManagerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPortSettingsManagerENDCLASS = QtMocHelpers::stringData(
    "PortSettingsManager",
    "currentBaudRateChanged",
    "",
    "currentDataBitsChanged",
    "currentStopBitsChanged",
    "currentParityChanged",
    "availablePortsChanged",
    "currentDuplexOptionChanged",
    "refreshPortList",
    "baudRatesModel",
    "dataBitsModel",
    "stopBitsModel",
    "parityModel",
    "availablePorts",
    "duplexOptions",
    "currentBaudRate",
    "currentDataBits",
    "currentStopBits",
    "currentParity",
    "currentDuplexOption"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPortSettingsManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
      11,   63, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,   12 /* Public */,
       3,    0,   57,    2, 0x06,   13 /* Public */,
       4,    0,   58,    2, 0x06,   14 /* Public */,
       5,    0,   59,    2, 0x06,   15 /* Public */,
       6,    0,   60,    2, 0x06,   16 /* Public */,
       7,    0,   61,    2, 0x06,   17 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   62,    2, 0x02,   18 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::QStringList, 0x00015401, uint(-1), 0,
      10, QMetaType::QStringList, 0x00015401, uint(-1), 0,
      11, QMetaType::QStringList, 0x00015401, uint(-1), 0,
      12, QMetaType::QStringList, 0x00015401, uint(-1), 0,
      13, QMetaType::QStringList, 0x00015001, uint(4), 0,
      14, QMetaType::QStringList, 0x00015401, uint(-1), 0,
      15, QMetaType::QString, 0x00015103, uint(0), 0,
      16, QMetaType::QString, 0x00015103, uint(1), 0,
      17, QMetaType::QString, 0x00015103, uint(2), 0,
      18, QMetaType::QString, 0x00015103, uint(3), 0,
      19, QMetaType::QString, 0x00015903, uint(5), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject PortSettingsManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPortSettingsManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPortSettingsManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPortSettingsManagerENDCLASS_t,
        // property 'baudRatesModel'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'dataBitsModel'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'stopBitsModel'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'parityModel'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'availablePorts'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'duplexOptions'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'currentBaudRate'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'currentDataBits'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'currentStopBits'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'currentParity'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'currentDuplexOption'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PortSettingsManager, std::true_type>,
        // method 'currentBaudRateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentDataBitsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentStopBitsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentParityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'availablePortsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'currentDuplexOptionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'refreshPortList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PortSettingsManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PortSettingsManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currentBaudRateChanged(); break;
        case 1: _t->currentDataBitsChanged(); break;
        case 2: _t->currentStopBitsChanged(); break;
        case 3: _t->currentParityChanged(); break;
        case 4: _t->availablePortsChanged(); break;
        case 5: _t->currentDuplexOptionChanged(); break;
        case 6: _t->refreshPortList(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PortSettingsManager::*)();
            if (_t _q_method = &PortSettingsManager::currentBaudRateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PortSettingsManager::*)();
            if (_t _q_method = &PortSettingsManager::currentDataBitsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PortSettingsManager::*)();
            if (_t _q_method = &PortSettingsManager::currentStopBitsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PortSettingsManager::*)();
            if (_t _q_method = &PortSettingsManager::currentParityChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PortSettingsManager::*)();
            if (_t _q_method = &PortSettingsManager::availablePortsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (PortSettingsManager::*)();
            if (_t _q_method = &PortSettingsManager::currentDuplexOptionChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<PortSettingsManager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->baudRatesModel(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->dataBitsModel(); break;
        case 2: *reinterpret_cast< QStringList*>(_v) = _t->stopBitsModel(); break;
        case 3: *reinterpret_cast< QStringList*>(_v) = _t->parityModel(); break;
        case 4: *reinterpret_cast< QStringList*>(_v) = _t->availablePorts(); break;
        case 5: *reinterpret_cast< QStringList*>(_v) = _t->duplexOptions(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->currentBaudRate(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->currentDataBits(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->currentStopBits(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->currentParity(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->currentDuplexOption(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<PortSettingsManager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 6: _t->setCurrentBaudRate(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setCurrentDataBits(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setCurrentStopBits(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->setCurrentParity(*reinterpret_cast< QString*>(_v)); break;
        case 10: _t->setCurrentDuplexOption(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *PortSettingsManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PortSettingsManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPortSettingsManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PortSettingsManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void PortSettingsManager::currentBaudRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PortSettingsManager::currentDataBitsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PortSettingsManager::currentStopBitsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PortSettingsManager::currentParityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PortSettingsManager::availablePortsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void PortSettingsManager::currentDuplexOptionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
