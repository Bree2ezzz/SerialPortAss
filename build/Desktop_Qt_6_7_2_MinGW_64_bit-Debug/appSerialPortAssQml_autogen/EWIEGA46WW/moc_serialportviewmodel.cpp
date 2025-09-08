/****************************************************************************
** Meta object code from reading C++ file 'serialportviewmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../serialportviewmodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialportviewmodel.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSerialPortViewModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSerialPortViewModelENDCLASS = QtMocHelpers::stringData(
    "SerialPortViewModel",
    "autoSendEnabledChanged",
    "",
    "autoSendIntervalChanged",
    "connectionStatusChanged",
    "isOpen",
    "portName",
    "sentBytesCountChanged",
    "receivedBytesCountChanged",
    "onDataReceived",
    "data",
    "onErrorOccurred",
    "errorString",
    "onPortOpened",
    "onPortClosed",
    "onAutoSendTimeout",
    "onFileSenderLog",
    "message",
    "connectPort",
    "disconnectPort",
    "clearByteCounts",
    "sendData",
    "text",
    "setAutoSend",
    "enabled",
    "interval",
    "settingsManager",
    "PortSettingsManager*",
    "logManager",
    "LogManager*",
    "dataProcessor",
    "DataProcessor*",
    "fileSender",
    "FileSender*",
    "isConnected",
    "sentBytesCount",
    "receivedBytesCount",
    "autoSendEnabled",
    "autoSendInterval"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSerialPortViewModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       9,  146, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x06,   10 /* Public */,
       3,    0,  111,    2, 0x06,   11 /* Public */,
       4,    2,  112,    2, 0x06,   12 /* Public */,
       7,    0,  117,    2, 0x06,   15 /* Public */,
       8,    0,  118,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,  119,    2, 0x0a,   17 /* Public */,
      11,    1,  122,    2, 0x0a,   19 /* Public */,
      13,    0,  125,    2, 0x0a,   21 /* Public */,
      14,    0,  126,    2, 0x0a,   22 /* Public */,
      15,    0,  127,    2, 0x08,   23 /* Private */,
      16,    1,  128,    2, 0x08,   24 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      18,    1,  131,    2, 0x02,   26 /* Public */,
      19,    0,  134,    2, 0x02,   28 /* Public */,
      20,    0,  135,    2, 0x02,   29 /* Public */,
      21,    1,  136,    2, 0x02,   30 /* Public */,
      23,    3,  139,    2, 0x02,   32 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    5,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::QString,   24,   25,   10,

 // properties: name, type, flags
      26, 0x80000000 | 27, 0x00015409, uint(-1), 0,
      28, 0x80000000 | 29, 0x00015409, uint(-1), 0,
      30, 0x80000000 | 31, 0x00015409, uint(-1), 0,
      32, 0x80000000 | 33, 0x00015409, uint(-1), 0,
      34, QMetaType::Bool, 0x00015001, uint(2), 0,
      35, QMetaType::LongLong, 0x00015001, uint(3), 0,
      36, QMetaType::LongLong, 0x00015001, uint(4), 0,
      37, QMetaType::Bool, 0x00015001, uint(0), 0,
      38, QMetaType::Int, 0x00015001, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SerialPortViewModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSSerialPortViewModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSerialPortViewModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSerialPortViewModelENDCLASS_t,
        // property 'settingsManager'
        QtPrivate::TypeAndForceComplete<PortSettingsManager*, std::true_type>,
        // property 'logManager'
        QtPrivate::TypeAndForceComplete<LogManager*, std::true_type>,
        // property 'dataProcessor'
        QtPrivate::TypeAndForceComplete<DataProcessor*, std::true_type>,
        // property 'fileSender'
        QtPrivate::TypeAndForceComplete<FileSender*, std::true_type>,
        // property 'isConnected'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'sentBytesCount'
        QtPrivate::TypeAndForceComplete<qint64, std::true_type>,
        // property 'receivedBytesCount'
        QtPrivate::TypeAndForceComplete<qint64, std::true_type>,
        // property 'autoSendEnabled'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'autoSendInterval'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SerialPortViewModel, std::true_type>,
        // method 'autoSendEnabledChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'autoSendIntervalChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'connectionStatusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sentBytesCountChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receivedBytesCountChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'onErrorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onPortOpened'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPortClosed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAutoSendTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onFileSenderLog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'connectPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'disconnectPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearByteCounts'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'setAutoSend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void SerialPortViewModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialPortViewModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->autoSendEnabledChanged(); break;
        case 1: _t->autoSendIntervalChanged(); break;
        case 2: _t->connectionStatusChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->sentBytesCountChanged(); break;
        case 4: _t->receivedBytesCountChanged(); break;
        case 5: _t->onDataReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 6: _t->onErrorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->onPortOpened(); break;
        case 8: _t->onPortClosed(); break;
        case 9: _t->onAutoSendTimeout(); break;
        case 10: _t->onFileSenderLog((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->connectPort((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->disconnectPort(); break;
        case 13: _t->clearByteCounts(); break;
        case 14: _t->sendData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->setAutoSend((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialPortViewModel::*)();
            if (_t _q_method = &SerialPortViewModel::autoSendEnabledChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialPortViewModel::*)();
            if (_t _q_method = &SerialPortViewModel::autoSendIntervalChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SerialPortViewModel::*)(bool , const QString & );
            if (_t _q_method = &SerialPortViewModel::connectionStatusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SerialPortViewModel::*)();
            if (_t _q_method = &SerialPortViewModel::sentBytesCountChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SerialPortViewModel::*)();
            if (_t _q_method = &SerialPortViewModel::receivedBytesCountChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< DataProcessor* >(); break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< FileSender* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< LogManager* >(); break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PortSettingsManager* >(); break;
        }
    }  else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SerialPortViewModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< PortSettingsManager**>(_v) = _t->settingsManager(); break;
        case 1: *reinterpret_cast< LogManager**>(_v) = _t->logManager(); break;
        case 2: *reinterpret_cast< DataProcessor**>(_v) = _t->dataProcessor(); break;
        case 3: *reinterpret_cast< FileSender**>(_v) = _t->fileSender(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->isConnected(); break;
        case 5: *reinterpret_cast< qint64*>(_v) = _t->sentBytesCount(); break;
        case 6: *reinterpret_cast< qint64*>(_v) = _t->receivedBytesCount(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->autoSendEnabled(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->autoSendInterval(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *SerialPortViewModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPortViewModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSerialPortViewModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialPortViewModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SerialPortViewModel::autoSendEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SerialPortViewModel::autoSendIntervalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void SerialPortViewModel::connectionStatusChanged(bool _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SerialPortViewModel::sentBytesCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void SerialPortViewModel::receivedBytesCountChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
