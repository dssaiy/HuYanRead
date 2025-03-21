/****************************************************************************
** Meta object code from reading C++ file 'TextReaderView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/TextReaderView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TextReaderView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextReaderView_t {
    QByteArrayData data[14];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextReaderView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextReaderView_t qt_meta_stringdata_TextReaderView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TextReaderView"
QT_MOC_LITERAL(1, 15, 13), // "pageRequested"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "page"
QT_MOC_LITERAL(4, 35, 17), // "nextPageRequested"
QT_MOC_LITERAL(5, 53, 21), // "previousPageRequested"
QT_MOC_LITERAL(6, 75, 14), // "mouseClickedAt"
QT_MOC_LITERAL(7, 90, 3), // "pos"
QT_MOC_LITERAL(8, 94, 20), // "contextMenuRequested"
QT_MOC_LITERAL(9, 115, 17), // "setShowPageNumber"
QT_MOC_LITERAL(10, 133, 4), // "show"
QT_MOC_LITERAL(11, 138, 15), // "setShowProgress"
QT_MOC_LITERAL(12, 154, 13), // "setTotalPages"
QT_MOC_LITERAL(13, 168, 10) // "totalPages"

    },
    "TextReaderView\0pageRequested\0\0page\0"
    "nextPageRequested\0previousPageRequested\0"
    "mouseClickedAt\0pos\0contextMenuRequested\0"
    "setShowPageNumber\0show\0setShowProgress\0"
    "setTotalPages\0totalPages"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextReaderView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,
       6,    1,   59,    2, 0x06 /* Public */,
       8,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   65,    2, 0x0a /* Public */,
      11,    1,   68,    2, 0x0a /* Public */,
      12,    1,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    7,
    QMetaType::Void, QMetaType::QPoint,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void TextReaderView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TextReaderView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pageRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->nextPageRequested(); break;
        case 2: _t->previousPageRequested(); break;
        case 3: _t->mouseClickedAt((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: _t->contextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 5: _t->setShowPageNumber((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->setShowProgress((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setTotalPages((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TextReaderView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TextReaderView::pageRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TextReaderView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TextReaderView::nextPageRequested)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TextReaderView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TextReaderView::previousPageRequested)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TextReaderView::*)(const QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TextReaderView::mouseClickedAt)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TextReaderView::*)(const QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TextReaderView::contextMenuRequested)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TextReaderView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TextReaderView.data,
    qt_meta_data_TextReaderView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TextReaderView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextReaderView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TextReaderView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TextReaderView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void TextReaderView::pageRequested(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TextReaderView::nextPageRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TextReaderView::previousPageRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TextReaderView::mouseClickedAt(const QPoint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TextReaderView::contextMenuRequested(const QPoint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
