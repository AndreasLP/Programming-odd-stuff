
#include "nuitka/prelude.h"
#include "structseq.h"

// Sentinel PyObject to be used for all our call iterator endings. It will
// become a PyCObject pointing to NULL. It's address is unique, and that's
// enough for us to use it as sentinel value.
PyObject *_sentinel_value = NULL;

PyObject *Nuitka_dunder_compiled_value = NULL;

PyObject *const_int_0;
PyObject *const_str_dot;
PyObject *const_float_0_0;
PyObject *const_float_1_0;
PyObject *const_int_neg_1;
PyObject *const_int_pos_1;
PyObject *const_int_pos_2;
PyObject *const_int_pos_3;
PyObject *const_int_pos_4;
PyObject *const_int_pos_5;
PyObject *const_int_pos_6;
PyObject *const_int_pos_7;
PyObject *const_str_empty;
PyObject *const_dict_empty;
PyObject *const_str_plain_b;
PyObject *const_str_plain_f;
PyObject *const_str_plain_i;
PyObject *const_tuple_empty;
PyObject *const_str_plain_rb;
PyObject *const_str_plain_HIG;
PyObject *const_str_plain_MED;
PyObject *const_str_plain_cnt;
PyObject *const_str_plain_dec;
PyObject *const_str_plain_int;
PyObject *const_str_plain_len;
PyObject *const_str_plain_sum;
PyObject *const_str_plain_sys;
PyObject *const_str_plain_argv;
PyObject *const_str_plain_iter;
PyObject *const_str_plain_join;
PyObject *const_str_plain_long;
PyObject *const_str_plain_name;
PyObject *const_str_plain_open;
PyObject *const_str_plain_read;
PyObject *const_str_plain_repr;
PyObject *const_str_plain_site;
PyObject *const_str_plain_type;
PyObject *const_float_minus_0_0;
PyObject *const_float_minus_1_0;
PyObject *const_str_plain_False;
PyObject *const_str_plain_MAGIC;
PyObject *const_str_plain_close;
PyObject *const_str_plain_crypt;
PyObject *const_str_plain_level;
PyObject *const_str_plain_range;
PyObject *const_str_plain_cipher;
PyObject *const_str_plain_format;
PyObject *const_str_plain_locals;
PyObject *const_str_plain_xrange;
PyObject *const_str_plain___all__;
PyObject *const_str_plain___cmp__;
PyObject *const_str_plain___doc__;
PyObject *const_str_plain_compile;
PyObject *const_str_plain_decrypt;
PyObject *const_str_plain_globals;
PyObject *const_str_plain_inspect;
PyObject *const_str_plain___dict__;
PyObject *const_str_plain___exit__;
PyObject *const_str_plain___file__;
PyObject *const_str_plain___iter__;
PyObject *const_str_plain___main__;
PyObject *const_str_plain___name__;
PyObject *const_str_plain___path__;
PyObject *const_str_plain_exc_type;
PyObject *const_str_plain_fromlist;
PyObject *const_str_plain_pswchars;
PyObject *const_str_plain___class__;
PyObject *const_str_plain___enter__;
PyObject *const_str_plain_bytearray;
PyObject *const_str_plain_exc_value;
PyObject *const_str_plain___import__;
PyObject *const_str_plain___module__;
PyObject *const_str_plain___delattr__;
PyObject *const_str_plain___getattr__;
PyObject *const_str_plain___package__;
PyObject *const_str_plain___setattr__;
PyObject *const_str_plain_classmethod;
PyObject *const_str_plain___builtins__;
PyObject *const_str_plain___compiled__;
PyObject *const_str_plain_staticmethod;
PyObject *const_str_plain___metaclass__;
PyObject *const_str_plain_exc_traceback;
PyObject *const_str_digest_7362b9a47180204a87d7e3a16823d69f;
PyObject *const_str_digest_79d8281ef2016b308b651aab8eb67219;
PyObject *const_str_digest_f570069e0d46f80dd06443468800a290;

static void _createGlobalConstants(void) {
    NUITKA_MAY_BE_UNUSED PyObject *exception_type, *exception_value;
    NUITKA_MAY_BE_UNUSED PyTracebackObject *exception_tb;

#ifdef _MSC_VER
    // Prevent unused warnings in case of simple programs, the attribute
    // NUITKA_MAY_BE_UNUSED doesn't work for MSVC.
    (void *)exception_type; (void *)exception_value; (void *)exception_tb;
#endif

    const_int_0 = PyInt_FromLong(0l);
    const_str_dot = UNSTREAM_CHAR(46, 0);
    const_float_0_0 = UNSTREAM_FLOAT(&constant_bin[ 1768 ]);
    const_float_1_0 = UNSTREAM_FLOAT(&constant_bin[ 1776 ]);
    const_int_neg_1 = PyInt_FromLong(-1l);
    const_int_pos_1 = PyInt_FromLong(1l);
    const_int_pos_2 = PyInt_FromLong(2l);
    const_int_pos_3 = PyInt_FromLong(3l);
    const_int_pos_4 = PyInt_FromLong(4l);
    const_int_pos_5 = PyInt_FromLong(5l);
    const_int_pos_6 = PyInt_FromLong(6l);
    const_int_pos_7 = PyInt_FromLong(7l);
    const_str_empty = UNSTREAM_STRING(&constant_bin[ 0 ], 0, 0);
    const_dict_empty = _PyDict_NewPresized( 0 );
    assert(PyDict_Size(const_dict_empty) == 0);
    const_str_plain_b = UNSTREAM_CHAR(98, 1);
    const_str_plain_f = UNSTREAM_CHAR(102, 1);
    const_str_plain_i = UNSTREAM_CHAR(105, 1);
    const_tuple_empty = PyTuple_New(0);
    const_str_plain_rb = UNSTREAM_STRING(&constant_bin[ 1784 ], 2, 1);
    const_str_plain_HIG = UNSTREAM_STRING(&constant_bin[ 1064 ], 3, 1);
    const_str_plain_MED = UNSTREAM_STRING(&constant_bin[ 1182 ], 3, 1);
    const_str_plain_cnt = UNSTREAM_STRING(&constant_bin[ 132 ], 3, 1);
    const_str_plain_dec = UNSTREAM_STRING(&constant_bin[ 361 ], 3, 1);
    const_str_plain_int = UNSTREAM_STRING(&constant_bin[ 865 ], 3, 1);
    const_str_plain_len = UNSTREAM_STRING(&constant_bin[ 6 ], 3, 1);
    const_str_plain_sum = UNSTREAM_STRING(&constant_bin[ 1786 ], 3, 1);
    const_str_plain_sys = UNSTREAM_STRING(&constant_bin[ 31 ], 3, 1);
    const_str_plain_argv = UNSTREAM_STRING(&constant_bin[ 1789 ], 4, 1);
    const_str_plain_iter = UNSTREAM_STRING(&constant_bin[ 1055 ], 4, 1);
    const_str_plain_join = UNSTREAM_STRING(&constant_bin[ 1793 ], 4, 1);
    const_str_plain_long = UNSTREAM_STRING(&constant_bin[ 1797 ], 4, 1);
    const_str_plain_name = UNSTREAM_STRING(&constant_bin[ 0 ], 4, 1);
    const_str_plain_open = UNSTREAM_STRING(&constant_bin[ 83 ], 4, 1);
    const_str_plain_read = UNSTREAM_STRING(&constant_bin[ 1801 ], 4, 1);
    const_str_plain_repr = UNSTREAM_STRING(&constant_bin[ 1805 ], 4, 1);
    const_str_plain_site = UNSTREAM_STRING(&constant_bin[ 1054 ], 4, 1);
    const_str_plain_type = UNSTREAM_STRING(&constant_bin[ 1809 ], 4, 1);
    const_float_minus_0_0 = UNSTREAM_FLOAT(&constant_bin[ 1813 ]);
    const_float_minus_1_0 = UNSTREAM_FLOAT(&constant_bin[ 1821 ]);
    const_str_plain_False = UNSTREAM_STRING(&constant_bin[ 249 ], 5, 1);
    const_str_plain_MAGIC = UNSTREAM_STRING(&constant_bin[ 451 ], 5, 1);
    const_str_plain_close = UNSTREAM_STRING(&constant_bin[ 1829 ], 5, 1);
    const_str_plain_crypt = UNSTREAM_STRING(&constant_bin[ 363 ], 5, 1);
    const_str_plain_level = UNSTREAM_STRING(&constant_bin[ 1834 ], 5, 1);
    const_str_plain_range = UNSTREAM_STRING(&constant_bin[ 222 ], 5, 1);
    const_str_plain_cipher = UNSTREAM_STRING(&constant_bin[ 1232 ], 6, 1);
    const_str_plain_format = UNSTREAM_STRING(&constant_bin[ 1839 ], 6, 1);
    const_str_plain_locals = UNSTREAM_STRING(&constant_bin[ 1845 ], 6, 1);
    const_str_plain_xrange = UNSTREAM_STRING(&constant_bin[ 1851 ], 6, 1);
    const_str_plain___all__ = UNSTREAM_STRING(&constant_bin[ 1857 ], 7, 1);
    const_str_plain___cmp__ = UNSTREAM_STRING(&constant_bin[ 1864 ], 7, 1);
    const_str_plain___doc__ = UNSTREAM_STRING(&constant_bin[ 1871 ], 7, 1);
    const_str_plain_compile = UNSTREAM_STRING(&constant_bin[ 1878 ], 7, 1);
    const_str_plain_decrypt = UNSTREAM_STRING(&constant_bin[ 361 ], 7, 1);
    const_str_plain_globals = UNSTREAM_STRING(&constant_bin[ 1885 ], 7, 1);
    const_str_plain_inspect = UNSTREAM_STRING(&constant_bin[ 1892 ], 7, 1);
    const_str_plain___dict__ = UNSTREAM_STRING(&constant_bin[ 1899 ], 8, 1);
    const_str_plain___exit__ = UNSTREAM_STRING(&constant_bin[ 1907 ], 8, 1);
    const_str_plain___file__ = UNSTREAM_STRING(&constant_bin[ 1915 ], 8, 1);
    const_str_plain___iter__ = UNSTREAM_STRING(&constant_bin[ 1923 ], 8, 1);
    const_str_plain___main__ = UNSTREAM_STRING(&constant_bin[ 1931 ], 8, 1);
    const_str_plain___name__ = UNSTREAM_STRING(&constant_bin[ 1939 ], 8, 1);
    const_str_plain___path__ = UNSTREAM_STRING(&constant_bin[ 1947 ], 8, 1);
    const_str_plain_exc_type = UNSTREAM_STRING(&constant_bin[ 1955 ], 8, 1);
    const_str_plain_fromlist = UNSTREAM_STRING(&constant_bin[ 1963 ], 8, 1);
    const_str_plain_pswchars = UNSTREAM_STRING(&constant_bin[ 624 ], 8, 1);
    const_str_plain___class__ = UNSTREAM_STRING(&constant_bin[ 1971 ], 9, 1);
    const_str_plain___enter__ = UNSTREAM_STRING(&constant_bin[ 1980 ], 9, 1);
    const_str_plain_bytearray = UNSTREAM_STRING(&constant_bin[ 191 ], 9, 1);
    const_str_plain_exc_value = UNSTREAM_STRING(&constant_bin[ 1989 ], 9, 1);
    const_str_plain___import__ = UNSTREAM_STRING(&constant_bin[ 1998 ], 10, 1);
    const_str_plain___module__ = UNSTREAM_STRING(&constant_bin[ 2008 ], 10, 1);
    const_str_plain___delattr__ = UNSTREAM_STRING(&constant_bin[ 2018 ], 11, 1);
    const_str_plain___getattr__ = UNSTREAM_STRING(&constant_bin[ 2029 ], 11, 1);
    const_str_plain___package__ = UNSTREAM_STRING(&constant_bin[ 2040 ], 11, 1);
    const_str_plain___setattr__ = UNSTREAM_STRING(&constant_bin[ 2051 ], 11, 1);
    const_str_plain_classmethod = UNSTREAM_STRING(&constant_bin[ 2062 ], 11, 1);
    const_str_plain___builtins__ = UNSTREAM_STRING(&constant_bin[ 2073 ], 12, 1);
    const_str_plain___compiled__ = UNSTREAM_STRING(&constant_bin[ 2085 ], 12, 1);
    const_str_plain_staticmethod = UNSTREAM_STRING(&constant_bin[ 2097 ], 12, 1);
    const_str_plain___metaclass__ = UNSTREAM_STRING(&constant_bin[ 1006 ], 13, 1);
    const_str_plain_exc_traceback = UNSTREAM_STRING(&constant_bin[ 2109 ], 13, 1);
    const_str_digest_7362b9a47180204a87d7e3a16823d69f = UNSTREAM_STRING(&constant_bin[ 1676 ], 62, 0);
    const_str_digest_79d8281ef2016b308b651aab8eb67219 = UNSTREAM_STRING(&constant_bin[ 2122 ], 16, 0);
    const_str_digest_f570069e0d46f80dd06443468800a290 = UNSTREAM_STRING(&constant_bin[ 2122 ], 4, 0);

#if _NUITKA_EXE
    /* Set the "sys.executable" path to the original CPython executable. */
    PySys_SetObject(
        (char *)"executable",
        const_str_digest_79d8281ef2016b308b651aab8eb67219
    );

#ifndef _NUITKA_STANDALONE
    /* Set the "sys.prefix" path to the original one. */
    PySys_SetObject(
        (char *)"prefix",
        const_str_digest_f570069e0d46f80dd06443468800a290
    );

    /* Set the "sys.prefix" path to the original one. */
    PySys_SetObject(
        (char *)"exec_prefix",
        const_str_digest_f570069e0d46f80dd06443468800a290
    );


#if PYTHON_VERSION >= 300
    /* Set the "sys.base_prefix" path to the original one. */
    PySys_SetObject(
        (char *)"base_prefix",
        None
    );

    /* Set the "sys.exec_base_prefix" path to the original one. */
    PySys_SetObject(
        (char *)"base_exec_prefix",
        None
    );

#endif
#endif
#endif

    static PyTypeObject Nuitka_VersionInfoType;

    // Same fields as "sys.version_info" except no serial number.
    static PyStructSequence_Field Nuitka_VersionInfoFields[] = {
        {(char *)"major", (char *)"Major release number"},
        {(char *)"minor", (char *)"Minor release number"},
        {(char *)"micro", (char *)"Micro release number"},
        {(char *)"releaselevel", (char *)"'alpha', 'beta', 'candidate', or 'release'"},
        {0}
    };

    static PyStructSequence_Desc Nuitka_VersionInfoDesc = {
        (char *)"__nuitka_version__",                                    /* name */
        (char *)"__compiled__\n\nVersion information as a named tuple.", /* doc */
        Nuitka_VersionInfoFields,                                        /* fields */
        4
    };

    PyStructSequence_InitType(&Nuitka_VersionInfoType, &Nuitka_VersionInfoDesc);

    Nuitka_dunder_compiled_value = PyStructSequence_New(&Nuitka_VersionInfoType);
    assert(Nuitka_dunder_compiled_value != NULL);

    PyStructSequence_SET_ITEM(Nuitka_dunder_compiled_value, 0, PyInt_FromLong(0));
    PyStructSequence_SET_ITEM(Nuitka_dunder_compiled_value, 1, PyInt_FromLong(6));
    PyStructSequence_SET_ITEM(Nuitka_dunder_compiled_value, 2, PyInt_FromLong(7));

#if PYTHON_VERSION < 300
    PyStructSequence_SET_ITEM(Nuitka_dunder_compiled_value, 3, PyString_FromString("release"));
#else
    PyStructSequence_SET_ITEM(Nuitka_dunder_compiled_value, 3, PyUnicode_FromString("release"));
#endif
    // Prevent users from creating the Nuitka version type object.
    Nuitka_VersionInfoType.tp_init = NULL;
    Nuitka_VersionInfoType.tp_new = NULL;


}

// In debug mode we can check that the constants were not tampered with in any
// given moment. We typically do it at program exit, but we can add extra calls
// for sanity.
#ifndef __NUITKA_NO_ASSERT__
void checkGlobalConstants(void) {

}
#endif

void createGlobalConstants(void) {
    if (_sentinel_value == NULL) {
#if PYTHON_VERSION < 300
        _sentinel_value = PyCObject_FromVoidPtr(NULL, NULL);
#else
        // The NULL value is not allowed for a capsule, so use something else.
        _sentinel_value = PyCapsule_New((void *)27, "sentinel", NULL);
#endif
        assert(_sentinel_value);

        _createGlobalConstants();
    }
}
