/****************************************************************************
** Meta object code from reading C++ file 'affineplugin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../AffinePlugin/affineplugin.h"
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'affineplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
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
struct qt_meta_stringdata_CLASSAffinePluginENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAffinePluginENDCLASS = QtMocHelpers::stringData(
    "AffinePlugin"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAffinePluginENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAffinePluginENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAffinePluginENDCLASS_t qt_meta_stringdata_CLASSAffinePluginENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12)   // "AffinePlugin"
    },
    "AffinePlugin"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAffinePluginENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject AffinePlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSAffinePluginENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAffinePluginENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAffinePluginENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AffinePlugin, std::true_type>
    >,
    nullptr
} };

void AffinePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *AffinePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AffinePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAffinePluginENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "EditorPluginInterface"))
        return static_cast< EditorPluginInterface*>(this);
    if (!strcmp(_clname, "com.kdr2.editorplugininterface"))
        return static_cast< EditorPluginInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int AffinePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_AffinePlugin[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1e,  'c',  'o',  'm',  '.',  'k', 
    'd',  'r',  '2',  '.',  'e',  'd',  'i',  't', 
    'o',  'r',  'p',  'l',  'u',  'g',  'i',  'n', 
    'i',  'n',  't',  'e',  'r',  'f',  'a',  'c', 
    'e', 
    // "className"
    0x03,  0x6c,  'A',  'f',  'f',  'i',  'n',  'e', 
    'P',  'l',  'u',  'g',  'i',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(AffinePlugin, AffinePlugin, qt_pluginMetaDataV2_AffinePlugin)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_AffinePlugin[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1e,  'c',  'o',  'm',  '.',  'k', 
    'd',  'r',  '2',  '.',  'e',  'd',  'i',  't', 
    'o',  'r',  'p',  'l',  'u',  'g',  'i',  'n', 
    'i',  'n',  't',  'e',  'r',  'f',  'a',  'c', 
    'e', 
    // "className"
    0x03,  0x6c,  'A',  'f',  'f',  'i',  'n',  'e', 
    'P',  'l',  'u',  'g',  'i',  'n', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(AffinePlugin, AffinePlugin)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP
